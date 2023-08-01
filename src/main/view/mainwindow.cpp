#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QModelIndex>
#include <QLineEdit>

#include "double_message_field_delegate.h"
#include "float_message_field_delegate.h"
#include "uint16_message_field_delegate.h"
#include "uint32_message_field_delegate.h"
#include "bin16_message_field_delegate.h"
#include "bin32_message_field_delegate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    messageModel_ = new MessageModel();

    ui->comboBox_messageNames->addItems(messageModel_->messageNames());
    ui->comboBox_messageNames->setCurrentIndex(-1);

    ui->tableView_messageFields->setModel(messageModel_);
    ui->tableView_messageFields->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_messageFields->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    setTableViewFields(messageModel_->fieldTypes());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTableViewFields(QList<AbstractMessage::FieldType> fieldsType)
{
    int i = 0;
    foreach(AbstractMessage::FieldType fieldType, fieldsType)
    {

        switch(fieldType)
        {
        case AbstractMessage::FieldType::Double:
        {
            DoubleMessageFieldDelegate *delegate = new DoubleMessageFieldDelegate();
            ui->tableView_messageFields->setItemDelegateForRow(i, delegate);
            break;
        }

        case AbstractMessage::FieldType::Float:
        {
            FloatMessageFieldDelegate *delegate = new FloatMessageFieldDelegate();
            ui->tableView_messageFields->setItemDelegateForRow(i, delegate);
            break;
        }

        case AbstractMessage::FieldType::UInt16:
        {
            UInt16MessageFieldDelegate *delegate = new UInt16MessageFieldDelegate();
            ui->tableView_messageFields->setItemDelegateForRow(i, delegate);
            break;
        }

        case AbstractMessage::FieldType::UInt32:
        {
            UInt32MessageFieldDelegate *delegate = new UInt32MessageFieldDelegate();
            ui->tableView_messageFields->setItemDelegateForRow(i, delegate);
            break;
        }

        case AbstractMessage::FieldType::Bin16:
        {
            Bin16MessageFieldDelegate *delegate = new Bin16MessageFieldDelegate();
            ui->tableView_messageFields->setItemDelegateForRow(i, delegate);
            break;
        }

        case AbstractMessage::FieldType::Bin32:
        {
            Bin32MessageFieldDelegate *delegate = new Bin32MessageFieldDelegate();
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


void MainWindow::on_comboBox_messageNames_currentTextChanged(const QString &arg1)
{
    messageModel_->setCurrentMessage(arg1);

    setTableViewFields(messageModel_->fieldTypes());
}

