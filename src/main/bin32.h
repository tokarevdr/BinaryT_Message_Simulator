#include <QCoreApplication>
#include <QDebug>

class bin32
{
public:

    bin32(quint32 value = 0);

    void SetBit(quint8 bit, bool value);
    bool GetBit(quint8 bit) const;
    quint32 GetBits(quint8 bit_begin, quint8 bit_end) const;
    void SetValue(quint32 buffer);

private:
    quint32 value_;
};
