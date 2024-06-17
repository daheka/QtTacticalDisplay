#ifndef TRACK_H
#define TRACK_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

class Track : public QGraphicsItem
{
public:
    Track(qreal id, qreal x, qreal y);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    qreal getId();
    qreal getX();
    qreal getY();

private:
    qreal id;
    qreal x;
    qreal y;
};

#endif // TRACK_H
