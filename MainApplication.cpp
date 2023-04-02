#include "MainApplication.h"
#include "connectdialogc.h"

#include <QDebug>

MainApplication::MainApplication(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect_dialog = new ConnectDialogClass(this);
    connect(connect_dialog, &ConnectDialogClass::implementServer, this, &MainApplication::server);
    connect(connect_dialog, &ConnectDialogClass::implementClient, this, &MainApplication::client);
}

MainApplication::~MainApplication()
{}

void MainApplication::on_actionConnect_triggered() {

    // Remove the help button from the title bar and display the dialog as a modal dialog
    connect_dialog->setWindowFlags(connect_dialog->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    connect_dialog->setModal(true);
    connect_dialog->show();

    qDebug() << "Connected";
}

void MainApplication::client(QString ipAddress, quint16 portAddress) {
	qDebug() << "Client code running";
}

void MainApplication::server(QString ipAddress, quint16 portAddress) {
	qDebug() << "Server code running";
}