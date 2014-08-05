/* -*- Mode: C++; tab-width: 20; indent-tabs-mode: nil; c-basic-offset: 2 -*- */

#include "launchrace.h"
#include "ui_launchrace.h"

LaunchRace::LaunchRace(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::LaunchRace)
{
  ui->setupUi(this);
}

LaunchRace::~LaunchRace()
{
  delete ui;
}
