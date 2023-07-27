#ifndef MESSAGEFACTORY_H
#define MESSAGEFACTORY_H

#include "abstractmessage.h"

class MessageFactory
{
public:
    enum class Type {
        CoordinateSpeedTime,
        Mock
    };

    MessageFactory(Type type);

    void setType(Type type);

    AbstractMessage* create();

private:
    Type type_;
};

#endif // MESSAGEFACTORY_H
