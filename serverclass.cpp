#include <QTcpServer>
#include <QTcpSocket>

#include "serverclass.h"

ServerClass::ServerClass(QObject *parent)
	: QObject(parent)
{
	server = new QTcpServer(this);
	socket = new QTcpSocket(this);
}

ServerClass::~ServerClass()
{
	delete socket;
}

bool ServerClass::startServer(QString ipAddress, quint16 port)
{
	// Start the server
	QHostAddress ip(ipAddress);
	if (!server->listen(ip, port)) {
		return false;
	}
	// Connect the server to the connection slot
	connect(server, SIGNAL(newConnection()), this, SLOT(connection()));
	return true;
}

// This is the slot that is called when the server receives a connection
void ServerClass::connection()
{
	socket = server->nextPendingConnection();
	// Connect the socket to the receiveMessage slot
	connect(socket, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
}

// This is the slot that is called when the server receives a message
void ServerClass::receiveMessage()
{
	QByteArray data = socket->readAll();
	QString message = QString::fromUtf8(data);
	emit messageReceived(message, 0);
}

// This is the method that is called when the server sends a message
void ServerClass::sendMessage(QString message)
{
	QByteArray data = message.toUtf8();
	socket->write(data);
}
