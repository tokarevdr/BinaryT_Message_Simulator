#ifndef MESSAGEFIELDTABLEWIDGET_H
#define MESSAGEFIELDTABLEWIDGET_H

#include <QTableWidget>

// класс приходится хранить в корневой папке проекта,
// потому что фича 'promote to' в дизайнере отказывается
// видеть файлы большей вложенности...
class MessageFieldTableWidget : public QTableWidget
{
public:
    MessageFieldTableWidget(QWidget *parent = nullptr);

    void setFields(QMap<QString, int> messageFields);
};

#endif // MESSAGEFIELDTABLEWIDGET_H
