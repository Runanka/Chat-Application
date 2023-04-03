#include "MainApplication.h"
#include "connectdialogc.h"
#include "mymessage.h"

MainApplication::MainApplication(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // Connect the send button to the sendButtonPressed slot
    connect(ui.sendButton, &QPushButton::pressed, this, &MainApplication::sendButtonPressed);
    ui.sendButton->setEnabled(false);

    // Connect the implementServer and implementClient signals to the server and client slots
    connect_dialog = new ConnectDialogClass(this);
    connect(connect_dialog, &ConnectDialogClass::implementServer, this, &MainApplication::server);
    connect(connect_dialog, &ConnectDialogClass::implementClient, this, &MainApplication::client);

    // Set the lineEdit and textwidget pointers to the lineEdit and scrollwidget objects in the UI
    lineEdit = ui.sentText;
    textwidget = ui.scrollwidget;

    // Set the mainlayout pointer to the layout of the scrollwidget and added a vertical spacer item to it
    mainlayout = new QVBoxLayout(textwidget);
    mainlayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
}

MainApplication::~MainApplication()
{
    delete connect_dialog;
    delete mainlayout;
    delete textwidget;
    delete lineEdit;
}

void MainApplication::on_actionConnect_triggered() {

    // Remove the help button from the title bar and display the dialog as a modal dialog
    connect_dialog->setWindowFlags(connect_dialog->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    connect_dialog->setModal(true);
    connect_dialog->show();
}

void MainApplication::sendButtonPressed() {
    // Send the message as a client or a server depending on the value of sc {0: server, 1: client}
    sc!=0 ? clientObject->sendMessage(lineEdit->text()): serverObject->sendMessage(lineEdit->text());
	textUI(lineEdit->text(), right);
    lineEdit->clear();
}

void MainApplication::printMessage(QString msg, int val) {
    // Print the message as a receive or sent depending on the value of val {0: received, 1: sent}
	val!=0 ? textUI(msg, right): textUI(msg, left);
}

void MainApplication::client(QString ipAddress, quint16 portAddress) {
    // Set the value of sc to 1 to imply client is chosen and disable the send button
    sc = 1;
    ui.sendButton->setEnabled(false);

    // Create a new client object and connect the messageReceived signal to the printMessage slot
    clientObject = new ClientClass(this);
    if (clientObject->connectToServer(ipAddress, portAddress)) {
        connect(clientObject, &ClientClass::messageReceived, this, &MainApplication::printMessage);
		textUI("Connected to the server", right);
        clientObject->sendMessage("Connected to the client");
        ui.sendButton->setEnabled(true);
	}
    else {
		textUI("Failed to connect to the server", right);
	}
}

void MainApplication::server(QString ipAddress, quint16 portAddress) {
    // Set the value of sc to 0 to imply server is chosen and disable the send button
    sc = 0;
    ui.sendButton->setEnabled(false);
    textUI("Waiting for client...", right);

    // Create a new server object and connect the messageReceived signal to the printMessage slot
    serverObject = new ServerClass(this);
    if (serverObject->startServer(ipAddress, portAddress)) {
		connect(serverObject, &ServerClass::messageReceived, this, &MainApplication::printMessage);
        ui.sendButton->setEnabled(true);
    }
    else {
        textUI("Failed to connect to the client", right);
    }
}

// For every message received or sent, create a new layout and add a spacer item to it
void MainApplication::textUI(QString text, textAlign var) {

    QHBoxLayout* layout = new QHBoxLayout();

    // If the message is sent, add a spacer item to the left and the message to the right
    if (var == right) {
        layout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
        layout->addWidget(new MyMessage(text));
    }
    // If the message is received, add the message to the left and a spacer item to the right
    else if (var == left) {
        layout->addWidget(new MyMessage(text));
        layout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
    }

    mainlayout->addLayout(layout);
}