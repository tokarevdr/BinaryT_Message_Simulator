#include <QtGlobal>

#include "bin32.h"

bin32::bin32(quint32 value)
{
    value_ = value;
}

void bin32::SetBit(quint8 bit, bool value)
{
    Q_ASSERT(bit <= 31);
    //устанавливаем бит по адресу
    value ? value_ |= (1 << bit) : value_ &= ~(1 << bit);
}

void bin32::SetValue(quint32 buffer)
{
    //устанавливаем значение
    value_ |= buffer;
}

bool bin32::GetBit(quint8 bit) const
{
    Q_ASSERT(bit <= 31);
    return value_ & (1 << bit);
}

quint32 bin32::GetBits(quint8 bit_begin, quint8 bit_end) const
{
    Q_ASSERT(bit_end <= 31 && bit_end > bit_begin);

    quint8 length = bit_end - bit_begin;
    quint16 mask = 1;
    for(int i = 1; i<= length; i++)
    {
        mask <<= 1;
        mask++;
    }
    return (value_ >> bit_begin) & mask;
}
