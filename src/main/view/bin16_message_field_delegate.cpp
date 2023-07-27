#include "bin16_message_field_delegate.h"

#include <QLineEdit>
#include <QRegularExpressionValidator>

Bin16MessageFieldDelegate::Bin16MessageFieldDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{

}

QWidget* Bin16MessageFieldDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                      const QModelIndex &index) const
{
    Q_UNUSED(option)
    Q_UNUSED(index)

    QLineEdit *editor = new QLineEdit(parent);
    editor->setFrame(false);
    QRegularExpression regExp("([0]|[1]){1,16}");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regExp);
    editor->setValidator(validator);

    return editor;
}

void Bin16MessageFieldDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.model()->data(index, Qt::EditRole).toInt();

    QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
    lineEdit->setText(QString::number(value, 2));
}

void Bin16MessageFieldDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                  const QModelIndex &index) const
{
    QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);

    int value = lineEdit->text().toInt(nullptr, 2);

    model->setData(index, value, Qt::EditRole);
}

void Bin16MessageFieldDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const
{
    Q_UNUSED(index)

    editor->setGeometry(option.rect);
}

QString Bin16MessageFieldDelegate::displayText(const QVariant &value, const QLocale &locale) const
{
    Q_UNUSED(locale)

    // небольшой костыль, иначе название поля преобразуется в число
    // из альтернатив: не переопределять метод и терпеть десятичный вывод чисел
    if (value.typeId() == QMetaType::QString)
        return value.toString();

    return QString::number(value.toUInt(), 2);
}
