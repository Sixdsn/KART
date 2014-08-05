/* -*- Mode: C++; tab-width: 20; indent-tabs-mode: nil; c-basic-offset: 2 -*- */

#include "sixLapTimer.h"

int sixLapTimer::getLimit() const
{
  return ((_timer.second() + (_timer.minute() * 60) + (_timer.hour() * 60 * 60)) * 3);
}
