#include "Timer.h"
#include <QTime>

/// The static singleton instance.
TimerPtr Timer::m_singleton = TimerPtr(NULL);

Timer::Timer()
{
}


TimerPtr Timer::getInstance() {
  if (m_singleton.isNull()) {
    m_singleton = TimerPtr(new Timer());
    QTime currentTime = QTime::currentTime();
    int nMsecToMinute = (60 - currentTime.second()) * 1000;
    QTimer::singleShot(nMsecToMinute, m_singleton.data(), SLOT(startMinuteTimer()));
  }

  return m_singleton;
}
