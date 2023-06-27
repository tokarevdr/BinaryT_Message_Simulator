#ifndef ISINK_H
#define ISINK_H

#include "abstractmessage.h"

namespace sink {

class ISink
{
public:
    virtual ~ISink() {};

    virtual void Send(std::unique_ptr<message::AbstractMessage> &message) = 0;
};

} // namespace sink

#endif // ISINK_H
