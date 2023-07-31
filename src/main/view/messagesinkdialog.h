#ifndef MESSAGESINKDIALOG_H
#define MESSAGESINKDIALOG_H

#include <QDialog>

#include "sinks/isink.h"

namespace Ui {
class MessageSinkDialog;
}

class MessageSinkDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MessageSinkDialog(QWidget *parent = nullptr);
    ~MessageSinkDialog();

    ISink* sink();

private slots:
    void on_comboBox_sink_currentIndexChanged(int index);

    void on_pushButton_accept_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::MessageSinkDialog *ui;
};

#endif // MESSAGESINKDIALOG_H
