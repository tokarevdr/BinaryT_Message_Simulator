#include "message_field_table_widget.h"

#include <QTableWidgetItem>
#include <QHeaderView>

#include "gui/uint16_message_field_table_widget_delegate.h"
#include "gui/double_message_field_table_widget_delegate.h"
#include "gui/float_message_field_table_widget_delegate.h"

MessageFieldTableWidget::MessageFieldTableWidget(QWidget *parent) :
    QTableWidget(parent)
{
    this->verticalHeader()->hide();
    this->horizontalHeader()->hide();
}

void MessageFieldTableWidget::setFields(QMap<QString, int> messageFields)
{
    this->clear();
    this->setColumnCount(2);
    this->setRowCount(messageFields.count());

    int row = 0;

    QMap<QString, int>::const_iterator i = messageFields.constBegin();

    // Цикл разбора мапы и заполнения таблицы
    while (i != messageFields.constEnd()) {
        QTableWidgetItem *itemName = new QTableWidgetItem();
        QTableWidgetItem *itemValue = new QTableWidgetItem();

        itemName->setText(i.key());

        this->setItem(row, 0, itemName);
        this->setItem(row, 1, itemValue);

        if (i.value() == 0) // quint16
        {
            UInt16MessageFieldTableWidgetDelegate *uintDelegate = new UInt16MessageFieldTableWidgetDelegate();
            this->setItemDelegateForRow(row, uintDelegate);
        }

        if (i.value() == 1) // double
        {
            DoubleMessageFieldTableWidgetDelegate *doubleDelegate = new DoubleMessageFieldTableWidgetDelegate();
            this->setItemDelegateForRow(row, doubleDelegate);
        }

        if (i.value() == 2) // float
        {
            FloatMessageFieldTableWidgetDelegate *floatDelegate = new FloatMessageFieldTableWidgetDelegate();
            this->setItemDelegateForRow(row, floatDelegate);
        }

        ++i;
        ++row;
    }
}
