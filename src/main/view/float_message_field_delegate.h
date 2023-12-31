#ifndef FLOATMESSAGEFIELDTABLEWIDGETDELEGATE_H
#define FLOATMESSAGEFIELDTABLEWIDGETDELEGATE_H

#include <QStyledItemDelegate>

class FloatMessageFieldDelegate : public QStyledItemDelegate
{
public:
    explicit FloatMessageFieldDelegate(QObject *parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                              const QModelIndex &index) const override;
};

#endif // FLOATMESSAGEFIELDTABLEWIDGETDELEGATE_H
