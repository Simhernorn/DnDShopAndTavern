#ifndef _GESTIONARWINDOW_H_
#define _GESTIONARWINDOW_H_

#include <QVector>
#include <QDialog>
#include <QLayout>

class GestionarWindow : public QDialog{
Q_OBJECT

public:
	GestionarWindow(QWidget *parent = NULL);

public slots:
	void slotEjemplo();
};

#endif 
