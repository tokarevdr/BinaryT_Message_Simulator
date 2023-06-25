#include <QDebug>

#include "bin32.h"

bin32::bin32(quint32 value)
{
    value_ = value;
}

void bin32::SetBit(quint8 bit, bool value)
{
    if (bit >= 0 && bit <= 31){
    //устанавливаем бит по адресу
    if (value != false)
        value_ |= (1 << bit);
    else 
        value_ &= ~(1 << bit);    
    }
    else qDebug()<< "Inserted bit is out of range";
}

void bin32::SetValue(quint32 buffer)
{
    if(buffer >= 0 && buffer <= 4294967295)
    //устанавливаем значение
    value_ |= buffer;
    else qDebug() << "Inserted value is out of range";

}

bool bin32::GetBit(quint8 bit) const
{
    if (bit>=0 && bit <=31)
    return value_ & (1 << bit);
    else qDebug() << "Inserted bit is out of range";
}

quint32 bin32::GetBits(quint8 bit_begin, quint8 bit_end) const
{
    if (bit_begin <=31 && bit_begin >=0 && bit_end >=0 && bit_end <=31 && bit_end > bit_begin){
    quint8 length = bit_end - bit_begin;
    quint16 mask = 1;
    for(int i = 1; i<= length; i++){
        mask <<= 1;
        mask++;
    }
    return (value_ >> bit_begin) & mask;
}
    else qDebug() << "Inserted bit is out of range";
}
