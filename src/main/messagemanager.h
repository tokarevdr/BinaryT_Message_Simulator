#ifndef MESSAGEMANAGER_H
#define MESSAGEMANAGER_H

#include <memory>

#include <QObject>

#include "abstractmessage.h"

class MessageManager : public QObject
{
public:
    MessageManager();

    static QStringList MessageTypes() {

        QStringList message_types;

        message_types << "Исходные КВ данные (09)";

        return message_types;
    }

private:
    std::unique_ptr<AbstractMessage> current_message;
};

#endif // MESSAGEMANAGER_H
