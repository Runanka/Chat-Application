#include "mymessage.h"

#include <QHBoxLayout>
#include <QSpacerItem>

MyMessage::MyMessage(const QString& message, QWidget* parent)
    : QTextEdit(parent)
{

	setReadOnly(true);
	setText(message);
	QFontMetrics metrics(font());
	//QRect textRect = metrics.boundingRect(QRect(0, 0, 400, 400), Qt::TextWordWrap, message);
	//setFixedSize(textRect.size());


	//QSize textSize = metrics.size(Qt::TextWordWrap, message);
	//setFixedWidth(textSize.width() + 10);
	//setFixedHeight(textSize.height() + 10);
	
	setFixedWidth(50*metrics.averageCharWidth() < metrics.horizontalAdvance(message) + 10 ? 50 * metrics.averageCharWidth() : metrics.horizontalAdvance(message) + 10);
	setFixedHeight((metrics.height()*message.length())/50 + metrics.height() + 10);

}

MyMessage::~MyMessage()
{
}