#include "models/rangecoordinate.h"

RangeCoordinate::RangeCoordinate(int minDistanceInMeters, int maxDistanceInMeters): Coordinates(minDistanceInMeters, maxDistanceInMeters)
{
    this->minDistanceInMeters = minDistanceInMeters;
    this->maxDistanceInMeters = maxDistanceInMeters;

    this->className = "RangeCoordinate";
}

int RangeCoordinate::getMinDistanceInMeters() const
{
    return minDistanceInMeters;
}

void RangeCoordinate::setMinDistanceInMeters(int newMinDistanceInMeters)
{
    minDistanceInMeters = newMinDistanceInMeters;
}

int RangeCoordinate::getMaxDistanceInMeters() const
{
    return maxDistanceInMeters;
}

void RangeCoordinate::setMaxDistanceInMeters(int newMaxDistanceInMeters)
{
    maxDistanceInMeters = newMaxDistanceInMeters;
}
