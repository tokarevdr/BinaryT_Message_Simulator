#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "message_fields_model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setTableViewFields(QList<IMessageFields::FieldType> fieldsType);

private:
    Ui::MainWindow *ui;
    MessageFieldsModel *_messageFieldsModel;
};
#endif // MAINWINDOW_H
