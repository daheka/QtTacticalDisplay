#include "statusbar.h"
#include <QHBoxLayout>

StatusBar::StatusBar(QWidget *parent)
    : QWidget{parent}
{
    positionLabel = new QLabel(QString(""));
    zoomLabel = new QLabel(QString("Zoom: %1").arg(""));
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(positionLabel, 0, Qt::AlignLeft);
    layout->addWidget(zoomLabel, 0, Qt::AlignRight);
    setLayout(layout);
}

void StatusBar::updateZoomLevel(float zoomFactor)
{
    zoomLabel->setText(QString("Zoom: %1").arg(zoomFactor));
}

void StatusBar::updatePosition(QPoint mousePosition)
{
    positionLabel->setText(QString("X: [%1], Y:[%2]")
                               .arg(QString::number(mousePosition.x()), QString::number(mousePosition.y())));
}
