#ifndef BIN16MESSAGEFIELDDELEGATE_H
#define BIN16MESSAGEFIELDDELEGATE_H

#include <QStyledItemDelegate>

class Bin16MessageFieldDelegate : public QStyledItemDelegate
{
public:
    explicit Bin16MessageFieldDelegate(QObject *parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                              const QModelIndex &index) const override;

    QString displayText(const QVariant &value, const QLocale &locale) const override;
};

#endif // BIN16MESSAGEFIELDDELEGATE_H
