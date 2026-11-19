#include "createpartywindow.h"

CreatePartyWindow::CreatePartyWindow(QWidget *parent) : QDialog(parent) {
	sbPlayerQuantity = new QSpinBox;
	sbPlayerQuantity->setMinimum(1);
	sbPlayerQuantity->setMaximum(6);
	sbPlayerQuantity->setValue(4);

	sbQuantity = sbPlayerQuantity->value();

	frameForms = new QFrame;
	vLayoutFrame = new QVBoxLayout;

	createPlayerFormWidgets(sbQuantity);

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

	connect(sbPlayerQuantity,
			SIGNAL(valueChanged(int)),
			this,
			SLOT(slotPlayerQuantityChanged(int)));
}

void CreatePartyWindow::createPlayerFormWidgets(int numberPlayerQuantity) {
	for (int i = 0; i < numberPlayerQuantity; ++i) {
		PlayerFormWidget *pfw = new PlayerFormWidget;
		vLayoutFrame->addWidget(pfw);
	}
}

void CreatePartyWindow::slotPlayerQuantityChanged(int num) {
	setUpdatesEnabled(false);

	QLayoutItem *item;
	while ((item = vLayoutFrame->takeAt(0)) != nullptr) {
		if (QWidget *widgetToDelete = item->widget()) {
			delete widgetToDelete;
		}
		delete item;
	}

	createPlayerFormWidgets(num);

	vLayoutFrame->activate();
	adjustSize();

	setUpdatesEnabled(true);
}