#ifndef UINT32MESSAGEFIELDDELEGATE_H
#define UINT32MESSAGEFIELDDELEGATE_H

#include <QStyledItemDelegate>

class UInt32MessageFieldDelegate : public QStyledItemDelegate
{
public:
    explicit UInt32MessageFieldDelegate(QObject *parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                              const QModelIndex &index) const override;
};

#endif // UINT32MESSAGEFIELDDELEGATE_H
