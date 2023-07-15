#ifndef MESSAGEFIELDSMODEL_H
#define MESSAGEFIELDSMODEL_H

#include <QAbstractTableModel>

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

    void setCurrentMessageFields(int type); // TODO enum

private:

};

#endif // MESSAGEFIELDSMODEL_H
