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

private slots:
	void connectPressed();										// Slot that is called when the connect button is pressed

signals:
	void implementServer(const QString,const quint16);			// Signal that a server has to be implemented
	void implementClient(const QString,const quint16);			// Signal that a client has to be implemented

};
