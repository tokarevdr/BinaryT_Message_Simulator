#include "bin32.h"

bin32::bin32(quint32 value)
{
    value_ = value;
}

void bin32::setBit(quint8 bit, bool value)
{
    Q_ASSERT(bit <= 31);

    value ? value_ |= (1 << bit) : value_ &= ~(1 << bit);
}

void bin32::setValue(quint32 value)
{
    value_ |= value;
}

bool bin32::bitAt(quint8 bit) const
{
    Q_ASSERT(bit <= 31);
    return value_ & (1 << bit);
}

quint32 bin32::bits(quint8 bit_begin, quint8 bit_end) const
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
