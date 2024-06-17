#ifndef TDAVIEW_H
#define TDAVIEW_H

#include <QGraphicsView>
#include <QWheelEvent>
#include <QKeyEvent>
#include <QLabel>
#include "tdascene.h"

class TdaView : public QGraphicsView
{
    Q_OBJECT
public:
    TdaView(TdaScene *scene);

    qreal panSpeed;
    qreal zoomDelta;
    qreal zoomKey;
    qreal resetKey;
    Qt::MouseButton panButton;
    Qt::MouseButton selectButton;

    void pan(QPointF delta);
    void zoom(float scaleFactor);
    void zoomIn();
    void zoomOut();

    qreal getScale() const;

signals:
    void mousePositionChanged(QPoint mousePosition);
    void zoomChanged(float zoomFactor);

protected:

    void keyPressEvent(QKeyEvent*) override;
    void keyReleaseEvent(QKeyEvent*) override;

    void mouseMoveEvent(QMouseEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void wheelEvent(QWheelEvent*) override;

private:

    TdaScene *scene;
    bool _doMousePanning;
    bool _doKeyZoom;

    QPoint _lastMousePos;
    qreal _scale;

    void setMaxSize();
    void resetView();
};

#endif // TDAVIEW_H
