#include "mymessage.h"

#include <QHBoxLayout>
#include <QSpacerItem>

MyMessage::MyMessage(const QString& message, QWidget* parent)
    : QTextEdit(parent)
{

	setReadOnly(true);
	setText(message);

	// Sets the width of QTextEdit to 50 characters or the width of the message, whichever is greater
	// Sets the height of QTextEdit to the number of lines of text in the message
	QFontMetrics metrics(font());
	setFixedWidth(50*metrics.averageCharWidth() < metrics.horizontalAdvance(message) + 10 ? 50 * metrics.averageCharWidth() : metrics.horizontalAdvance(message) + 10);
	setFixedHeight((metrics.height()*message.length())/50 + metrics.height() + 10);

}

MyMessage::~MyMessage()
{
}