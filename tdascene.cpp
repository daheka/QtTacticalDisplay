#include "tdascene.h"

#include <QGraphicsEllipseItem>
#include <QRandomGenerator64>
#include <QMap>
#include "track.h"

TdaScene::TdaScene()
{
}

void TdaScene::addTracks(QList<Track*> trackList)
{
    while (!trackList.isEmpty())
    {
        Track *track = trackList.takeFirst();
        trackMap.insert(track->getId(), track);
        addItem(track);
    }
}

void TdaScene::updateTracks()
{
    QMapIterator<int, Track*> i(trackMap);
    while (i.hasNext()) {
        i.next();
        i.value()->setX(QRandomGenerator::global()->bounded(-bound, bound));
        i.value()->setY(QRandomGenerator::global()->bounded(-bound, bound));
    }
}
