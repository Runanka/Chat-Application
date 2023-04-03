#include <QTcpSocket>
#include <QByteArray>

#include "clientclass.h"

ClientClass::ClientClass(QObject *parent)
	: QObject(parent)
{
	socket = new QTcpSocket(this);
}

ClientClass::~ClientClass()
{
	delete socket;
}

bool ClientClass::connectToServer(QString ip, quint16 port)
{
	// Connect to the server.
	socket->connectToHost(ip, port);

	if (socket->waitForConnected())
	{
		// When the socket has data to read, call the receiveMessage() slot.
		connect(socket, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
		return true;
	}
	else {
		return false;
	}
}

// This is the slot that is called when the socket has data to read.
void ClientClass::receiveMessage()
{
	QByteArray data = socket->readAll();
	QString message = QString::fromUtf8(data);

	emit messageReceived(message, 0);
}

// This is the method that is called when the socket has data to send.
void ClientClass::sendMessage(QString message)
{
	QByteArray data = message.toUtf8();
	socket->write(data);
}