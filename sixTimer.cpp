/* -*- Mode: C++; tab-width: 20; indent-tabs-mode: nil; c-basic-offset: 2 -*- */

#include "sixTimer.h"

void sixTimer::init(const QTime& timer)
{
  ASixTimer::init(timer);
  _orig_timer = _timer.second() + (_timer.minute() * 60) + (_timer.hour() * 60 * 60);
  _alert = false;
}

void sixTimer::dec(int val)
{
  _timer = _timer.addSecs(val * -1);
}

int sixTimer::getRest() const
{
  return (_timer.second() + (_timer.minute() * 60) + (_timer.hour() * 60 * 60));
}

int sixTimer::getPerc() const
{
  return ((float)((float)getRest() / (float)_orig_timer) * 100);
}

bool sixTimer::getAlert() const
{
  return (_alert);
}

void sixTimer::setAlert(bool val)
{
  _alert = val;
}
