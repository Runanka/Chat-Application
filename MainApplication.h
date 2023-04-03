#pragma once

#include <QtWidgets/QMainWindow>

#include "ui_MainApplication.h"
#include "connectdialogc.h"
#include "clientclass.h"
#include "serverclass.h"

class MainApplication : public QMainWindow
{
    Q_OBJECT

public:
    MainApplication(QWidget *parent = nullptr);
    ~MainApplication();


private:
    Ui::MainApplicationClass ui;
    ConnectDialogClass *connect_dialog;
    QVBoxLayout* mainlayout;
    QWidget* textwidget;
    QLineEdit* lineEdit;
    ClientClass *clientObject;
    ServerClass *serverObject;
    enum textAlign { left = 0, right = 1 };     // {message received: left, message sent: right}
    int sc = 0;                                 // {server selected: 0, client selected: 1}


private slots:
    void on_actionConnect_triggered();          // When the connect option is selected from the menu
    void sendButtonPressed();                   // When the send button is pressed
 
protected slots:
    void client(QString, quint16);			    // When the client option is selected from the dialog
    void server(QString, quint16);              // When the server option is selected from the dialog
    void printMessage(QString, int);            // Handles if the text is received or sent

protected:
    void textUI(QString, textAlign);            // Handles the UI of the text
};
