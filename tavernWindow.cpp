#include "tavernWindow.h"
#include "productfilterproxy.h"

#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QHBoxLayout>
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

void TavernWindow::setupProductos(){
	// --- Modelo (aquí cargas tus productos; ejemplo con datos de prueba) ---
	m_model = new QStandardItemModel(0, 3, this);
	m_model->setHorizontalHeaderLabels({"Nombre", "Categoría", "Precio"});

	auto addProducto = [this](const QString &nombre, const QString &cat,
							  double precio) {
		auto *pPrecio = new QStandardItem;
		pPrecio->setData(precio, Qt::DisplayRole);   // número real -> ordena bien
		m_model->appendRow({ new QStandardItem(nombre),
							new QStandardItem(cat),
							pPrecio });
	};
	addProducto("Espada corta", "Armas", 29.90);
	addProducto("Ratón inalámbrico",  "Periféricos", 15.50);
	// ... el resto de tus productos

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