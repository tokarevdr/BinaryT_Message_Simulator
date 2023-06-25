
/* BIN16 */ 
bin16::bin16(quint16 value)
{
    value_ = value;
}

void bin16::SetBit(quint8 bit, bool value)
{
    //устанавливаем бит по адресу
    if (value != false)
        value_ |= (1 << bit);
    else {
        value_ |= (0 << bit);
    }
}

void bin16::SetValue(quint16 buffer)
{
    //устанавливаем значение
    value_ |= buffer;

}

bool bin16::GetBit(quint8 bit) const
{
    return value_ & (1 << bit);
}

quint16 bin16::GetBits(quint8 bit_begin, quint8 bit_end) const
{
    quint8 length = bit_end - bit_begin;
    quint16 mask = 1;
    for(int i = 1; i<= length; i++){
        mask <<= 1;
        mask++;
    }
    return (value_ >> bit_begin) & mask;

}

/* BIN32 */

bin32::bin32(quint32 value)
{
    value_ = value;
}

void bin32::SetBit32(quint8 bit, bool value)
{
    //устанавливаем бит по адресу
    if (value != false)
        value_ |= (1 << bit);
    else {
        value_ |= (0 << bit);
    }
}

void bin32::SetValue32(quint32 buffer)
{
    //устанавливаем значение
    value_ |= buffer;

}

bool bin32::GetBit32(quint8 bit) const
{
    return value_ & (1 << bit);
}

quint32 bin32::GetBits32(quint8 bit_begin, quint8 bit_end) const
{
    quint8 length = bit_end - bit_begin;
    quint32 mask = 1;
    for(int i = 1; i<= length; i++){
        mask <<= 1;
        mask++;
    }
    return (value_ >> bit_begin) & mask;

}
