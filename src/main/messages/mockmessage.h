#ifndef MOCKMESSAGE_H
#define MOCKMESSAGE_H

#include <abstractmessage.h>
#include "mockmessagefields.h"

class MockMessage : public AbstractMessage
{
public:
    MockMessage(MockMessageFields);
};

#endif // MOCKMESSAGE_H
