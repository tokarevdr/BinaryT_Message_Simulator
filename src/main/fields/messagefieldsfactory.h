#ifndef MESSAGEFIELDSFACTORY_H
#define MESSAGEFIELDSFACTORY_H

#include "imessagefields.h"
#include "../messages/messagetype.h"

class MessageFieldsFactory
{
private:
    MessageType type;
public:
    MessageFieldsFactory(MessageType type);

    std::unique_ptr<IMessageFields> getFields() const;
};

#endif // MESSAGEFIELDSFACTORY_H
