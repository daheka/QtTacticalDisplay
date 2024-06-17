#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QWidget>
#include <QLabel>

class StatusBar : public QWidget
{
    Q_OBJECT
public:
    explicit StatusBar(QWidget *parent = nullptr);

public slots:
    void updatePosition(QPoint mousePosition);
    void updateZoomLevel(float zoomFactor);

private:
    QLabel *positionLabel;
    QLabel *zoomLabel;
};

#endif // STATUSBAR_H
