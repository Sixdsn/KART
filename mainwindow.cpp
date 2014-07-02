#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _time_race = ui->timeRaceEdit->time();
    _time_pilot = ui->timePilotEdit->time();
    _time_fuel = ui->timeFuelEdit->time();
    _viewLive = new QWebView(ui->WebFrameLive);
    _viewLive->load(QUrl(ui->LiveEdit->text()));
    _viewLive->resize(ui->WebFrameLive->size());
    _viewLive->showMaximized();
    _viewStrategy = new QWebView(ui->WebFrameStrategy);
    _viewStrategy->load(QUrl(ui->LiveEdit->text()));
    _viewStrategy->resize(ui->WebFrameStrategy->size());
    _viewStrategy->showMaximized();
    _timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(showtime()));
    _valid_race = new LaunchRace(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _viewLive;
    delete _viewStrategy;
    delete _timer;
    delete _valid_race;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    _viewLive->resize(event->size());
    _viewStrategy->resize(event->size());
}

void MainWindow::showtime()
{
    _time_race = _time_race.addSecs(-1);
    ui->lcdRace->display(_time_race.toString("hh:mm:ss"));
    _time_pilot = _time_pilot.addSecs(-1);
    ui->lcdPilot->display(_time_pilot.toString("hh:mm:ss"));
    _time_fuel = _time_fuel.addSecs(-1);
    ui->lcdFuel->display(_time_fuel.toString("hh:mm:ss"));
}

void MainWindow::on_pushRace_clicked()
{
    _time_race = ui->timeRaceEdit->time();
    ui->lcdRace->display(_time_race.toString("hh:mm:ss"));
    ui->lcdRace_2->display(_time_race.toString("hh:mm:ss"));
}

void MainWindow::on_pushPilot_clicked()
{
    _time_pilot = ui->timePilotEdit->time();
    ui->lcdPilot->display(_time_pilot.toString("hh:mm:ss"));
    ui->lcdPilot_2->display(_time_pilot.toString("hh:mm:ss"));
}

void MainWindow::on_pushFuel_clicked()
{
    _time_fuel = ui->timeFuelEdit->time();
    ui->lcdFuel->display(_time_fuel.toString("hh:mm:ss"));
    ui->lcdFuel_2->display(_time_fuel.toString("hh:mm:ss"));
}

void MainWindow::on_action_Exit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionStart_Race_triggered()
{
    _valid_race->show();
    if( _valid_race->exec() == QDialog::Accepted )
    {
        _timer->start(1000);
        on_pushRace_clicked();
        on_pushPilot_clicked();
        on_pushFuel_clicked();
    }
}

void MainWindow::on_LiveEdit_editingFinished()
{
    _viewLive->load(QUrl(ui->LiveEdit->text()));
    _viewLive->resize(ui->WebFrameStrategy->size());
}

void MainWindow::on_StrategyEdit_editingFinished()
{
    _viewStrategy->load(QUrl(ui->StrategyEdit->text()));
    _viewStrategy->resize(ui->WebFrameStrategy->size());
}
