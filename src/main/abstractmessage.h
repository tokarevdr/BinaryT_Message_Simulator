#ifndef ABSTRACTMESSAGE_H
#define ABSTRACTMESSAGE_H

#include<QObject>
#include<QMap>
#include<QString>


    class AbstractMessage
    {
    private:
        static const quint16 kHeaderIdentifier = 0xF157;
        quint8 message_identifier_;
        quint8 informational_part_length_;

    public:
        AbstractMessage(
            quint8 message_identifier,
            quint8 informational_part_length
            );
        virtual quint16 GetCheckSum() const = 0;
        virtual QByteArray FormPackage() const = 0;
        virtual QMap<QString, int> GetFields() const = 0;
        virtual QString GetMessageName() const = 0;
    };


#endif // ABSTRACTMESSAGE_H
