/* -*- Mode: C++; tab-width: 20; indent-tabs-mode: nil; c-basic-offset: 2 -*- */

#ifndef ASIX_TIMER
#define ASIX_TIMER

#include <QTime>
#include <QString>

class ASixTimer
{
public:
  virtual ~ASixTimer() {}
  virtual void init(const QTime&);
  virtual const QString toStr() const;

protected:
  ASixTimer() {}
  QTime _timer;
private:
  ASixTimer(const ASixTimer&);
  ASixTimer& operator=(const ASixTimer&);
};

#endif
