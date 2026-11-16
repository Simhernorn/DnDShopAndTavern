#ifndef _ITEM_H_
#define _ITEM_H_

#include <qstring.h>

class Item
{
public:
	QString *itemName;
	float *price;
	Item();

	QString *getItemName();
};

#endif // _ITEM_H_
