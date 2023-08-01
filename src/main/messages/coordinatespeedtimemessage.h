#ifndef COORDINATESPEEDTIMEMESSAGE_H
#define COORDINATESPEEDTIMEMESSAGE_H

#include "abstractmessage.h"

#include <QVariant>

#include "utilities/bin16.h"
#include "utilities/bin32.h"

class CoordinateSpeedTimeMessage : public AbstractMessage
{
public:
    CoordinateSpeedTimeMessage();

    virtual quint16 checkSum() const override;
    virtual QByteArray formPackage() const override;

    virtual quint8 rowCount() const override;
    virtual QString fieldName(quint8 row) const override;
    virtual FieldType fieldType(quint8 row) const override;
    virtual bool setField(quint8 row, QVariant value) override;
    virtual QVariant field(quint8 row) const override;

private:
    bin16 readiness_word_;
    bin16 coordinates_systems_signs_;
    quint16 ellipsoid_number_ = 0;
    bin32 date_;
    bin32 time_;
    double latitude_ = 0.;
    double longitude_ = 0.;
    double altitude_ = 0.;
    float speed_latitude_component_ = 0.;
    float speed_longitude_component_ = 0.;
    float speed_altitude_component_ = 0.;
};

#endif // COORDINATESPEEDTIMEMESSAGE_H
