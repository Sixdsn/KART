#ifndef LAUNCHRACE_H
#define LAUNCHRACE_H

#include <QDialog>

namespace Ui {
class LaunchRace;
}

class LaunchRace : public QDialog
{
    Q_OBJECT

public:
    explicit LaunchRace(QWidget *parent = 0);
    ~LaunchRace();

private:
    Ui::LaunchRace *ui;
};

#endif // LAUNCHRACE_H
