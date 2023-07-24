#include "mockmessagefields.h"

MockMessageFields::MockMessageFields()
{

}

QString MockMessageFields::getFieldName(quint8 row) const
{
    if (row > 5) return QString();

    switch (row)
    {
    case 0: return "Uint16";
    case 1: return "Uint32";
    case 2: return "Bin16";
    case 3: return "Bin32";
    case 4: return "Float";
    case 5: return "Double";
    default: return QString();
    }
}

IMessageFields::FieldType MockMessageFields::getFieldType(quint8 row) const
{
    if (row > 5) return IMessageFields::FieldType::Invalid;

    switch (row)
    {
    case 0: return IMessageFields::FieldType::Uint16;
    case 1: return IMessageFields::FieldType::Uint32;
    case 2: return IMessageFields::FieldType::Bin16;
    case 3: return IMessageFields::FieldType::Bin32;
    case 4: return IMessageFields::FieldType::Float;
    case 5: return IMessageFields::FieldType::Double;
    default: return IMessageFields::FieldType::Invalid;
    }
}

quint8 MockMessageFields::getRowCount() const
{
    return 6;
}

bool MockMessageFields::setField(quint8 row, QVariant value)
{
    if (row > 5) return false;

    switch (row) {
    case 0:
        uint16 = value.toUInt();
        return true;
    case 1:
        uint32 = value.toUInt();
        return true;
    case 2:
        return true;
    case 3:
        return true;
    case 4:
        floatVar = value.toFloat();
        return true;
    case 5:
        doubleVar = value.toDouble();
        return true;
    default:
        return false;
    }
}

QVariant MockMessageFields::getField(quint8 row) const
{
    if (row > 5) return QVariant();

    switch (row)
    {
    case 0: return uint16;
    case 1: return uint32;
    case 2: return QVariant();
    case 3: return QVariant();
    case 4: return floatVar;
    case 5: return doubleVar;
    default: return QVariant();
    }
}
