#ifndef _TAVERNWINDOW_H_
#define _TAVERNWINDOW_H_

#include <QDialog>
#include <QStandardItemModel>
#include <QComboBox>
#include <QLineEdit>
#include <QTableView>
#include "productfilterproxy.h"

class TavernWindow : public QDialog
{
	Q_OBJECT

public:
	QComboBox * comboCategoria;
	QLineEdit * lineBuscar;
	QTableView * tablaProductos;
	TavernWindow(QWidget *parent = nullptr);

private slots:
	void onProductoSeleccionado(const QModelIndex &current);

private:
	void setupProductos();
	bool cargarProductosCSV(const QString &ruta);
	static QStringList parseLineaCSV(const QString &linea);

	QStandardItemModel *m_model = nullptr;
	ProductFilterProxy *m_proxy = nullptr;
};

#endif