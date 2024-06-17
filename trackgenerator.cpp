#include "trackgenerator.h"
#include <QRandomGenerator64>

TrackGenerator::TrackGenerator(int xBound, int yBound) {
    this->xBound = xBound;
    this->yBound = yBound;
}

QList<Track*> TrackGenerator::generateTracks(int amountOfTracks)
{
    QList<Track*> trackList;
    for(int i = 0; i < amountOfTracks; i++)
    {
        int x = QRandomGenerator::global()->bounded(-xBound, yBound);
        int y = QRandomGenerator::global()->bounded(-xBound, yBound);
        Track *track = new Track(i, x, y);
        trackList.append(track);
    }
    return trackList;
}
