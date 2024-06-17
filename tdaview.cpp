#include "tdaview.h"

#include <QVBoxLayout>
#include "track.h"

#define VIEW_CENTER viewport()->rect().center()
#define VIEW_WIDTH viewport()->rect().width()
#define VIEW_HEIGHT viewport()->rect().height()

TdaView::TdaView(TdaScene *scene)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setBackgroundBrush(QBrush(QColor(47, 47, 47)));
    setViewportUpdateMode(FullViewportUpdate);
    setRenderHints(QPainter::Antialiasing);
    setMouseTracking(true);

    setMaxSize();
    centerOn(0, 0);
    this->scene = scene;
    setScene(scene);

    zoomDelta = 0.1;
    panSpeed = 10;
    _doMousePanning = false;
    _doKeyZoom = false;
    _scale = 0.1;

    panButton = Qt::RightButton;
    selectButton = Qt::LeftButton;
    zoomKey = Qt::Key_Z;
    resetKey = Qt::Key_R;
}

qreal TdaView::getScale() const
{
    return _scale;
}

void TdaView::keyPressEvent(QKeyEvent * event)
{
    qint32 key = event->key();

    if (key == zoomKey)
    {
        _doKeyZoom = true;
    }

    if (_doKeyZoom)
    {
        if (key == Qt::Key_Up)
        {
            zoomIn();
        }
        else if (key == Qt::Key_Down)
        {
            zoomOut();
        }
    }
    else
    {
        QGraphicsView::keyPressEvent(event);
    }
}

void TdaView::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == zoomKey)
    {
        _doKeyZoom = false;
    }
    else if (event->key() == resetKey)
    {
        resetView();
    }

    QGraphicsView::keyReleaseEvent(event);
}

void TdaView::mouseMoveEvent(QMouseEvent *event)
{
    if (_doMousePanning)
    {
        QPointF mouseDelta = mapToScene(event->pos()) - mapToScene(_lastMousePos);
        pan(mouseDelta);
    }

    QGraphicsView::mouseMoveEvent(event);
    _lastMousePos = event->pos();
    emit mousePositionChanged(mapToScene(event->pos()).toPoint());
}

void TdaView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == panButton)
    {
        _lastMousePos = event->pos();
        _doMousePanning = true;
    }
    else if (event->button() == selectButton)
    {
        QGraphicsItem *item = itemAt(event->pos());
        if (item != nullptr)
        {
            item->setSelected(true);
            item->setZValue(1);
        }
    }

    QGraphicsView::mousePressEvent(event);
}

void TdaView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == panButton)
    {
        _doMousePanning = false;
    }

    QGraphicsView::mouseReleaseEvent(event);
}

void TdaView::wheelEvent(QWheelEvent *event)
{
    QPoint scrollAmount = event->angleDelta();

    scrollAmount.y() > 0 ? zoomIn() : zoomOut();
}

void TdaView::setMaxSize()
{
    setSceneRect(INT_MIN/2, INT_MIN/2, INT_MAX, INT_MAX);
}

void TdaView::resetView()
{
    _scale = 0.1;
    emit zoomChanged(_scale);
    resetTransform();
    centerOn(0, 0);
}

void TdaView::zoom(float scaleFactor)
{
    scale(scaleFactor, scaleFactor);

    _scale *= scaleFactor;

    emit zoomChanged(_scale);
}

void TdaView::zoomIn()
{
    zoom(1 + zoomDelta);
}

void TdaView::zoomOut()
{
    zoom(1 - zoomDelta);
}

void TdaView::pan(QPointF delta)
{
    delta *= _scale;
    delta *= panSpeed;

    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    QPoint newCenter(VIEW_WIDTH / 2 - delta.x(), VIEW_HEIGHT / 2 - delta.y());
    centerOn(mapToScene(newCenter));

    setTransformationAnchor(QGraphicsView::AnchorViewCenter);
}
