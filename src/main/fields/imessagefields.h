#ifndef IMESSAGEFIELDS_H
#define IMESSAGEFIELDS_H

#include "QMap"
#include "QString"
//#include "QList"
#include "QVariant"

class IMessageFields
{
public:

    enum class FieldType {
        Uint16, Uint32, Bin16, Bin32, Float, Double, Invalid
    };

//    virtual QMap<QString, FieldType> MessageFields() const = 0;
    virtual quint8 getRowCount() const = 0;
    virtual QString getFieldName(quint8 row) const = 0;
    virtual FieldType getFieldType(quint8 row) const = 0;
    virtual bool setField(quint8 row, QVariant value) = 0;
    virtual QVariant getField(quint8 row) const = 0;
//    virtual void SetFields(QList<QVariant>) = 0;
};

#endif // IMESSAGEFIELDS_H
