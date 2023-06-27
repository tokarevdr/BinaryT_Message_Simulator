#include <QtGlobal>

#include "bin16.h"
 
bin16::bin16(quint16 value)
{
    value_ = value;
}

void bin16::SetBit(quint8 bit, bool value)
{
    Q_ASSERT(bit <= 15);
    //устанавливаем бит по адресу
    value ? value_ |= (1 << bit) : value_ &= ~(1 << bit);
}

void bin16::SetValue(quint16 buffer)
{
    //устанавливаем значение
    value_ |= buffer;
}

bool bin16::GetBit(quint8 bit) const
{
    Q_ASSERT(bit <= 15);
    return value_ & (1 << bit);
}

quint16 bin16::GetBits(quint8 bit_begin, quint8 bit_end) const
{
    Q_ASSERT(bit_end <= 15 && bit_end > bit_begin);

    quint8 length = bit_end - bit_begin;
    quint16 mask = 1;
    for(int i = 1; i<= length; i++)
    {
        mask <<= 1;
        mask++;
    }
    return (value_ >> bit_begin) & mask;
}
