#pragma once

#include <QObject>
#include <QTcpSocket>

class ClientClass  : public QObject
{
	Q_OBJECT

public:
	ClientClass(QObject *parent);
	~ClientClass();
	bool connectToServer(QString, quint16);			// Connects to the server.
	void sendMessage(QString);						// Sends a message to the server.

signals:
	void messageReceived(QString, int);				// int{0 = left, 1 = right}; Triggers when a message is received.

private:
	QTcpSocket *socket;

protected slots:
	void receiveMessage();							// Receives a message from the server.

};
