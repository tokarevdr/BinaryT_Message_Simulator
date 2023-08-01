#ifndef DOUBLEMESSAGEFIELDTABLEWIDGETDELEGATE_H
#define DOUBLEMESSAGEFIELDTABLEWIDGETDELEGATE_H

#include <QStyledItemDelegate>

class DoubleMessageFieldDelegate : public QStyledItemDelegate
{
public:
    explicit DoubleMessageFieldDelegate(QObject *parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                              const QModelIndex &index) const override;
};

#endif // DOUBLEMESSAGEFIELDTABLEWIDGETDELEGATE_H
