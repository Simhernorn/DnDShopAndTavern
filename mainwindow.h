#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QComboBox>
#include <QLineEdit>
#include <QTableView>
#include "productfilterproxy.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	QComboBox * comboCategoria;
	QLineEdit * lineBuscar;
	QTableView * tablaProductos;
	MainWindow(QWidget *parent = nullptr);

private slots:
	void onProductoSeleccionado(const QModelIndex &current);

private:
	void setupProductos();

	QStandardItemModel *m_model = nullptr;
	ProductFilterProxy *m_proxy = nullptr;
};

#endif
