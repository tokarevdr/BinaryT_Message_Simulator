#include "mockmessage.h"

MockMessage::MockMessage(): AbstractMessage(205, 6)
{

}

quint16 MockMessage::checkSum() const
{
    return 0;
}

QByteArray MockMessage::formPackage() const
{
    QByteArray payload("МОК сообщение");

//    payload.resize(informational_part_length_);

//    payload[0] = uint16;
//    payload[1] = uint32;
//    payload[2] = bin_16.value();
//    payload[3] = bin_32.value();
//    payload[4] = floatVar;
//    payload[5] = doubleVar;

    return payload;
}

quint8 MockMessage::rowCount() const
{
    return 6;
}

QString MockMessage::fieldName(quint8 row) const
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

AbstractMessage::FieldType MockMessage::fieldType(quint8 row) const
{
    if (row > 5) return AbstractMessage::FieldType::Invalid;

    switch (row)
    {
    case 0: return AbstractMessage::FieldType::UInt16;
    case 1: return AbstractMessage::FieldType::UInt32;
    case 2: return AbstractMessage::FieldType::Bin16;
    case 3: return AbstractMessage::FieldType::Bin32;
    case 4: return AbstractMessage::FieldType::Float;
    case 5: return AbstractMessage::FieldType::Double;
    default: return AbstractMessage::FieldType::Invalid;
    }
}

bool MockMessage::setField(quint8 row, QVariant value)
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
        bin_16 = value.toUInt();
        return true;
    case 3:
        bin_32 = value.toUInt();
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

QVariant MockMessage::field(quint8 row) const
{
    if (row > 5) return QVariant();

    switch (row)
    {
    case 0: return uint16;
    case 1: return uint32;
    case 2: return bin_16.value();
    case 3: return bin_32.value();
    case 4: return floatVar;
    case 5: return doubleVar;
    default: return QVariant();
    }
}
