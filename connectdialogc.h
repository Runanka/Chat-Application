#pragma once

#include <ui_connectdialog.h>

#include <QDialog>

namespace Ui {
	class ConnectDialogClass;
}

class ConnectDialogClass  : public QDialog
{
	Q_OBJECT

public:
	explicit ConnectDialogClass(QWidget *parent = nullptr);
	~ConnectDialogClass();

private:
	Ui::ConnectDialogClass *ui_dialog;
};
