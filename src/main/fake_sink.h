#ifndef FAKESINK_H
#define FAKESINK_H

#include "isink.h"

namespace sink {

class FakeSink : public ISink
{
public:
    FakeSink();

    void Send(std::unique_ptr<message::AbstractMessage> &message);
};

} // namespace sink

#endif // FAKESINK_H
