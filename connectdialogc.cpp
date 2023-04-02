#include "connectdialogc.h"
#include "ui_connectdialog.h"

#include <QDialog>
#include <QString>
#include <QRegExpValidator>
#include <QPushButton>
#include <QDebug>

ConnectDialogClass::ConnectDialogClass(QWidget* parent): 
	QDialog(parent),
	ui_dialog(new Ui::ConnectDialogClass)
{
	ui_dialog->setupUi(this);


    // Set the IP address validator
    QLineEdit* ipLine = ui_dialog->ipLineEdit;
    QString ipAddressRegex = "^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])|([0-9a-fA-F]{1,4}:){7}([0-9a-fA-F]{1,4})$";
    QRegExpValidator* ipAddressValidator = new QRegExpValidator(QRegExp(ipAddressRegex), this);
    ipLine->setValidator(ipAddressValidator);
    ipLine->setCursorPosition(0);


    // Set the port validator
    QLineEdit* portLine = ui_dialog->portLineEdit;
    QString portRegex = "^([1-9]|[1-9][0-9]{1,3}|[1-5][0-9]{4}|6[0-4][0-9]{3}|65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])$";
    QRegExpValidator* portValidator = new QRegExpValidator(QRegExp(portRegex), this);
    portLine->setValidator(portValidator);
    portLine->setCursorPosition(0);


    // Set the default radio button
    QRadioButton *serverRadio = ui_dialog->serverRadioButton;
    serverRadio->setChecked(true);


    // Connect the connect button to the connectPressed slot
    connect(ui_dialog->connectButton, &QPushButton::clicked, this, &ConnectDialogClass::connectPressed);
}

ConnectDialogClass::~ConnectDialogClass()
{
	delete ui_dialog;
}


void ConnectDialogClass::connectPressed() {
    qDebug() << "Connect button pressed";
}
