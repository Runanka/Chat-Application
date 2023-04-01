#include "connectdialogc.h"
#include "ui_connectdialog.h"

#include <QDialog>

ConnectDialogClass::ConnectDialogClass(QWidget* parent): 
	QDialog(parent),
	ui_dialog(new Ui::ConnectDialogClass)
{
	ui_dialog->setupUi(this);
}

ConnectDialogClass::~ConnectDialogClass()
{
	delete ui_dialog;
}
