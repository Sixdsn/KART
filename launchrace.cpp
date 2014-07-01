#include "launchrace.h"
#include "ui_launchrace.h"

LaunchRace::LaunchRace(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LaunchRace)
{
    ui->setupUi(this);
}

LaunchRace::~LaunchRace()
{
    delete ui;
}
