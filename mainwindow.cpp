#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	lblBienvenida = new QLabel("Bienvenido/a!");
	lblBienvenida->setAlignment(Qt::AlignCenter);
	lblCargarParty = new QLabel("Por favor, carga o crea una party");
	lblCargarParty->setAlignment(Qt::AlignCenter);

	btnTaberna = new QPushButton("Taberna");
	btnTaberna->setEnabled(false);
	btnTienda = new QPushButton("Tienda");
	btnTienda->setEnabled(false);
	btnEditarTaberna = new QPushButton("Editar Taberna");
	btnEditarTaberna->setEnabled(false);
	btnEditarTienda = new QPushButton("Editar Tienda");
	btnEditarTienda->setEnabled(false);
	btnCargarParty = new QPushButton("Cargar Party");
	btnGuardarParty = new QPushButton("Guardar Party");
	btnGuardarParty->setEnabled(false);
	btnGestionarParty = new QPushButton("Gestionar Party");
	btnGestionarParty->setEnabled(false);
	btnInventario = new QPushButton("Inventario");
	btnInventario->setEnabled(false);
	btnCrearParty = new QPushButton("Crear Party");
	btnSalir = new QPushButton("Salir");

	tabernaTiendaLayout = new QHBoxLayout();
	tabernaTiendaLayout->addWidget(btnTaberna);
	tabernaTiendaLayout->addWidget(btnTienda);
	editarLayout = new QHBoxLayout();
	editarLayout->addWidget(btnEditarTaberna);
	editarLayout->addWidget(btnEditarTienda);
	cargarGuardarLayout = new QHBoxLayout();
	cargarGuardarLayout->addWidget(btnCargarParty);
	cargarGuardarLayout->addWidget(btnGuardarParty);
	gestionarEInventarioLayout = new QHBoxLayout();
	gestionarEInventarioLayout->addWidget(btnGestionarParty);
	gestionarEInventarioLayout->addWidget(btnInventario);

	principalLayout = new QVBoxLayout();
	principalLayout->addWidget(lblBienvenida);
	principalLayout->addWidget(lblCargarParty);
	principalLayout->addLayout(tabernaTiendaLayout);
	principalLayout->addLayout(editarLayout);
	principalLayout->addLayout(cargarGuardarLayout);
	principalLayout->addLayout(gestionarEInventarioLayout);
	principalLayout->addWidget(btnCrearParty);
	principalLayout->addWidget(btnSalir);

	centralWidget = new QWidget;

	centralWidget->setLayout(principalLayout);

	this->setCentralWidget(centralWidget);

	this->setFixedHeight(200);
	this->setFixedWidth(400);

	connect(btnTaberna,
			SIGNAL(clicked()),
			this,
			SLOT(slotAbrirTaberna()));

	/*
	connect(btnTienda,
			SIGNAL(clicked()),
			this,
			SLOT(slotAbrirTienda()));

	connect(btnEditarTaberna,
			SIGNAL(clicked()),
			this,
			SLOT(slotAbrirEditarTaberna()));

	connect(btnEditarTienda,
			SIGNAL(clicked()),
			this,
			SLOT(slotAbrirEditarTienda()));

	connect(btnCargarParty,
			SIGNAL(clicked()),
			this,
			SLOT(slotCargarParty()));

	connect(btnGuardarParty,
			SIGNAL(clicked()),
			this,
			SLOT(slotGuardarParty()));
	*/

	connect(btnGestionarParty,
			SIGNAL(clicked()),
			this,
			SLOT(slotGestionarParty()));

	/*
	connect(btnInventario,
			SIGNAL(clicked()),
			this,
			SLOT(slotInventario()));
	*/

	connect(btnCrearParty,
			SIGNAL(clicked()),
			this,
			SLOT(slotCrearParty()));

	/*
	connect(btnSalir,
			SIGNAL(clicked()),
			this,
			SLOT(slotSalir()));
	*/
}

void MainWindow::slotAbrirTaberna() {
	taberna = new TavernWindow();
	taberna->show();
}

void MainWindow::slotGestionarParty() {
	gestionar = new GestionarWindow();
	gestionar->show();
}

void MainWindow::slotCrearParty() {
	crear = new CreatePartyWindow();
	crear->show();
}