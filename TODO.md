# Main things still to do

## MainWindow

1. Party detection functionality. If there is no parties at all, the app will ask you to create one
2. Create Party button. It will start a CreatePartyWindow, which will save that party to a CSV

## Player class

1. Attributes: characterName, playerName, itemsAcquired
2. Getters and Setters

## Party class

## TavernWindow Dialog

## ShopWindow Dialog

1. Buy/Sell functionality

## EditTavern Dialog

## EditShop Dialog

## CSV Override

## CreatePartyWindow Dialog

1. QSpinBox for amount of players. Changing the amount of players in the QSpinBox will update the amount of player forms to fill
2. Variable amount of PlayerFormWidget. For loop to make it so that there are as many of these widgets as the number in the SpinBox

## PlayerFormWidget QWidget

1. Main Structure:

```h
#ifndef _PLAYERFORMWIDGET_H_
#define _PLAYERFORMWIDGET_H_

#include <QLabel>
#include <QLineEdit>
#include <QLayout>

class PlayerFormWidget : public QDialog
{
    Q_OOBJECT

public:
    QLabel
        *lblCharacterName,
        *lblPlayerName;
    QLineEdit
        *leCharacterName,
        *lePlayerName;
    QVBoxLayout
        *characterNameLayout,
        *playerNameLayout;
    QHBoxLayout
        *mainLayout;

    PlayerFormWidget(QWidget *parent = nullptr);
};

#endif // _PLAYERFORMWIDGET_H_
```

```cpp
#include "playerformwidget.h"

PlayerFormWidget::PlayerFormWidget(QWidget *parent)
    : QDialog(parent)
{
    lblCharacterName = new QLabel("Nombre del personaje");
    lblPlayerName = new QLabel("Nombre del jugador");
    leCharacterName = new QLineEdit();
    lePlayerName = new QLineEdit();

    characterNameLayout = new QVBoxLayout();
    playerNameLayout = new QVBoxLayout();
    mainLayout = new QHBoxLayout();

    characterNameLayout->addWidget(lblCharacterName);
    characterNameLayout->addWidget(leCharacterName);
    playerNameLayout->addWidget(lblPlayerName);
    playerNameLayout->addWidget(lePlayerName);

    mainLayout->addLayout(characterNameLayout);
    mainLayout->addLayout(playerNameLayout);

    this->setLayout(mainLayout);
}
```

## GestionarWindow Dialog

## SaveParty Functionality/Dialog

## LoadParty Functionality/Dialog
