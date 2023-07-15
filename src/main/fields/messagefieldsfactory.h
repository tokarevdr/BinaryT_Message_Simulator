#ifndef MESSAGEFIELDSFACTORY_H
#define MESSAGEFIELDSFACTORY_H

#include "imessagefields.h"

class MessageFieldsFactory
{
private:
    IMessageFields::FieldType type;
public:
    MessageFieldsFactory(IMessageFields::FieldType type);

    IMessageFields getFields() const;
};

#endif // MESSAGEFIELDSFACTORY_H
