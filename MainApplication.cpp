#include "MainApplication.h"

#include "connectdialogc.h"

#include <QDebug>

MainApplication::MainApplication(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

MainApplication::~MainApplication()
{}

void MainApplication::on_actionConnect_triggered() {
    ConnectDialogClass* connect_dialog = new ConnectDialogClass(this);

    // Remove the help button from the title bar
    connect_dialog->setWindowFlags(connect_dialog->windowFlags() & ~Qt::WindowContextHelpButtonHint);

    connect_dialog->setModal(true);
    connect_dialog->show();

    qDebug() << "Connected";
}
