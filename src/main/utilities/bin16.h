#ifndef BIN16_H
#define BIN16_H

#include <QtGlobal>

class bin16
{

public:
    bin16(quint16 value = 0);

    void setBit(quint8 bit, bool value);
    bool bitAt(quint8 bit) const;
    quint16 bits(quint8 bit_begin, quint8 bit_end) const;
    void setValue(quint16 value);
    quint16 value() const;

private:
    quint16 value_;
};

#endif // BIN16_H
