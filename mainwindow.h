#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QWebView>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void showtime();

    void on_pushRace_clicked();

    void on_pushPilot_clicked();

    void on_pushStart_clicked();

    void on_action_Exit_triggered();

    void on_actionStart_Race_triggered();

    void on_LiveEdit_editingFinished();

private:
    QTime _time_race;
    QTime _time_pilot;
    Ui::MainWindow *ui;
    QWebView *_view;
    QTimer *_timer;
};

#endif // MAINWINDOW_H
