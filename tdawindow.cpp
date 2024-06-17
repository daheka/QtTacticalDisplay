#include "tdawindow.h"

#include <QGridLayout>
#include <QTimer>

TdaWindow::TdaWindow()
{
    tdaScene = new TdaScene;
    tdaView = new TdaView(tdaScene);
    statusBar = new StatusBar();
    statusBar->updateZoomLevel(tdaView->getScale());

    timer = new QTimer();
    timer->setInterval(1000 / 30);
    // connect(timer, &QTimer::timeout, this, [=]() {
    //     tdaScene->updateTracks();
    // });
    // timer->start();

    QObject::connect(tdaView, &TdaView::zoomChanged, statusBar, &StatusBar::updateZoomLevel);
    QObject::connect(tdaView, &TdaView::mousePositionChanged, statusBar, &StatusBar::updatePosition);

    informationPanel = new InformationPanel(this);

    // QObject::connect(tdaScene, &TdaScene::selectionChanged, informationPanel, &InformationPanel::updateTrackInformation);

    setupUi();
}

TdaWindow::~TdaWindow()
{
    disconnect(timer);
}

void TdaWindow::addTracks(QList<Track*> trackList)
{
    tdaScene->addTracks(trackList);
}

void TdaWindow::setupUi()
{
    QGridLayout *grid = new QGridLayout();
    grid->addWidget(tdaView, 0, 0, 0, 3);
    grid->addWidget(statusBar, 1, 0, 1, 3, Qt::AlignBottom);
    grid->addWidget(informationPanel, 0, 4, 0, 1);
    setLayout(grid);
    setWindowTitle("Tactical Display Area");
    resize(1280, 1024);
}
