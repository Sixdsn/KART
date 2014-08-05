/* -*- Mode: C++; tab-width: 20; indent-tabs-mode: nil; c-basic-offset: 2 -*- */

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  _viewLive(),
  _viewStrategy(),
  _timer(this)
{
  ui->setupUi(this);
  _lap.init(ui->timeLapEdit->time());
  _pilot.init(ui->timePilotEdit->time());
  _fuel.init(ui->timeFuelEdit->time());
  _viewLive.setParent(ui->WebFrameLive);
  _viewLive.load(QUrl(ui->LiveEdit->text()));
  _viewLive.resize(ui->WebFrameLive->size());
  _viewLive.showMaximized();
  _viewStrategy.setParent(ui->WebFrameStrategy);
  _viewStrategy.load(QUrl(ui->LiveEdit->text()));
  _viewStrategy.resize(ui->WebFrameStrategy->size());
  _viewStrategy.showMaximized();
  connect(&_timer, SIGNAL(timeout()), this, SLOT(showtime()));
  _origPal = ui->lcdPilot->palette();
  _alertPal = _origPal;
  _alertPal.setColor(QPalette::Normal, QPalette::WindowText, Qt::green);
  _alertPal.setColor(QPalette::Normal, QPalette::Window, Qt::black);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
  _viewLive.resize(event->size());
  _viewStrategy.resize(event->size());
}

void MainWindow::showtime()
{
  _pilot.dec(1);
  _fuel.dec(1);

  ui->lcdPilot->display(_pilot.toStr());
  ui->lcdFuel->display(_fuel.toStr());

  ui->progressBarPilot->setValue(_pilot.getPerc());
  ui->progressBarFuel->setValue(_fuel.getPerc());

  if (_pilot.getRest() <= _lap.getLimit())
    {
      if (!_pilot.getAlert())
        {
          QSound::play(ALERT_SOUND);
          _pilot.setAlert();
        }
      ui->lcdPilot->setPalette(_alertPal);
    }
  if (_fuel.getRest() <= _lap.getLimit())
    {
      if (!_fuel.getAlert())
        {
          QSound::play(ALERT_SOUND);
          _fuel.setAlert();
        }
      ui->lcdFuel->setPalette(_alertPal);
    }
}

void MainWindow::on_pushLap_clicked()
{
  _lap.init(ui->timeLapEdit->time());
  ui->lcdLap_2->display(_lap.toStr());
}

void MainWindow::on_pushPilot_clicked()
{
  _pilot.init(ui->timePilotEdit->time());
  ui->lcdPilot->display(_pilot.toStr());
  ui->lcdPilot_2->display(_pilot.toStr());
  ui->lcdPilot->setPalette(_origPal);
}

void MainWindow::on_pushFuel_clicked()
{
  _fuel.init(ui->timeFuelEdit->time());
  ui->lcdFuel->display(_fuel.toStr());
  ui->lcdFuel_2->display(_fuel.toStr());
  ui->lcdFuel->setPalette(_origPal);
}

void MainWindow::on_action_Exit_triggered()
{
  this->close();
}

void MainWindow::on_actionStart_Race_triggered()
{
  LaunchRace valid_race(this);

  valid_race.show();
  if (valid_race.exec() == QDialog::Accepted)
    {
      _timer.start(1000);
      on_pushPilot_clicked();
      on_pushFuel_clicked();
    }
}

void MainWindow::on_LiveEdit_editingFinished()
{
  _viewLive.load(QUrl(ui->LiveEdit->text()));
  _viewLive.showMaximized();
}

void MainWindow::on_StrategyEdit_editingFinished()
{
  _viewStrategy.load(QUrl(ui->StrategyEdit->text()));
  _viewStrategy.showMaximized();
}

void MainWindow::on_line1Edit_editingFinished()
{
  ui->labelLine1->setText(ui->line1Edit->text());
}

void MainWindow::on_line2Edit_editingFinished()
{
  ui->labelLine2->setText(ui->line2Edit->text());
}

void MainWindow::on_line3Edit_editingFinished()
{
  ui->labelLine3->setText(ui->line3Edit->text());
}

void MainWindow::on_PolicySlider_valueChanged(int value)
{
  QFont font;

  font.setPointSize(value);
  font.setBold(true);
  font.setWeight(75);

  ui->labelLine1->setFont(font);
  ui->labelLine2->setFont(font);
  ui->labelLine3->setFont(font);
}

void MainWindow::on_checkBoxLine2_clicked(bool checked)
{
  if (!checked)
    ui->labelLine2->hide();
  else
    ui->labelLine2->showMaximized();
}

void MainWindow::on_checkBoxLine3_clicked(bool checked)
{
  if (!checked)
    ui->labelLine3->hide();
  else
    ui->labelLine3->showMaximized();
}
