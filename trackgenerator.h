#ifndef TRACKGENERATOR_H
#define TRACKGENERATOR_H

#include "track.h"

class TrackGenerator
{
public:
    TrackGenerator(int xBound, int yBound);

    QList<Track*> generateTracks(int amountOfTracks);

private:
    int xBound;
    int yBound;
};

#endif // TRACKGENERATOR_H
