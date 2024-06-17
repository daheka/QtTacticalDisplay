#ifndef TRACKINFORMATION_H
#define TRACKINFORMATION_H

#include <QWidget>

namespace Ui {
class TrackInformation;
}

class TrackInformation : public QWidget
{
    Q_OBJECT

public:
    explicit TrackInformation(QWidget *parent = nullptr);
    ~TrackInformation();

private:
    Ui::TrackInformation *ui;
};

#endif // TRACKINFORMATION_H
