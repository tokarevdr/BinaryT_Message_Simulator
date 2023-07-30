#ifndef ISINK_H
#define ISINK_H

#include <QByteArray>

class ISink
{
public:
    virtual ~ISink() {};

    virtual void send(const QByteArray &payload) = 0;

    virtual bool open() = 0;

    virtual void close() = 0;
};

#endif // ISINK_H
