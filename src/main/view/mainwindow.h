#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "messagemodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setTableViewFields(QList<AbstractMessage::FieldType> fieldTypes);

private slots:
    void on_comboBox_messageNames_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    MessageModel *messageModel_;
};
#endif // MAINWINDOW_H
