#ifndef MOCKMESSAGEFIELDS_H
#define MOCKMESSAGEFIELDS_H

#include "imessagefields.h"
#include "utilities/bin16.h"
#include "utilities/bin32.h"

class MockMessageFields : public IMessageFields
{
private :
    quint16 uint16;
    quint32 uint32;
    bin16 bin16;
    bin32 bin32;
    float floatVar;
    double doubleVar;

public:
    MockMessageFields();
    quint8 getRowCount() const override;
    QString getFieldName(quint8 row) const override;
    FieldType getFieldType(quint8 row) const override;
    void setField(quint8 row, QVariant value) override;
};

#endif // MOCKMESSAGEFIELDS_H
