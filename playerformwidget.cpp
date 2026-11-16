#include "playerformwidget.h"

PlayerFormWidget::PlayerFormWidget(QWidget *parent)
	: QWidget(parent)
{
	lblCharacterName = new QLabel("Nombre del personaje");
	lblPlayerName = new QLabel("Nombre del jugador");
	lblCharismaStat = new QLabel("Modificador de carisma");
	leCharacterName = new QLineEdit();
	lePlayerName = new QLineEdit();
	leCharismaStat = new QLineEdit();

	cbCharismaMod = new QComboBox();
	cbCharismaMod->addItems(modSymbols);

	characterNameLayout = new QVBoxLayout();
	playerNameLayout = new QVBoxLayout();
	charismaGeneralLayout = new QVBoxLayout();
	mainLayout = new QHBoxLayout();
	charismaInputLayout = new QHBoxLayout();

	characterNameLayout->addWidget(lblCharacterName);
	characterNameLayout->addWidget(leCharacterName);
	playerNameLayout->addWidget(lblPlayerName);
	playerNameLayout->addWidget(lePlayerName);
	charismaInputLayout->addWidget(cbCharismaMod);
	charismaInputLayout->addWidget(leCharismaStat);
	charismaGeneralLayout->addWidget(lblCharismaStat);
	charismaGeneralLayout->addLayout(charismaInputLayout);

	mainLayout->addLayout(characterNameLayout);
	mainLayout->addLayout(playerNameLayout);
	mainLayout->addLayout(charismaGeneralLayout);

	this->setLayout(mainLayout);
}
