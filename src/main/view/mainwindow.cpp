#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QModelIndex>
#include <QLineEdit>

#include "view/double_message_field_table_widget_delegate.h"
#include "view/float_message_field_table_widget_delegate.h"
#include "view/uint16_message_field_table_widget_delegate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _messageFieldsModel = new MessageFieldsModel();

    ui->tableView_messageFields->setModel(_messageFieldsModel);
    ui->tableView_messageFields->horizontalHeader()->setVisible(true);

    setTableViewFields(_messageFieldsModel->getMessageFieldsType());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTableViewFields(QList<IMessageFields::FieldType> fieldsType)
{
    int i = 0;
    foreach(IMessageFields::FieldType fieldType, fieldsType)
    {

        switch(fieldType)
        {
        case IMessageFields::FieldType::Double:
        {
            DoubleMessageFieldTableWidgetDelegate *delegate = new DoubleMessageFieldTableWidgetDelegate();
            ui->tableView_messageFields->setItemDelegateForRow(i, delegate);
            break;
        }

        case IMessageFields::FieldType::Float:
        {
            FloatMessageFieldTableWidgetDelegate *delegate = new FloatMessageFieldTableWidgetDelegate();
            ui->tableView_messageFields->setItemDelegateForRow(i, delegate);
            break;
        }

        case IMessageFields::FieldType::Uint16:
        {
            UInt16MessageFieldTableWidgetDelegate *delegate = new UInt16MessageFieldTableWidgetDelegate();
            ui->tableView_messageFields->setItemDelegateForRow(i, delegate);
            break;
        }

        default:
        {
            QStyledItemDelegate *delegate = new QStyledItemDelegate();
            ui->tableView_messageFields->setItemDelegateForRow(i, delegate);
            break;
        }
        }

        ++i;
    }
}

