#include "coordinatespeedtimemessage.h"

CoordinateSpeedTimeMessage::CoordinateSpeedTimeMessage() :
    AbstractMessage(9, 25)
{

}

quint16 CoordinateSpeedTimeMessage::checkSum() const
{
    return 0;
}

QByteArray CoordinateSpeedTimeMessage::formPackage() const
{
    return QByteArray();
}

quint8 CoordinateSpeedTimeMessage::rowCount() const
{
    return 11;
}

QString CoordinateSpeedTimeMessage::fieldName(quint8 row) const
{
    if (row > 10) return QString();

    switch (row)
    {
    case 0: return "Слово готовности";
    case 1: return "Признаки системы координат";
    case 2: return "Номер эллипсоида";
    case 3: return "Дата";
    case 4: return "Время";
    case 5: return "Широта (координата X)";
    case 6: return "Долгота (координата Y)";
    case 7: return "Высота (координата Z)";
    case 8: return "Составляющая скорости\n"
                   "по широте (X)";
    case 9: return "Составляющая скорости\n"
                   "по долготе (Y)";
    case 10: return "Составляющая скорости\n"
                    "по высоте (Z)";
    default: return QString();
    }
}

AbstractMessage::FieldType CoordinateSpeedTimeMessage::fieldType(quint8 row) const
{
    if (row > 10) return AbstractMessage::FieldType::Invalid;

    switch (row)
    {
    case 0: return AbstractMessage::FieldType::Bin16;
    case 1: return AbstractMessage::FieldType::Bin16;
    case 2: return AbstractMessage::FieldType::UInt16;
    case 3: return AbstractMessage::FieldType::Bin32;
    case 4: return AbstractMessage::FieldType::Bin32;
    case 5: return AbstractMessage::FieldType::Double;
    case 6: return AbstractMessage::FieldType::Double;
    case 7: return AbstractMessage::FieldType::Double;
    case 8: return AbstractMessage::FieldType::Float;
    case 9: return AbstractMessage::FieldType::Float;
    case 10: return AbstractMessage::FieldType::Float;
    default: return AbstractMessage::FieldType::Invalid;
    }
}

bool CoordinateSpeedTimeMessage::setField(quint8 row, QVariant value)
{
    if (row > 10) return false;

    switch (row) {
    case 0:
        readiness_word_ = value.toUInt();
        return true;
    case 1:
        coordinates_systems_signs_ = value.toUInt();
        return true;
    case 2:
        ellipsoid_number_ = value.toInt();
        return true;
    case 3:
        date_ = value.toUInt();
        return true;
    case 4:
        time_ = value.toUInt();
        return true;
    case 5:
         latitude_ = value.toDouble();
        return true;
    case 6:
         longitude_ = value.toDouble();
        return true;
    case 7:
         altitude_ = value.toDouble();
        return true;
    case 8:
         speed_latitude_component_ = value.toFloat();
        return true;
    case 9:
         speed_longitude_component_ = value.toFloat();
        return true;
    case 10:
         speed_altitude_component_ = value.toFloat();
        return true;
    default:
        return false;
    }
}

QVariant CoordinateSpeedTimeMessage::field(quint8 row) const
{
    if (row > 10) return QVariant();

    switch (row)
    {
    case 0: return readiness_word_.value();
    case 1: return coordinates_systems_signs_.value();
    case 2: return ellipsoid_number_;
    case 3: return date_.value();
    case 4: return time_.value();
    case 5: return latitude_;
    case 6: return longitude_;
    case 7: return altitude_;
    case 8: return speed_latitude_component_;
    case 9: return speed_longitude_component_;
    case 10: return speed_altitude_component_;
    default: return QVariant();
    }
}
