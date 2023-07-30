#ifndef FAKESINK_H
#define FAKESINK_H

#include "isink.h"

class FakeSink : public ISink
{
public:
    FakeSink();

    void send(const QByteArray &payload) override;
    bool open() override;
    void close() override;
};

#endif // FAKESINK_H
