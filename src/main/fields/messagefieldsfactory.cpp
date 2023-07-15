#include "messagefieldsfactory.h"
#include "messages/messagetype.h"
#include "mockmessagefields.h"

#include <memory.h>

MessageFieldsFactory::MessageFieldsFactory(MessageType type)
{
    this->type = type;
}

std::unique_ptr<IMessageFields> MessageFieldsFactory::getFields() const
{
    switch (type)
    {
    case MessageType::CoordinateSpeedTimeMessage:
        break;
    case MessageType::MockMessage:
        return std::make_unique<MockMessageFields>();
        break;
    }
}
