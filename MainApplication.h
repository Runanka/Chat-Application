#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainApplication.h"
#include "connectdialogc.h"

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
    enum textAlign { left = 0, right = 1 };


private slots:
    void on_actionConnect_triggered();
 
public slots:
    void client(QString, quint16);
    void server(QString, quint16);

protected:
    void textUI(QString, textAlign);
};
