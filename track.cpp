#include "track.h"

Track::Track(qreal id, qreal x, qreal y)
{
    this->id = id;
    this->x = x;
    this->y = y;
    setFlag(ItemIsSelectable);
}

QRectF Track::boundingRect() const
{
    return QRectF(x,y,10,10);
}

void Track::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();

    QPen pen(QColor(150,150,150), 0.1);
    QBrush brush(QColor(150, 150, 150));
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawEllipse(rect);
    if (isSelected())
    {
        painter->setPen(QPen(QColor(235, 155, 52), 2));
        painter->setBrush(Qt::transparent);
        painter->drawRect(QRectF(x - 5, y - 5, 20, 20));
    }
}

qreal Track::getId()
{
    return id;
}

qreal Track::getX()
{
    return x;
}

qreal Track::getY()
{
    return y;
}
