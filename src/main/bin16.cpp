#include <QDebug>

#include "bin16.h"
 
bin16::bin16(quint16 value)
{
    value_ = value;
}

void bin16::SetBit(quint8 bit, bool value)
{
    if (bit < 0 && bit > 15)
    {
        qDebug()<< "bin16:SetBit(): Inserted bit is out of range";
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

void bin16::SetValue(quint16 buffer)
{
    //устанавливаем значение
    value_ |= buffer;
}

bool bin16::GetBit(quint8 bit) const
{
    if (bit<0 && bit > 15)
    {
     qDebug() << "bin16:GetBit(): Inserted bit is out of range";
     return false;
    }
    else return value_ & (1 << bit);;
}

quint16 bin16::GetBits(quint8 bit_begin, quint8 bit_end) const
{
    if (bit_begin > 15 && bit_begin < 0 && bit_end < 0 && bit_end > 15)
    {
        qDebug() << "bin16:GetBits(): Inserted bit is out of range";
        return 0;
    }
    else if (bit_end < bit_begin)
    {
        qDebug() << "bin16:GetBits(): start bit > end bit";
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
