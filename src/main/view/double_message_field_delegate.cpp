#include "double_message_field_delegate.h"

#include <QDoubleSpinBox>

DoubleMessageFieldDelegate::DoubleMessageFieldDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{

}

QWidget* DoubleMessageFieldDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                      const QModelIndex &index) const
{
    Q_UNUSED(option)
    Q_UNUSED(index)

    QDoubleSpinBox *editor = new QDoubleSpinBox(parent);
    editor->setFrame(false);
    editor->setMinimum(-1.79e+308);
    editor->setMaximum(1.79e+308);
    editor->setDecimals(15);

    return editor;
}

void DoubleMessageFieldDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    double value = index.model()->data(index, Qt::EditRole).toDouble();

    QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
    spinBox->setValue(value);
}

void DoubleMessageFieldDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                  const QModelIndex &index) const
{
    QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
    double value = spinBox->value();

    model->setData(index, value, Qt::EditRole);
}

void DoubleMessageFieldDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const
{
    Q_UNUSED(index)

    editor->setGeometry(option.rect);
}
