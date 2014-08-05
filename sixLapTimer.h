/* -*- Mode: C++; tab-width: 20; indent-tabs-mode: nil; c-basic-offset: 2 -*- */

#ifndef SIX_LAP_TIMER
#define SIX_LAP_TIMER

#include "ASixTimer.h"

class sixLapTimer: public ASixTimer
{
public:
  sixLapTimer(): ASixTimer() {}
  virtual ~sixLapTimer() {}
  int getLimit() const;

private:
  sixLapTimer(const sixLapTimer&);
  sixLapTimer& operator=(const sixLapTimer&);
};

#endif
