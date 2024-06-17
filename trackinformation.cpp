#include "trackinformation.h"
#include "ui_trackinformation.h"

TrackInformation::TrackInformation(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TrackInformation)
{
    ui->setupUi(this);
}

TrackInformation::~TrackInformation()
{
    delete ui;
}
