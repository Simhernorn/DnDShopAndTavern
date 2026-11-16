#include "player.h"

Player::Player() {

}

QString *Player::getCName() {
	return characterName;
}

QString *Player::getPName() {
	return playerName;
}

int *Player::getCharismaStat() {
	return charismaStat;
}

void Player::setCName(QString *nombre) {
	characterName = nombre;
}

void Player::setPName(QString *nombre) {
	playerName = nombre;
}

void Player::setCharismaStat(QString mod, int *num) {
	if (mod == "+")
		charismaStat = num;
	else
		charismaStat = hazNegativo(num);
}

int *Player::hazNegativo(int *punt) {
	*punt *= -1;
	return punt;
}

void Player::addItem(Item *item) {
	itemsAcquired.append(item);
}

int Player::barter() {
	int numero = QRandomGenerator::global()->bounded(1, 21); // 1-20
	int descuento = 0;

	if(numero == 20)
		descuento = 25;
	else if(numero <= 19 && numero >= 15)
		descuento = 20;
	else if(numero <= 14 && numero >= 10)
		descuento = 15;
	else if(numero <= 9 && numero >= 5)
		descuento = 10;
	else if(numero <= 4 && numero >= 2)
		descuento = 5;
	else
		descuento = 0;

	return descuento;
}

Item *Player::findItemByName(QString *nombre) {
	for (int i = 0; i < itemsAcquired.count(); ++i) {
		Item *item = itemsAcquired.at(i);
		QString *nombreItem = item->getItemName();
		if(nombre == nombreItem)
			return item;
	}

	return nullptr;
}