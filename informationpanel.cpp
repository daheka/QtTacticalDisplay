#include "informationpanel.h"

#include <QGroupBox>
#include <QVBoxLayout>

InformationPanel::InformationPanel(QWidget *parent)
    : QGroupBox{parent}
{
    setTitle(tr("Track Information"));

    identificationLabel = new QLabel(tr("Identification:"));
    positionLabel = new QLabel(tr("Position:"));
    identityLabel = new QLabel(tr("Identity:"));
    environmentLabel = new QLabel(tr("Environment:"));
    fuseLabel = new QLabel(tr("Fusions:"));

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(identificationLabel);
    vbox->addWidget(positionLabel);
    vbox->addWidget(identityLabel);
    vbox->addWidget(environmentLabel);
    vbox->addWidget(fuseLabel);
    vbox->addStretch(1);
    setLayout(vbox);
}

void InformationPanel::updateTrackInformation(Track *track)
{
    if (track != nullptr) {
        identificationLabel->setText(QString("Identification: %1").arg(track->getId()));
        positionLabel->setText(QString("Position: X:%1, Y:%2")
                                   .arg(QString::number(track->getX()), QString::number(track->getY())));
    }
    else
    {
        identificationLabel->setText(QString("Identification:"));
        positionLabel->setText(QString("Position:"));
    }
}
