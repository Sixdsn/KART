/* -*- Mode: C++; tab-width: 20; indent-tabs-mode: nil; c-basic-offset: 2 -*- */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QWebView>
#include <QTimer>
#include <QResizeEvent>
#include <QSound>

#include "launchrace.h"
#include "sixtimer.h"
#define ALERT_SOUND "./assets/alert.wav"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  void resizeEvent(QResizeEvent *event);

private slots:
  void showtime();
  void on_pushPilot_clicked();
  void on_pushFuel_clicked();
  void on_action_Exit_triggered();
  void on_actionStart_Race_triggered();
  void on_LiveEdit_editingFinished();
  void on_StrategyEdit_editingFinished();
  void on_pushLap_clicked();
  void on_line1Edit_editingFinished();
  void on_line2Edit_editingFinished();
  void on_line3Edit_editingFinished();
  void on_PolicySlider_valueChanged(int value);
  void on_checkBoxLine2_clicked(bool checked);
  void on_checkBoxLine3_clicked(bool checked);

private:
  SixTimer _pilot;
  SixTimer _fuel;
  SixTimer _lap;
  QPalette _origPal;
  QPalette _alertPal;
  Ui::MainWindow *ui;
  QWebView *_viewLive;
  QWebView *_viewStrategy;
  QTimer *_timer;
};

#endif // MAINWINDOW_H
