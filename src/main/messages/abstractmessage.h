#ifndef ABSTRACTMESSAGE_H
#define ABSTRACTMESSAGE_H

#include <QString>
#include <QVariant>

class AbstractMessage
{
public:
    enum class FieldType {
        UInt16, UInt32, Bin16, Bin32, Float, Double, Invalid
    };

    AbstractMessage(quint8 message_identifier,
                    quint8 informational_part_length);

    quint16 checkSum() const;
    QByteArray formPackage() const;
    //virtual QMap<QString, int> getFields() const = 0;

    virtual quint8 rowCount() const = 0;
    virtual QString fieldName(quint8 row) const = 0;
    virtual FieldType fieldType(quint8 row) const = 0;
    virtual bool setField(quint8 row, QVariant value) = 0;
    virtual QVariant field(quint8 row) const = 0;
    //virtual void SetFields(QList<QVariant>) = 0;

protected:
    static constexpr quint16 kHeaderIdentifier = 0xF157;
    const quint8 message_identifier_;
    const quint8 informational_part_length_;
};

#endif // ABSTRACTMESSAGE_H
