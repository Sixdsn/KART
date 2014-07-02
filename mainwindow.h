#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QWebView>
#include <QTimer>
#include <QResizeEvent>

#include "launchrace.h"

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

    void on_pushRace_clicked();

    void on_pushPilot_clicked();

    void on_pushFuel_clicked();

    void on_action_Exit_triggered();

    void on_actionStart_Race_triggered();

    void on_LiveEdit_editingFinished();

    void on_StrategyEdit_editingFinished();

private:
    QTime _time_race;
    QTime _time_pilot;
    QTime _time_fuel;
    Ui::MainWindow *ui;
    QWebView *_viewLive;
    QWebView *_viewStrategy;
    QTimer *_timer;
    LaunchRace *_valid_race;
};

#endif // MAINWINDOW_H
