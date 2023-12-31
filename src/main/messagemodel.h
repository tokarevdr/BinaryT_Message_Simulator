#ifndef MESSAGEMODEL_H
#define MESSAGEMODEL_H

#include <QAbstractTableModel>

#include "messages/abstractmessage.h"
#include "sinks/isink.h"

class MessageModel : public QAbstractTableModel
{
public:
    explicit MessageModel(QObject *parent = nullptr);
    ~MessageModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    QVariant headerData(int section, Qt::Orientation orientation,
                                int role = Qt::DisplayRole) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void setCurrentMessage(const QString &messageName);
    QList<AbstractMessage::FieldType> fieldTypes() const;
    QStringList messageNames() const;
    void setSink(ISink* sink);
    void send();

private:
    QMap<QString, AbstractMessage*> messages_;
    QString currentMessageName_ = "";
    ISink *sink_ = nullptr;
};

#endif // MESSAGEMODEL_H
