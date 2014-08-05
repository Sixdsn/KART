/* -*- Mode: C++; tab-width: 20; indent-tabs-mode: nil; c-basic-offset: 2 -*- */

#include "ASixTimer.h"

void ASixTimer::init(const QTime& timer)
{
  _timer = timer;
}

const QString ASixTimer::toStr() const
{
  return (_timer.toString("hh:mm:ss"));
}
