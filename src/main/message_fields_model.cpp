#include "message_fields_model.h"

MessageFieldsModel::MessageFieldsModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    _messageFields = std::make_unique<MockMessageFields>();
}

int MessageFieldsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    if (!_messageFields.get())
        return 0;

    return _messageFields.get()->getRowCount();
}

int MessageFieldsModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    return 2;
}

QVariant MessageFieldsModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role)

    if (!_messageFields.get())
        return QVariant();

    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        switch (index.column())
        {
        case 0:
            return _messageFields.get()->getFieldName(index.row());

        case 1:
            return _messageFields.get()->getField(index.row());
        }
    }

    return QVariant();
}

bool MessageFieldsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Q_UNUSED(role)

    if (!_messageFields.get())
        return false;

    if (!index.isValid())
        return false;

    return _messageFields.get()->setField(index.row(), value);
}

QVariant MessageFieldsModel::headerData(int section, Qt::Orientation orientation,
                            int role) const
{   
    if (role != Qt::DisplayRole)
        return QVariant();

    switch (orientation)
    {
    case Qt::Orientation::Horizontal:
        switch (section)
        {
        case 0:
            return tr("Величина");

        case 1:
            return tr("Значение");

        default:
            return QVariant();
        }

    case Qt::Orientation::Vertical:
        return QVariant();
    }

    return QVariant();
}

Qt::ItemFlags MessageFieldsModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    switch(index.column())
    {
    case 0:
        return Qt::ItemIsEnabled;

    case 1:
        return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
    }

    return Qt::ItemIsEnabled;
}

void MessageFieldsModel::setCurrentMessageFields(IMessageFields::FieldType fieldType)
{
   // _messageFields = Factory
}

QList<IMessageFields::FieldType> MessageFieldsModel::getMessageFieldsType() const
{
    if (!_messageFields.get())
        return QList<IMessageFields::FieldType>();

    QList<IMessageFields::FieldType> messageFieldsType;

    for (int i = 0; i < _messageFields->getRowCount(); ++i)
        messageFieldsType.append(_messageFields.get()->getFieldType(i));

    return messageFieldsType;
}
