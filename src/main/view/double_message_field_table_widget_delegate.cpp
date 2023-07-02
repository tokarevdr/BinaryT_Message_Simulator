#include "double_message_field_table_widget_delegate.h"

#include <QDoubleSpinBox>

DoubleMessageFieldTableWidgetDelegate::DoubleMessageFieldTableWidgetDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{

}

QWidget* DoubleMessageFieldTableWidgetDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                      const QModelIndex &index) const
{
    if (index.column() == 1)
    {
        QDoubleSpinBox *editor = new QDoubleSpinBox(parent);
        editor->setFrame(false);
        editor->setMinimum(-1.79e+308);
        editor->setMaximum(1.79e+308);
        editor->setDecimals(15);

        return editor;
    }

    return QStyledItemDelegate::createEditor(parent, option, index);
}

void DoubleMessageFieldTableWidgetDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if (index.column() == 1)
    {
        double value = index.model()->data(index, Qt::EditRole).toDouble();

        QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
        spinBox->setValue(value);

        return;
    }

    QStyledItemDelegate::setEditorData(editor, index);
}

void DoubleMessageFieldTableWidgetDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                  const QModelIndex &index) const
{
    if (index.column() == 1)
    {
        QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
        double value = spinBox->value();

        model->setData(index, value, Qt::EditRole);

        return;
    }

    QStyledItemDelegate::setModelData(editor, model, index);
}

void DoubleMessageFieldTableWidgetDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const
{
    if (index.column() == 1)
    {
        editor->setGeometry(option.rect);

        return;
    }

    QStyledItemDelegate::updateEditorGeometry(editor, option, index);
}
