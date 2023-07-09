#include "message_field_table_widget.h"

#include <QTableWidgetItem>
#include <QHeaderView>

MessageFieldTableWidget::MessageFieldTableWidget(QWidget *parent) :
    QTableWidget(parent)
{
    this->verticalHeader()->hide();
    this->horizontalHeader()->hide();
    this->setColumnCount(2);
    this->setSelectionMode(QAbstractItemView::NoSelection);
}

void MessageFieldTableWidget::setField(int row, const QString &name, QStyledItemDelegate *delegate)
{
    QTableWidgetItem *itemName = new QTableWidgetItem();
    QTableWidgetItem *itemValue = new QTableWidgetItem();

    itemName->setText(name);
    itemName->setFlags(itemName->flags() ^ Qt::ItemIsEditable);

    this->setItem(row, 0, itemName);
    this->setItem(row, 1, itemValue);

    this->setItemDelegateForRow(row, delegate);
}

void MessageFieldTableWidget::clearAndSetRowCount(int rowCount)
{
    this->clear();
    this->setRowCount(rowCount);
}
