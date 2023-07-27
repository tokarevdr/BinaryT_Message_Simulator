#ifndef BIN32_H
#define BIN32_H

#include <QtGlobal>

class bin32
{
public:
    bin32(quint32 value = 0);

    void setBit(quint8 bit, bool value);
    bool bitAt(quint8 bit) const;
    quint32 bits(quint8 bit_begin, quint8 bit_end) const;
    void setValue(quint32 value);

private:
    quint32 value_;
};

#endif // BIN32_H
