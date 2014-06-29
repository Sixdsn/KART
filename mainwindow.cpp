#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QWebView>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _time_race = ui->timeRaceEdit->time();
    _time_pilot = ui->timePilotEdit->time();
    QWebView *view = new QWebView(ui->WebFrame);
    view->load(QUrl("http://google.com/"));
    view->resize(ui->WebFrame->size());
    view->showMaximized();
}

MainWindow::~MainWindow()
{
    delete ui;
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
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showtime()));
    timer->start(1000);
    on_pushRace_clicked();
    on_pushPilot_clicked();
}

void MainWindow::on_action_Exit_triggered()
{
    QApplication::quit();
}
