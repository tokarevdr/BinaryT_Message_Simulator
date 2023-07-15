#include "message_fields_model.h"

MessageFieldsModel::MessageFieldsModel(QObject *parent)
    : QAbstractTableModel{parent}
{

}

int MessageFieldsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    return 20;
}

int MessageFieldsModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    return 2;
}

QVariant MessageFieldsModel::data(const QModelIndex &index, int role) const
{

}

bool MessageFieldsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

}

QVariant MessageFieldsModel::headerData(int section, Qt::Orientation orientation,
                            int role) const
{

}

void MessageFieldsModel::setCurrentMessageFields(int type) // TODO enum
{

}
