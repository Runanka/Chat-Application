#pragma once

#include <QTextEdit>

// This is a custom QTextEdit widget
class MyMessage : public QTextEdit
{
    Q_OBJECT

public:
    explicit MyMessage(const QString& message, QWidget* parent = nullptr);
    ~MyMessage();

private:
    const int MAX_WIDTH = 40;
};
