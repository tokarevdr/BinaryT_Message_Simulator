#include "mockmessagefields.h"

MockMessageFields::MockMessageFields()
{

}

QString MockMessageFields::getFieldName(quint8 row) const
{
    if (row > 5 || row < 0) return QString();

    switch (row)
    {
    case 0: return "Uint16";
    case 1: return "Uint32";
    case 2: return "Bin16";
    case 3: return "Bin32";
    case 4: return "Float";
    case 5: return "Double";
    }
}

IMessageFields::FieldType MockMessageFields::getFieldType(quint8 row) const
{
    if (row > 5 || row < 0) return IMessageFields::FieldType::InvalidType;

    switch (row)
    {
    case 0: return IMessageFields::FieldType::Uint16;
    case 1: return IMessageFields::FieldType::Uint32;
    case 2: return IMessageFields::FieldType::Bin16;
    case 3: return IMessageFields::FieldType::Bin32;
    case 4: return IMessageFields::FieldType::Float;
    case 5: return IMessageFields::FieldType::Double;
    }
}

quint8 MockMessageFields::getRowCount() const
{
    return 6;
}

void MockMessageFields::setField(quint8 row, QVariant value)
{
    if (row > 5) return;

    switch (row) {
    case 0:
        uint16 = value.toUInt();
        break;
    case 1:
        uint32 = value.toUInt();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        floatVar = value.toFloat();
        break;
    case 5:
        doubleVar = value.toDouble();
        break;
    default:
        break;
    }
}
