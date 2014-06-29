#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _time_race = ui->timeRaceEdit->time();
    _time_pilot = ui->timePilotEdit->time();
    _view = new QWebView(ui->WebFrame);
    _view->load(QUrl(ui->LiveEdit->text()));
    _view->resize(ui->WebFrame->size());
    _view->showMaximized();
    _timer = new QTimer(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _view;
    delete _timer;
}

void MainWindow::showtime()
{
    _time_race = _time_race.addSecs(-1);
    ui->lcdRace->display(_time_race.toString("hh:mm:ss"));

    _time_pilot = _time_pilot.addSecs(-1);
    ui->lcdPilot->display(_time_pilot.toString("hh:mm:ss"));
}

void MainWindow::on_pushRace_clicked()
{
    _time_race = ui->timeRaceEdit->time();
    ui->lcdRace->display(_time_race.toString("hh:mm:ss"));
}

void MainWindow::on_pushPilot_clicked()
{
    _time_pilot = ui->timePilotEdit->time();
    ui->lcdPilot->display(_time_pilot.toString("hh:mm:ss"));
}

void MainWindow::on_pushStart_clicked()
{

    connect(_timer, SIGNAL(timeout()), this, SLOT(showtime()));
    _timer->start(1000);
    on_pushRace_clicked();
    on_pushPilot_clicked();
}

void MainWindow::on_action_Exit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_LiveEdit_editingFinished()
{
    _view->load(QUrl(ui->LiveEdit->text()));
    _view->resize(ui->WebFrame->size());
}
