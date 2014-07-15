#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _time_lap = ui->timeLapEdit->time();
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
    _origPal = ui->lcdPilot->palette();
    _alertPal = _origPal;
    _alertPal.setColor(QPalette::Normal, QPalette::WindowText, Qt::green);
    _alertPal.setColor(QPalette::Normal, QPalette::Window, Qt::black);
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
    static bool played_pilot_alert = false;
    static bool played_fuel_alert = false;

    int laptime = _time_lap.second() + (_time_lap.minute() * 60) + (_time_lap.hour() * 60 * 60);
    laptime *= 3;

    int rest_pilot = _time_pilot.second() + (_time_pilot.minute() * 60) + (_time_pilot.hour() * 60 * 60);
    int rest_fuel = _time_fuel.second() + (_time_fuel.minute() * 60) + (_time_fuel.hour() * 60 * 60);

    int pilot_perc =  (float)((float)rest_pilot / (float)_orig_pilot) * 100;
    int fuel_perc =  (float)((float)rest_fuel / (float)_orig_fuel) * 100;

    _time_pilot = _time_pilot.addSecs(-1);
    ui->lcdPilot->display(_time_pilot.toString("hh:mm:ss"));
    _time_fuel = _time_fuel.addSecs(-1);
    ui->lcdFuel->display(_time_fuel.toString("hh:mm:ss"));

    ui->progressBarPilot->setValue(pilot_perc);
    ui->progressBarFuel->setValue(fuel_perc);

    if (rest_pilot <= laptime)
    {
        if (!played_pilot_alert)
        {
            QSound::play("/home/six/alert.wav");
            played_pilot_alert = true;
        }
        ui->lcdPilot->setPalette(_alertPal);
    }
    else
        played_pilot_alert = false;
    if (rest_fuel <= laptime)
    {
        if (!played_fuel_alert)
        {
            QSound::play("/home/six/alert.wav");
            played_fuel_alert = true;
        }
        ui->lcdFuel->setPalette(_alertPal);
    }
    else
        played_fuel_alert = false;
}

void MainWindow::on_pushLap_clicked()
{
    _time_lap = ui->timeLapEdit->time();
    ui->lcdLap_2->display(_time_lap.toString("hh:mm:ss"));
}

void MainWindow::on_pushPilot_clicked()
{
    _time_pilot = ui->timePilotEdit->time();
    _orig_pilot = _time_pilot.second() + (_time_pilot.minute() * 60) + (_time_pilot.hour() * 60 * 60);
    ui->lcdPilot->display(_time_pilot.toString("hh:mm:ss"));
    ui->lcdPilot_2->display(_time_pilot.toString("hh:mm:ss"));
    ui->lcdPilot->setPalette(_origPal);
}

void MainWindow::on_pushFuel_clicked()
{
    _time_fuel = ui->timeFuelEdit->time();
    _orig_fuel = _time_fuel.second() + (_time_fuel.minute() * 60) + (_time_fuel.hour() * 60 * 60);
    ui->lcdFuel->display(_time_fuel.toString("hh:mm:ss"));
    ui->lcdFuel_2->display(_time_fuel.toString("hh:mm:ss"));
    ui->lcdFuel->setPalette(_origPal);
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
