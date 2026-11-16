#ifndef _CREATEPARTYWINDOW_H_
#define _CREATEPARTYWINDOW_H_

#include <QDialog>
#include <QSpinBox>
#include <QPushButton>
#include <QLayout>
#include <QFrame>

class CreatePartyWindow : public QDialog
{
Q_OBJECT

public:
	int numberPlayerQuantity;

	QSpinBox
		*sbPlayerQuantity;
	QFrame
		*frameForms;
	QPushButton
		*btnAccept,
		*btnCancel;
	QHBoxLayout
		*layoutBotones;
	QVBoxLayout
		*layoutPrincipal,
		*vLayoutFrame;

	CreatePartyWindow(QWidget * parent = nullptr);
};

#endif // CREATEPARTYWINDOW_H
