#ifndef UINT16MESSAGEFIELDTABLEWIDGETDELEGATE_H
#define UINT16MESSAGEFIELDTABLEWIDGETDELEGATE_H

#include <QStyledItemDelegate>

class UInt16MessageFieldDelegate : public QStyledItemDelegate
{
public:
    explicit UInt16MessageFieldDelegate(QObject *parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                              const QModelIndex &index) const override;
};

#endif // UINT16MESSAGEFIELDTABLEWIDGETDELEGATE_H
