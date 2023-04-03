#pragma once

#include <QTextEdit>

class MyMessage : public QTextEdit
{
    Q_OBJECT

public:
    explicit MyMessage(const QString& message, QWidget* parent = nullptr);
    ~MyMessage();

private:
    const int MAX_WIDTH = 40;
};
