#ifndef _GESTIONARWINDOW_H_
#define _GESTIONARWINDOW_H_

#include <QDialog>
#include <QLayout>

class GestionarWindow : public QDialog
{
Q_OBJECT

public:
	GestionarWindow(QWidget *parent = nullptr);

public slots:
	void slotEjemplo();
};

#endif 
