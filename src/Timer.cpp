#include "Timer.h"

TimerPtr Timer::m_singleton = TimerPtr(NULL);

Timer::Timer()
{

}


TimerPtr Timer::getInstance() {
  if (m_singleton.isNull()) {
    m_singleton = TimerPtr(new Timer());
  }

  return m_singleton;
}
