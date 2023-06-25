#include <QCoreApplication>
#include <QDebug>


class bin16
{

public:

    bin16(quint16 value = 0);

    void SetBit(quint8 bit, bool value);
    bool GetBit(quint8 bit) const;
    quint16 GetBits(quint8 bit_begin, quint8 bit_end) const;
    void SetValue(quint16 buffer);

private:
    quint16 value_;
};

/* ............ */ 

class bin32
{
public:

    bin32(quint32 value = 0);

    void SetBit32(quint8 bit, bool value);
    bool GetBit32(quint8 bit) const;
    quint32 GetBits32(quint8 bit_begin, quint8 bit_end) const;
    void SetValue32(quint32 buffer);

private:
    quint32 value_;
};
