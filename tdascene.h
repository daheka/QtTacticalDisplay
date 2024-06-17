#ifndef TDASCENE_H
#define TDASCENE_H

#include <QGraphicsScene>
#include <QMap>
#include "track.h"

class TdaScene : public QGraphicsScene
{
    Q_OBJECT
public:
    TdaScene();
    void addTracks(QList<Track*> trackList);
    void updateTracks();

private:
    QMap<int, Track*> trackMap;
    int bound = 500;

    void generateTracks(int numberOfTracks);
};

#endif // TDASCENE_H
