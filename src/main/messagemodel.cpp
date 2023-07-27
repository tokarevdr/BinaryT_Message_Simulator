#include "messagemodel.h"

#include "messages/mockmessage.h"
#include "messages/messagefactory.h"

MessageModel::MessageModel(QObject *parent)
    : QAbstractTableModel{parent}
{

}

int MessageModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    if (currentMessageName_.isEmpty())
        return 0;

    return messages_[currentMessageName_]->rowCount();
}

int MessageModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    return 2;
}

QVariant MessageModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role)

    if (currentMessageName_.isEmpty())
        return QVariant();

    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        switch (index.column())
        {
        case 0:
            return messages_[currentMessageName_]->fieldName(index.row());

        case 1:
            return messages_[currentMessageName_]->field(index.row());
        }
    }

    return QVariant();
}

bool MessageModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Q_UNUSED(role)

    if (currentMessageName_.isEmpty())
        return false;

    if (!index.isValid())
        return false;

    return messages_[currentMessageName_]->setField(index.row(), value);
}

QVariant MessageModel::headerData(int section, Qt::Orientation orientation,
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

Qt::ItemFlags MessageModel::flags(const QModelIndex &index) const
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

bool MessageModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row , row + count);
    endInsertRows();
    return true;
}

bool MessageModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row , row + count);
    endRemoveRows();
    return true;
}

void MessageModel::setCurrentMessage(const QString &messageName)
{
    // Создаем сообщение, если его еще не было
    if (!messages_.contains(messageName)) {
        MessageFactory factory(MessageFactory::Type::CoordinateSpeedTime);

        if (messageName == "Исходные КВ-данные")
            factory.setType(MessageFactory::Type::CoordinateSpeedTime);
        else if (messageName == "МОК")
            factory.setType(MessageFactory::Type::Mock);

        messages_[messageName] = factory.create();
    }

    if (!currentMessageName_.isEmpty()) {
        beginRemoveRows(QModelIndex(), 0, messages_[currentMessageName_]->rowCount() - 1);
        endRemoveRows();
    }

    currentMessageName_ = messageName;

    if (currentMessageName_.isEmpty())
        return;

    beginInsertRows(QModelIndex(), 0, messages_[currentMessageName_]->rowCount() - 1);
    endInsertRows();
}

QList<AbstractMessage::FieldType> MessageModel::fieldTypes() const
{
    if (currentMessageName_.isEmpty())
        return QList<AbstractMessage::FieldType>();

    QList<AbstractMessage::FieldType> messageFieldsType;

    for (int i = 0; i < messages_[currentMessageName_]->rowCount(); ++i)
        messageFieldsType.append(messages_[currentMessageName_]->fieldType(i));

    return messageFieldsType;
}

QStringList MessageModel::messageNames() const
{
    QStringList names;

    names << "МОК";

    names << "Исходные КВ-данные";

    return names;
}
