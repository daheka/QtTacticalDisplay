#ifndef INFORMATIONPANEL_H
#define INFORMATIONPANEL_H

#include <QGroupBox>
#include <QLabel>
#include "track.h"

class InformationPanel : public QGroupBox
{
    Q_OBJECT
public:
    explicit InformationPanel(QWidget *parent = nullptr);

    void updateTrackInformation(Track *track);

private:
    QLabel *identificationLabel;
    QLabel *positionLabel;
    QLabel *identityLabel;
    QLabel *environmentLabel;
    QLabel *fuseLabel;
};

#endif // INFORMATIONPANEL_H
