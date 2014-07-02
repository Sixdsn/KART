/********************************************************************************
** Form generated from reading UI file 'launchrace.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAUNCHRACE_H
#define UI_LAUNCHRACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_LaunchRace
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *LaunchRace)
    {
        if (LaunchRace->objectName().isEmpty())
            LaunchRace->setObjectName(QStringLiteral("LaunchRace"));
        LaunchRace->resize(194, 85);
        gridLayout = new QGridLayout(LaunchRace);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonBox = new QDialogButtonBox(LaunchRace);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1, Qt::AlignHCenter|Qt::AlignBottom);

        label = new QLabel(LaunchRace);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);


        retranslateUi(LaunchRace);
        QObject::connect(buttonBox, SIGNAL(accepted()), LaunchRace, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LaunchRace, SLOT(reject()));

        QMetaObject::connectSlotsByName(LaunchRace);
    } // setupUi

    void retranslateUi(QDialog *LaunchRace)
    {
        LaunchRace->setWindowTitle(QApplication::translate("LaunchRace", "Dialog", 0));
        label->setText(QApplication::translate("LaunchRace", "Launching Race?", 0));
    } // retranslateUi

};

namespace Ui {
    class LaunchRace: public Ui_LaunchRace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAUNCHRACE_H
