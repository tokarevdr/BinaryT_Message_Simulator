#include "messagefactory.h"

#include "messages/coordinatespeedtimemessage.h"
#include "messages/mockmessage.h"

MessageFactory::MessageFactory(Type type) :
    type_(type)
{

}

void MessageFactory::setType(Type type)
{
    type_ = type;
}

AbstractMessage* MessageFactory::create()
{
    switch(type_)
    {
    case Type::CoordinateSpeedTime:
        return new CoordinateSpeedTimeMessage();

    case Type::Mock:
        return new MockMessage();

    default:
        return new MockMessage();
    }
}
