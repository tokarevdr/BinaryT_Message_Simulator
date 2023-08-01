#ifndef MOCKMESSAGE_H
#define MOCKMESSAGE_H

#include "abstractmessage.h"

#include <QVariant>

#include "utilities/bin16.h"
#include "utilities/bin32.h"

class MockMessage : public AbstractMessage
{
public:
    MockMessage();

    virtual quint16 checkSum() const override;
    virtual QByteArray formPackage() const override;

    virtual quint8 rowCount() const override;
    virtual QString fieldName(quint8 row) const override;
    virtual FieldType fieldType(quint8 row) const override;
    virtual bool setField(quint8 row, QVariant value) override;
    virtual QVariant field(quint8 row) const override;

private :
    quint16 uint16 = 0;
    quint32 uint32 = 0;
    bin16 bin_16;
    bin32 bin_32;
    float floatVar = 0.;
    double doubleVar = 0.;
};

#endif // MOCKMESSAGE_H
