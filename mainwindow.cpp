#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	lblBienvenida = new QLabel("Bienvenido/a!");
	lblBienvenida->setAlignment(Qt::AlignCenter);

	btnTaberna = new QPushButton("Taberna");
	btnTienda = new QPushButton("Tienda");
	btnEditarTaberna = new QPushButton("Editar Taberna");
	btnEditarTienda = new QPushButton("Editar Tienda");
	btnCargarParty = new QPushButton("Cargar Party");
	btnGuardarParty = new QPushButton("Guardar Party");
	btnGestionarParty = new QPushButton("Gestionar Party");
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
	gestionarSalirLayout = new QHBoxLayout();
	gestionarSalirLayout->addWidget(btnGestionarParty);
	gestionarSalirLayout->addWidget(btnSalir);

	principalLayout = new QVBoxLayout();
	principalLayout->addWidget(lblBienvenida);
	principalLayout->addLayout(tabernaTiendaLayout);
	principalLayout->addLayout(editarLayout);
	principalLayout->addLayout(cargarGuardarLayout);
	principalLayout->addLayout(gestionarSalirLayout);

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