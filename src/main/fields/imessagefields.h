#ifndef IMESSAGEFIELDS_H
#define IMESSAGEFIELDS_H

#include "QMap"
#include "QString"
#include "QList"
#include "QVariant"


class IMessageFields
{
public:

    enum class FieldType {
        Uint16, Uint32, Bin16, Bin32, Float, Double
    };

    virtual QMap<QString, FieldType> MessageFields() const = 0;
    virtual void SetFields(QList<QVariant>) = 0;
};

#endif // IMESSAGEFIELDS_H
