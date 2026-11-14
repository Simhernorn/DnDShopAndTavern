#include "tavernWindow.h"
#include "productfilterproxy.h"

#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>

TavernWindow::TavernWindow(QWidget *parent)
	: QDialog(parent)
{
	// Widgets
	comboCategoria = new QComboBox(this);
	lineBuscar = new QLineEdit(this);
	tablaProductos = new QTableView(this);

	// Layout (en un QDialog el layout se asigna directamente al diálogo)
	auto *vbox = new QVBoxLayout(this);
	auto *hbox = new QHBoxLayout;
	hbox->addWidget(comboCategoria);
	hbox->addWidget(lineBuscar, 1);
	vbox->addLayout(hbox);
	vbox->addWidget(tablaProductos);

	setupProductos();
}

// Divide una línea CSV en campos (separador ',', admite campos entre comillas dobles)
QStringList TavernWindow::parseLineaCSV(const QString &linea)
{
	QStringList campos;
	QString actual;
	bool entreComillas = false;

	for (int i = 0; i < linea.size(); ++i) {
		const QChar ch = linea.at(i);
		if (entreComillas) {
			if (ch == '"') {
				if (i + 1 < linea.size() && linea.at(i + 1) == '"') {
					actual += '"';   // comilla escapada ""
					++i;
				} else {
					entreComillas = false;
				}
			} else {
				actual += ch;
			}
		} else if (ch == '"') {
			entreComillas = true;
		} else if (ch == ',') {
			campos << actual.trimmed();
			actual.clear();
		} else {
			actual += ch;
		}
	}
	campos << actual.trimmed();
	return campos;
}

// Carga los productos desde un CSV con cabecera: nombre,categoria,precio
bool TavernWindow::cargarProductosCSV(const QString &ruta)
{
	QFile file(ruta);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qWarning() << "No se pudo abrir el CSV:" << ruta << file.errorString();
		return false;
	}

	QTextStream in(&file);
	in.setEncoding(QStringConverter::Utf8);

	bool primera = true;
	int numLinea = 0;
	while (!in.atEnd()) {
		const QString linea = in.readLine();
		++numLinea;

		if (primera) {            // saltar la cabecera
			primera = false;
			continue;
		}
		if (linea.trimmed().isEmpty())
			continue;

		const QStringList campos = parseLineaCSV(linea);
		if (campos.size() < 3) {
			qWarning() << "Línea" << numLinea << "ignorada (faltan campos):" << linea;
			continue;
		}

		bool ok = false;
		const double precio = campos.at(2).toDouble(&ok);
		if (!ok) {
			qWarning() << "Línea" << numLinea << "ignorada (precio no válido):" << linea;
			continue;
		}

		auto *pPrecio = new QStandardItem;
		pPrecio->setData(precio, Qt::DisplayRole);   // número real -> ordena bien
		m_model->appendRow({ new QStandardItem(campos.at(0)),
							new QStandardItem(campos.at(1)),
							pPrecio });
	}
	return true;
}

void TavernWindow::setupProductos(){
	// --- Modelo (productos cargados desde CSV) ---
	m_model = new QStandardItemModel(0, 3, this);
	m_model->setHorizontalHeaderLabels({"Nombre", "Categoría", "Precio"});

	// El CSV se busca junto al ejecutable; cambia la ruta si lo tienes en otro sitio
	const QString rutaCSV = QCoreApplication::applicationDirPath() + "/../taberna.csv";
	cargarProductosCSV(rutaCSV);

	// --- Proxy ---
	m_proxy = new ProductFilterProxy(this);
	m_proxy->setSourceModel(m_model);

	// --- Tabla ---
	auto *t = tablaProductos;
	t->setModel(m_proxy);
	t->setSortingEnabled(true);                        // clic en cabecera para ordenar
	t->setSelectionBehavior(QAbstractItemView::SelectRows);
	t->setSelectionMode(QAbstractItemView::SingleSelection);
	t->setEditTriggers(QAbstractItemView::NoEditTriggers);
	t->setAlternatingRowColors(true);
	t->horizontalHeader()->setStretchLastSection(true);
	t->verticalHeader()->hide();

	// --- Combo de categorías: se rellena con las categorías únicas del modelo ---
	QStringList categorias;
	for (int r = 0; r < m_model->rowCount(); ++r) {
		const QString c = m_model->item(r, 1)->text();
		if (!categorias.contains(c))
			categorias << c;
	}
	categorias.sort();
	comboCategoria->addItem("Todas las categorías", QString());  // userData vacío
	for (const QString &c : std::as_const(categorias))
		comboCategoria->addItem(c, c);

	// --- Buscador ---
	lineBuscar->setPlaceholderText("Buscar producto...");
	lineBuscar->setClearButtonEnabled(true);

	// --- Conexiones ---
	connect(lineBuscar, &QLineEdit::textChanged,
			m_proxy, &ProductFilterProxy::setSearchText);

	connect(comboCategoria, &QComboBox::currentIndexChanged, this, [this](int) {
		m_proxy->setCategory(comboCategoria->currentData().toString());
	});

	connect(t->selectionModel(), &QItemSelectionModel::currentRowChanged,
			this, &TavernWindow::onProductoSeleccionado);
}

void TavernWindow::onProductoSeleccionado(const QModelIndex &current)
{
	if (!current.isValid()) return;

	const QModelIndex src = m_proxy->mapToSource(current);
	const QString nombre = m_model->item(src.row(), 0)->text();
	const double precio  = m_model->item(src.row(), 2)->data(Qt::DisplayRole).toDouble();

	qDebug() << "Seleccionado:" << nombre << precio;
}