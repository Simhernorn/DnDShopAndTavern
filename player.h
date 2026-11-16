#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <QList>
#include <QRandomGenerator>

#include <qstring.h>
#include "item.h"

class Player
{
public:
	QString
		*characterName,
		*playerName;
	QList<Item*> itemsAcquired;
	int *charismaStat;

	Player();

	QString *getCName();
	QString *getPName();
	int *getCharismaStat();

	void setCName(QString*);
	void setPName(QString*);
	void setCharismaStat(QString, int*);

	void addItem(Item*);
	int barter();
	Item *findItemByName(QString*);
	int *hazNegativo(int*);
};

#endif // _PLAYER_H_
