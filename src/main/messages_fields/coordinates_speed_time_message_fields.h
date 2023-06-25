#ifndef COORDINATESSPEEDTIMEMESSAGEFIELDS_H
#define COORDINATESSPEEDTIMEMESSAGEFIELDS_H

#include "i_message_fields.h"

namespace message {

class CoordinatesSpeedTimeMessageFields : public IMessageFields
{
public:
    CoordinatesSpeedTimeMessageFields();

    QMap<QString, FieldType> MessageFields() const override;
    void SetFields(QList<QVariant>) override;

private:
    bin16 readness_word_;
    bin16 coordinates_systems_signs_;
    quint16 ellipsoid_number_;
    bin32 date_;
    bin32 time_;
    double latitude_;
    double longitude_;
    double altitude_;
    float speed_latitude_component_;
    float speed_longitude_component_;
    float speed_altitude_component_;
};

} //namespace message

#endif // COORDINATESSPEEDTIMEMESSAGEFIELDS_H
