#include <QApplication>
#include "tdawindow.h"
#include "trackgenerator.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TdaWindow window;
    TrackGenerator trackGenerator(500, 500);
    window.addTracks(trackGenerator.generateTracks(1000));;
    window.show();
    return app.exec();
}
