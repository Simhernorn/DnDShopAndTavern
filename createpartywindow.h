#ifndef _CREATEPARTYWINDOW_H_
#define _CREATEPARTYWINDOW_H_

#include <QDialog>
#include <QSpinBox>
#include <QPushButton>
#include <QLayout>
#include <QFrame>
#include <QList>

#include "playerformwidget.h"

class CreatePartyWindow : public QDialog
{
Q_OBJECT

public:
	int sbQuantity;

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
	QList<PlayerFormWidget*> pfwList;

	void createPlayerFormWidgets(int);

	CreatePartyWindow(QWidget * parent = nullptr);

public slots:
	void slotPlayerQuantityChanged(int);
};

#endif // CREATEPARTYWINDOW_H
