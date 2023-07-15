#ifndef FAKESINK_H
#define FAKESINK_H

#include "../isink.h"
#include "../abstractmessage.h"


class FakeSink : public ISink
{
public:
    FakeSink();

    void Send(const AbstractMessage message) const override;
};

#endif // FAKESINK_H
