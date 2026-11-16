#ifndef ITEM_H
#define ITEM_H

#include <qstring.h>

class Item
{
public:
	QString *itemName;
	float *price;
	Item();

	QString *getItemName();
};

#endif // ITEM_H
