/* -*- Mode: C++; tab-width: 20; indent-tabs-mode: nil; c-basic-offset: 2 -*- */

#ifndef SIX_TIMER
#define SIX_TIMER

#include "ASixTimer.h"

class sixTimer: public ASixTimer
{
public:
  sixTimer(): ASixTimer() {}
  virtual ~sixTimer() {}
  void init(const QTime&);
  void dec(int);
  int getRest() const;
  int getPerc() const;
  bool getAlert() const;
  void setAlert(bool val = true);

private:
  sixTimer(const sixTimer&);
  sixTimer& operator=(const sixTimer&);
  int _orig_timer;
  bool _alert;
};

#endif
