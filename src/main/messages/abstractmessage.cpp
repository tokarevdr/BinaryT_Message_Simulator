#include "abstractmessage.h"

AbstractMessage::AbstractMessage(quint8 message_identifier,
                                 quint8 informational_part_length) :
    message_identifier_(message_identifier),
    informational_part_length_(informational_part_length)
{

}

quint16 AbstractMessage::checkSum() const
{
   quint16 check_sum = 0;
   for (int i = 0; i < informational_part_length_; ++i)
   {
       switch (field(i).type())
       {
       case QMetaType::Float:
       {
           quint32 float_bytes;
           float float_var = field(i).toFloat();
           memmove(&float_bytes, &float_var, 4);
           check_sum += float_bytes >> 16;
           check_sum += float_bytes;
           break;
       }
       case QMetaType::Double:
       {
           quint64 double_bytes;
           double double_var = field(i).toDouble();
           memmove(&double_bytes, &double_var, 8);
           check_sum += double_bytes >> 48;
           check_sum += double_bytes >> 32;
           check_sum += double_bytes >> 16;
           check_sum += double_bytes;
           break;
       }
       case QMetaType::UInt:
       {
           check_sum += field(i).toUInt();
           break;
       }
       case QMetaType::Int:
       {
           int bytes = field(i).toInt();
           check_sum += bytes >> 16;
           check_sum += bytes;
           break;
       }
       }
   }
   return check_sum; // TODO: предусмотреть переполнение и суммирование битов переноса
}

QByteArray AbstractMessage::formPackage() const
{
    QByteArray payload;

    payload.resize(informational_part_length_ * 2 + 6);
    payload[1] = kHeaderIdentifier >> 8;
    payload[0] = kHeaderIdentifier;
    payload[3] = message_identifier_;
    payload[2] = informational_part_length_;
    payload[5] = checkSum() >> 8;
    payload[4] = checkSum();

    for (int i = 0, j = 6; i < informational_part_length_; ++i)
    {
        switch (field(i).type())
        {
        case QMetaType::Float:
        {
            quint32 float_bytes;
            float float_var = field(i).toFloat();
            memmove(&float_bytes, &float_var, 4);
            payload[j] = float_bytes;
            payload[j+1] = float_bytes >> 8;
            payload[j+2] = float_bytes >> 16;
            payload[j+3] = float_bytes >> 24;
            j+=4;
            break;
        }
        case QMetaType::Double:
        {
            quint64 double_bytes;
            double double_var = field(i).toDouble();
            memmove(&double_bytes, &double_var, 8);
            payload[j] = double_bytes;
            payload[j+1] = double_bytes >> 8;
            payload[j+2] = double_bytes >> 16;
            payload[j+3] = double_bytes >> 24;
            payload[j+4] = double_bytes >> 32;
            payload[j+5] = double_bytes >> 40;
            payload[j+6] = double_bytes >> 48;
            payload[j+7] = double_bytes >> 56;
            j+=8;
            break;
        }
        case QMetaType::Int:
            payload[j] = field(i).toUInt();
            payload[j+1] = field(i).toUInt() >> 8;
            j+=2;
            break;

        case QMetaType::UInt:
            payload[j] = field(i).toUInt();
            payload[j+1] = field(i).toUInt() >> 8;
            payload[j+2] = field(i).toUInt() >> 16;
            payload[j+3] = field(i).toUInt() >> 24;
            j+=4;
            break;
        }
    }

    return payload;
}
