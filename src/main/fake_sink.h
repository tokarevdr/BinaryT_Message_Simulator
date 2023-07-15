#ifndef FAKESINK_H
#define FAKESINK_H

#include "isink.h"

namespace sink {

class FakeSink : public ISink
{
public:
    FakeSink();

    void Send(std::unique_ptr<AbstractMessage> &message);
};

} // namespace sink

#endif // FAKESINK_H
