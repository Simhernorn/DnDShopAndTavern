#include "createpartywindow.h"
#include "playerformwidget.h"

CreatePartyWindow::CreatePartyWindow(QWidget *parent) : QDialog(parent) {
	/*
	QSpinBox
		*btnPlayerQuantity;
	QPushButton
		*btnAccept,
		*btnCancel;
	*/

	sbPlayerQuantity = new QSpinBox;
	sbPlayerQuantity->setMinimum(1);
	sbPlayerQuantity->setMaximum(6);

	numberPlayerQuantity = sbPlayerQuantity->value();

	frameForms = new QFrame;
	vLayoutFrame = new QVBoxLayout;

	for (int i = 0; i < numberPlayerQuantity; ++i) {
		PlayerFormWidget *pfw = new PlayerFormWidget;
		vLayoutFrame->addWidget(pfw);
	}

	frameForms->setLayout(vLayoutFrame);

	btnAccept = new QPushButton("Aceptar");
	btnCancel = new QPushButton("Cancelar");

	layoutBotones = new QHBoxLayout;
	layoutPrincipal = new QVBoxLayout;

	layoutBotones->addWidget(btnAccept);
	layoutBotones->addWidget(btnCancel);

	layoutPrincipal->addWidget(sbPlayerQuantity);
	layoutPrincipal->addWidget(frameForms);
	layoutPrincipal->addLayout(layoutBotones);

	this->setLayout(layoutPrincipal);
}
