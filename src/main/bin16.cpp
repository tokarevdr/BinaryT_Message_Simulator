#include <QDebug>

#include "bin16.h"
 
bin16::bin16(quint16 value)
{
    value_ = value;
}

void bin16::SetBit(quint8 bit, bool value)
{
    if (bit >= 0 && bit <= 15){
    //устанавливаем бит по адресу
    if (value != false)
        value_ |= (1 << bit);
    else 
        value_ &= ~(1 << bit);    
    }
    else qDebug()<< "Inserted bit is out of range";
}

void bin16::SetValue(quint16 buffer)
{
    if(buffer >= 0 && buffer <= 65535)
    //устанавливаем значение
    value_ |= buffer;
    else qDebug() << "Inserted value is out of range";
}

bool bin16::GetBit(quint8 bit) const
{
    if (bit>=0 && bit <=15)
    return value_ & (1 << bit);
    else qDebug() << "Inserted bit is out of range";
}

quint16 bin16::GetBits(quint8 bit_begin, quint8 bit_end) const
{
    if (bit_begin <=15 && bit_begin >=0 && bit_end >=0 && bit_end <=15 && bit_end > bit_begin){
    quint8 length = bit_end - bit_begin;
    quint16 mask = 1;
    for(int i = 1; i<= length; i++){
        mask <<= 1;
        mask++;
    }
    return (value_ >> bit_begin) & mask;
    }
    else return "Inserted bit is out of range";

}
