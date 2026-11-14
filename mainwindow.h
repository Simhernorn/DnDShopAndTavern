#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QWidget>

#include "tavernWindow.h"
#include "gestionarwindow.h"

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
	QLabel *lblBienvenida;
	QPushButton
		*btnTaberna,
		*btnTienda,
		*btnEditarTaberna,
		*btnEditarTienda,
		*btnCargarParty,
		*btnGuardarParty,
		*btnGestionarParty,
		*btnSalir;
	QHBoxLayout
		*tabernaTiendaLayout,
		*editarLayout,
		*cargarGuardarLayout,
		*gestionarSalirLayout;
	QVBoxLayout
		*principalLayout;
	QWidget
		*centralWidget;
	TavernWindow
		*taberna;
	GestionarWindow
		*gestionar;

	MainWindow(QWidget *parent = nullptr);

public slots:
	void slotAbrirTaberna();
	void slotGestionarParty();
};

#endif // MAINWINDOW_H
