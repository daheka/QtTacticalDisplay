#ifndef TDAWINDOW_H
#define TDAWINDOW_H

#include <QWidget>
#include "tdaview.h"
#include "tdascene.h"
#include "statusbar.h"
#include "informationpanel.h"

class TdaWindow : public QWidget
{
    Q_OBJECT

public:
    TdaWindow();
    ~TdaWindow();

    void addTracks(QList<Track*> trackList);

private:
    void setupUi();

private:
    QTimer *timer;
    TdaScene *tdaScene;
    TdaView *tdaView;
    StatusBar *statusBar;
    InformationPanel *informationPanel;
};
#endif // TDAWINDOW_H
