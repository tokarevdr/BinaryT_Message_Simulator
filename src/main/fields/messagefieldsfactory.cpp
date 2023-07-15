#include "messagefieldsfactory.h"

MessageFieldsFactory::MessageFieldsFactory(IMessageFields::FieldType type)
{
    this->type = type;
}

IMessageFields MessageFieldsFactory::getFields() const
{

}
