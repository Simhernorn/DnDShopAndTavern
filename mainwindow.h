#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QWidget>

#include "tavernWindow.h"
#include "gestionarwindow.h"
#include "createpartywindow.h"

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
	bool partyCargada = false;
	QLabel
		*lblBienvenida,
		*lblCargarParty;
	QPushButton
		*btnTaberna,
		*btnTienda,
		*btnEditarTaberna,
		*btnEditarTienda,
		*btnCargarParty,
		*btnGuardarParty,
		*btnGestionarParty,
		*btnInventario,
		*btnCrearParty,
		*btnSalir;
	QHBoxLayout
		*tabernaTiendaLayout,
		*editarLayout,
		*cargarGuardarLayout,
		*gestionarEInventarioLayout;
	QVBoxLayout
		*principalLayout;
	QWidget
		*centralWidget;
	TavernWindow
		*taberna;
	GestionarWindow
		*gestionar;
	CreatePartyWindow
		*crear;

	MainWindow(QWidget *parent = nullptr);

public slots:
	void slotAbrirTaberna();
	// void slotAbrirTienda();
	// void slotAbrirEditarTaberna();
	// void slotAbrirEditarTienda();
	// void slotCargarParty();
	// void slotGuardarParty();
	void slotGestionarParty();
	// void slotInventario();
	void slotCrearParty();
	// void slotSalir();
};

#endif // MAINWINDOW_H
