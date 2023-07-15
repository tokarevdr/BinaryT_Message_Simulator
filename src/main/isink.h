#ifndef ISINK_H
#define ISINK_H

#include "abstractmessage.h"



class ISink
{
public:
    virtual ~ISink() {};

    virtual void Send(const AbstractMessage message) const = 0;
};

#endif // ISINK_H
