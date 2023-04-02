#include "connectdialogc.h"
#include "ui_connectdialog.h"
#include "MainApplication.h"

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
    QString portRegex = "^[0-9]{5}$";
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

    quint16 portAddress = ui_dialog->portLineEdit->text().toUInt();

    QString ipAddress = ui_dialog->ipLineEdit->text();
    QRegularExpression regex("^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])|([0-9a-fA-F]{1,4}:){7}([0-9a-fA-F]{1,4})$");
    QRegularExpressionMatch matchip = regex.match(ipAddress);

    bool isServer = ui_dialog->serverRadioButton->isChecked();


    if (matchip.hasMatch() && portAddress <= 65535 && portAddress >= 49152) {
        qDebug() << "String matches regex pattern";
        
        (isServer) ? emit implementServer(ipAddress, portAddress) :emit implementClient(ipAddress, portAddress);
        close();
        
    }
    else if(!matchip.hasMatch()){
        qDebug() << "String does not match ip regex pattern";
    }
    else if (portAddress > 65535 || portAddress < 49152) {
		qDebug() << "String does not match port regex pattern";
	}


    qDebug() << "Connect button pressed" << ipAddress << portAddress;
}
