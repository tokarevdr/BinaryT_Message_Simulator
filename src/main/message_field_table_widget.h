#ifndef MESSAGEFIELDTABLEWIDGET_H
#define MESSAGEFIELDTABLEWIDGET_H

#include <QTableWidget>
#include <QStyledItemDelegate>

// класс приходится хранить в корневой папке проекта,
// потому что фича 'promote to' в дизайнере отказывается
// видеть файлы большей вложенности...
class MessageFieldTableWidget : public QTableWidget
{
public:
    MessageFieldTableWidget(QWidget *parent = nullptr);

    void setField(int row, const QString &name, QStyledItemDelegate *delegate);

    void clearAndSetRowCount(int rowCount);
};

#endif // MESSAGEFIELDTABLEWIDGET_H
