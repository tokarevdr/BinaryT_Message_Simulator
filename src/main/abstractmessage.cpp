#include "abstractmessage.h"

message::AbstractMessage::AbstractMessage(
    quint8 message_identifier,
    quint8 informational_part_length,
    quint8 check_sum
    )
{
    message_identifier_ = message_identifier;
    informational_part_length_ = informational_part_length;
    check_sum_ = check_sum;
}
