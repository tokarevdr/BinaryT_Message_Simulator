#ifndef FAKESINK_H
#define FAKESINK_H

#include "isink.h"



class FakeSink : public ISink
{
public:
    FakeSink();

    void Send(const AbstractMessage message);
};

#endif // FAKESINK_H
