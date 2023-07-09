#include "float_message_field_table_widget_delegate.h"

#include <QDoubleSpinBox>

FloatMessageFieldTableWidgetDelegate::FloatMessageFieldTableWidgetDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{

}

QWidget* FloatMessageFieldTableWidgetDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                      const QModelIndex &index) const
{
    if (index.column() != 1)
        return QStyledItemDelegate::createEditor(parent, option, index);

    QDoubleSpinBox *editor = new QDoubleSpinBox(parent);
    editor->setFrame(false);
    editor->setMinimum(-3.4e+38);
    editor->setMaximum(3.4e+38);
    editor->setDecimals(6);

    return editor;
}

void FloatMessageFieldTableWidgetDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if (index.column() != 1)
    {
        QStyledItemDelegate::setEditorData(editor, index);
        return;
    }

    float value = index.model()->data(index, Qt::EditRole).toFloat();

    QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
    spinBox->setValue(value);
}

void FloatMessageFieldTableWidgetDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                  const QModelIndex &index) const
{
    if (index.column() != 1)
    {
        QStyledItemDelegate::setModelData(editor, model, index);
        return;
    }

    QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
    float value = spinBox->value();

    model->setData(index, value, Qt::EditRole);
}

void FloatMessageFieldTableWidgetDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const
{
    if (index.column() != 1)
    {
        QStyledItemDelegate::updateEditorGeometry(editor, option, index);
        return;
    }

    editor->setGeometry(option.rect);
}
