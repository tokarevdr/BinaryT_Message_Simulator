#ifndef I_MESSAGE_FIELDS_H
#define I_MESSAGE_FIELDS_H

#include <QString>
#include <QMap>
#include <QVariant>

namespace message {

class IMessageFields
{
public:
    IMessageFields() {};
    virtual ~IMessageFields() {};

    enum class FieldType {
        kDouble,
        kFloat,
        kBin16,
        kBin32,
        kQuint16
    };

    virtual QMap<QString, FieldType> MessageFields() const = 0;
    virtual void SetFields(QList<QVariant>) = 0;
};

} // namespace message

#endif // I_MESSAGE_FIELDS_H
