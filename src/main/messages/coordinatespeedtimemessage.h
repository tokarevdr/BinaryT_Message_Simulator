#ifndef COORDINATESPEEDTIMEMESSAGE_H
#define COORDINATESPEEDTIMEMESSAGE_H

#include <abstractmessage.h>

#include "utilities/bin16.h"
#include "utilities/bin32.h"

    class CoordinateSpeedTimeMessage : public AbstractMessage
    {
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
    public:
        CoordinateSpeedTimeMessage();
    };


#endif // COORDINATESPEEDTIMEMESSAGE_H
