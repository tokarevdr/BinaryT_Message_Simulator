#include "abstractmessage.h"

AbstractMessage::AbstractMessage(quint8 message_identifier,
                                 quint8 informational_part_length) :
    message_identifier_(message_identifier),
    informational_part_length_(informational_part_length)
{

}
