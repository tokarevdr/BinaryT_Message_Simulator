#ifndef MOCKMESSAGEFIELDS_H
#define MOCKMESSAGEFIELDS_H

#include "imessagefields.h"
#include "utilities/bin16.h"
#include "utilities/bin32.h"

class MockMessageFields : public IMessageFields
{
private :
    quint16 uint16 = 0;
    quint32 uint32 = 0;
    bin16 bin16;
    bin32 bin32;
    float floatVar = 0.;
    double doubleVar = 0.;

public:
    MockMessageFields();
    quint8 getRowCount() const override;
    QString getFieldName(quint8 row) const override;
    FieldType getFieldType(quint8 row) const override;
    bool setField(quint8 row, QVariant value) override;
    QVariant getField(quint8 row) const override;
};

#endif // MOCKMESSAGEFIELDS_H
