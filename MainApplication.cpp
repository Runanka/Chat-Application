#include "MainApplication.h"
#include "connectdialogc.h"
#include "mymessage.h"

#include <QDebug>

MainApplication::MainApplication(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect_dialog = new ConnectDialogClass(this);
    connect(connect_dialog, &ConnectDialogClass::implementServer, this, &MainApplication::server);
    connect(connect_dialog, &ConnectDialogClass::implementClient, this, &MainApplication::client);


    textwidget = ui.scrollwidget;
    mainlayout = new QVBoxLayout(textwidget);
    mainlayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
}

MainApplication::~MainApplication()
{
    delete connect_dialog;
}

void MainApplication::on_actionConnect_triggered() {

    // Remove the help button from the title bar and display the dialog as a modal dialog
    connect_dialog->setWindowFlags(connect_dialog->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    connect_dialog->setModal(true);
    connect_dialog->show();

    qDebug() << "Connected";
}

void MainApplication::client(QString ipAddress, quint16 portAddress) {
	qDebug() << "Client code running";

    for (int i = 0; i < 10; i++) {
        QString text = "This is a long paragraph that needs to be wrapped after 40 characters. Sometimes there won't be any spaces at the end of the line so we need to handle that case too.";
        //QString text = "Hey how are you?";
        textUI(text, right);
        textUI(text, left);
	}
}



void MainApplication::server(QString ipAddress, quint16 portAddress) {
	qDebug() << "Server code running";

    for (int i = 0; i < 10; i++) {
		//QString text = "This is a long paragraph that needs to be wrapped after 40 characters. Sometimes there won't be any spaces at the end of the line so we need to handle that case too.";
		QString text = "Hey how are you?";
		textUI(text, right);
	}
}

void MainApplication::textUI(QString text, textAlign var) {

    QHBoxLayout* layout = new QHBoxLayout();

    if (var == right) {
        layout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
        layout->addWidget(new MyMessage(text));
    }
    else if (var == left) {
        layout->addWidget(new MyMessage(text));
        layout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
    }

    mainlayout->addLayout(layout);
}