#ifndef RANGECOORDINATE_H
#define RANGECOORDINATE_H

#include "models/coordinates.h"

class RangeCoordinate : public Coordinates
{
    Q_OBJECT
public:
    RangeCoordinate(int minDistanceInMeters, int maxDistanceInMeters);

    int getMinDistanceInMeters() const;
    void setMinDistanceInMeters(int newMinDistanceInMeters);

    int getMaxDistanceInMeters() const;
    void setMaxDistanceInMeters(int newMaxDistanceInMeters);

private:
    int minDistanceInMeters;
    int maxDistanceInMeters;

signals:

};

#endif // RANGECOORDINATE_H
