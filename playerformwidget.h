#ifndef PLAYERFORMWIDGET_H
#define PLAYERFORMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QLayout>

class PlayerFormWidget : public QWidget
{
	Q_OBJECT

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
		*playerNameLayout,
		*charismaGeneralLayout;
	QHBoxLayout
		*mainLayout,
		*charismaInputLayout;
	QStringList
		modSymbols = {"+","-"};
	PlayerFormWidget(QWidget *parent = nullptr);
};

#endif // PLAYERFORMWIDGET_H
