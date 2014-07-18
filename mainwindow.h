#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QWebView>
#include <QTimer>
#include <QResizeEvent>
#include <QSound>

#include "launchrace.h"

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

private:
    QTime _time_pilot;
    QTime _time_fuel;
    QTime _time_lap;
    int _orig_pilot;
    int _orig_fuel;
    QPalette _origPal;
    QPalette _alertPal;
    Ui::MainWindow *ui;
    QWebView *_viewLive;
    QWebView *_viewStrategy;
    QTimer *_timer;
    LaunchRace *_valid_race;
};

#endif // MAINWINDOW_H
