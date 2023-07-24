#ifndef MESSAGEFIELDSMODEL_H
#define MESSAGEFIELDSMODEL_H

#include <memory>

#include <QAbstractTableModel>

#include "fields/mockmessagefields.h"

class MessageFieldsModel : public QAbstractTableModel
{
public:
    explicit MessageFieldsModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    QVariant headerData(int section, Qt::Orientation orientation,
                                int role = Qt::DisplayRole) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void setCurrentMessageFields(IMessageFields::FieldType fieldType);

    QList<IMessageFields::FieldType> getMessageFieldsType() const;

private:
    std::unique_ptr<IMessageFields> _messageFields;
};

#endif // MESSAGEFIELDSMODEL_H
