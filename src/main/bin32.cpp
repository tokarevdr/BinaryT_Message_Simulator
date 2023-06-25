#include <QDebug>

#include "bin32.h"

bin32::bin32(quint32 value)
{
    value_ = value;
}

void bin32::SetBit(quint8 bit, bool value)
{
    if (bit < 0 && bit > 31)
    {
        qDebug()<< "In class BIN32, in method SetBit(), error: Inserted bit is out of range";
        return;
    }
    else
    {
    //устанавливаем бит по адресу
    if (value != false)
        value_ |= (1 << bit);
    else
        value_ &= ~(1 << bit);
    }
}

void bin32::SetValue(quint32 buffer)
{
    //устанавливаем значение
    value_ |= buffer;
}

bool bin32::GetBit(quint8 bit) const
{
    if (bit<0 && bit > 31)
    {
     qDebug() << "In class BIN32, in method GetBit(), error: Inserted bit is out of range";
     return false;
    }
    else return value_ & (1 << bit);;
}

quint32 bin32::GetBits(quint8 bit_begin, quint8 bit_end) const
{
    if (bit_begin > 31 && bit_begin < 0 && bit_end < 0 && bit_end > 31)
    {
        qDebug() << "In class BIN32, in method GetBits(), error: Inserted bit is out of range";
        return 0;
    }
    else if (bit_end < bit_begin)
    {
        qDebug() << "In class BIN32, in method GetBits(), error: The bit order is entered incorrectly";
        return 0;
    }
    else
    {
    quint8 length = bit_end - bit_begin;
    quint16 mask = 1;
    for(int i = 1; i<= length; i++){
        mask <<= 1;
        mask++;
    }
    return (value_ >> bit_begin) & mask;
    }
}
