#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainApplication.h"

class MainApplication : public QMainWindow
{
    Q_OBJECT

public:
    MainApplication(QWidget *parent = nullptr);
    ~MainApplication();

private:
    Ui::MainApplicationClass ui;

private slots:
    void on_actionConnect_triggered();
};
