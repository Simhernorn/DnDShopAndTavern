# Main things still to do

## MainWindow

1. Party detection functionality. If there is no parties at all, the app will ask you to create one. If there are one or more, it will ask to either create or load one
2. Crear Party button. It will start a CreatePartyWindow, which will save that party to an xml
3. Inventario button. It will start a InventoryWindow, which will show the party members and the objects they have bought so far

## Player class

1. Attributes: characterName, playerName, itemsAcquired, charismaStat
2. Getters and Setters
3. Method barter(), which will simulate a charisma roll, to then apply discounts to the shop
4. Method findItemByName()

## Party class

1. Attributes: playerList
2. Methods findByCharacterName() and findByPlayerName()
3. Method toXML(), which will turn the list of characters to XML format

## TavernWindow Dialog

1. Add bar to the left for gold spending visibility, there will be one QLabel for each character and one extra one for total gold
2. Add buttons for each character that there is, each button's text will be "Add to {Character}"
3. Add functionality of Player::barter()

## ShopWindow Dialog

1. Sell functionality
2. Add bar to the left for gold spending visibility, there will be one QLabel for each character and one extra one for total gold
3. Add buttons for each character that there is. Each button's text will be "Add to {Character}"
4. Add buttons for each character that there is. Each button's text will be "{Character} wants to sell...". Pushing this button will open a SellWindow
5. Add functionality of Player::barter()

## EditTavern and EditShop Dialog

1. Both display only a table of all the products, the spinbox to choose categories and the searching bar
2. Double clicking on an item opens a small editing dialog, meant to take and hold the new values for the item. After accepting the changes, these are put into a CSV that will override the base one

## ProductEdit Dialog

1. 3 fields: Name, Category and price
2. 3 QLabels and 3 QLineEdits
3. Accept and cancel buttons. Accepting puts the values into an overriding CSV, while cancelling simply closes the dialog
4. Reset value: QPushButton. Upon pressing, the dialog will be closed and the values of the product that's being shown will be taken out of the overriding CSV, returning to their normal state

## CSV Override

## CreatePartyWindow Dialog

1. QSpinBox for amount of players. Changing the amount of players in the QSpinBox will update the amount of player forms to fill
2. Variable amount of PlayerFormWidget. For loop to make it so that there are as many of these widgets as the number in the SpinBox
3. When "Accept" button is hit, it takes all the data from the different players and puts it into an xml

## PlayerFormWidget QWidget

1. Main Structure:

```h
#ifndef _PLAYERFORMWIDGET_H_
#define _PLAYERFORMWIDGET_H_

#include <QLabel>
#include <QLineEdit>
#include <QLayout>
#include <qstring.h>

class PlayerFormWidget : public QDialog
{
    Q_OOBJECT

public:
    QLabel
        *lblCharacterName,
        *lblPlayerName,
        *lblCharismaStat;
    QLineEdit
        *leCharacterName,
        *lePlayerName,
        *leCharismaStat;
    QComboBox
        *cbCharismaMod;
    QVBoxLayout
        *characterNameLayout,
        *playerNameLayout
        *charismaGeneralLayout;
    QHBoxLayout
        *mainLayout;
        *charismaInputLayout;
    QStringList
        *modSymbols = {"+","-"};

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
    lblCharismaStat = new QLabel("Modificador de carisma");
    leCharacterName = new QLineEdit();
    lePlayerName = new QLineEdit();
    leCharismaStat = new QLineEdit();

    cbCharismaMod = new QComboBox();
    cbCharismaMod->addItems(modSymbols);

    characterNameLayout = new QVBoxLayout();
    playerNameLayout = new QVBoxLayout();
    charismaGeneralLayout = new QVBoxLayout();
    mainLayout = new QHBoxLayout();
    charismaInputLayout = new QHBoxLayout();

    characterNameLayout->addWidget(lblCharacterName);
    characterNameLayout->addWidget(leCharacterName);
    playerNameLayout->addWidget(lblPlayerName);
    playerNameLayout->addWidget(lePlayerName);
    charismaInputLayout->addWidget(cbCharismaMod);
    charismaInputLayout->addWidget(leCharismaStat);
    charismaGeneralLayout->addWidget(lblCharismaStat);
    charismaGeneralLayout->addLayout(charismaInputLayout);

    mainLayout->addLayout(characterNameLayout);
    mainLayout->addLayout(playerNameLayout);
    mainLayout->addLayout(charismaGeneralLayout);

    this->setLayout(mainLayout);
}
```

## GestionarWindow Dialog

1. Dialog which will show the party members of the loaded party
2. 2 QLabels, one for the character´s name, another for the player's name
3. 2 QLineEdits, one for the character's name, another for the player's name
4. 3 QPushButtons, one to delete a character (a confirmation will be prompted through ConfirmWindow), one to accept changes and the other to deny changes

## ConfirmWindow Dialog

1. QLabel that will ask the user if he's sure. Depending on the conditions of the calling, it will display different messages, shown on the table below
2. Two QPushButtons, one to accept and one to cancel

| Condition | int passed when calling | Message |
| --- | --- | --- |
| Selling an item | 0 | This action will be permanent and irreversible. Are you sure you wish to sell this item? |
| Deleting a character | 1 | This action will be permanent and irreversible. Are you sure you wish to delete this character? |

## SellWindow Dialog

1. Display a table of all the items the character has, the spinbox to choose categories and the searching bar.
2. Double clicking on one of the items will prompt a ConfirmWindow. If the ConfirmWindow is accepted, the item will be sold

## SaveParty Functionality/Dialog

1. Saves the party to an xml
2. Will read the characters in the list and take their names, their player's names and the objects they have bought to then put them into the file

## LoadParty Functionality/Dialog
