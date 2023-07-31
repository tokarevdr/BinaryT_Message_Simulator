#include "messagesinkdialog.h"
#include "ui_messagesinkdialog.h"

#include "sinks/filesink.h"
#include "sinks/fake_sink.h"

#include <QSerialPortInfo>

MessageSinkDialog::MessageSinkDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageSinkDialog)
{
    ui->setupUi(this);

    foreach (QSerialPortInfo info, QSerialPortInfo::availablePorts()) {
        ui->comboBox_port->addItem(info.portName());
    }
}

MessageSinkDialog::~MessageSinkDialog()
{
    delete ui;
}

ISink* MessageSinkDialog::sink()
{
    switch (ui->comboBox_sink->currentIndex())
    {
    case 0:
        return new FileSink(ui->lineEdit_namepath->text());
    case 1:
        return new FakeSink();
    default:
        return new FakeSink();
    }
}

void MessageSinkDialog::on_comboBox_sink_currentIndexChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}

void MessageSinkDialog::on_pushButton_accept_clicked()
{
    accept();
}


void MessageSinkDialog::on_pushButton_cancel_clicked()
{
    reject();
}

