#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTimer>
#include <QSharedPointer>

class Timer;

typedef QSharedPointer<Timer> TimerPtr;
/** This class represents a timer that shoots every minute. 
**  It should be exact enough in timing to soot exactly at every full minute. 
**  It's implemented as singleton. */
class Timer : public QTimer
{
  Q_OBJECT
  Q_DISABLE_COPY(Timer)

public:
  /// This method returns a shared pointer to the singleton instance 
  static TimerPtr getInstance();

protected:
    /// The constructor is protected. Ise getINstance() instead.
    Timer();

public:
    virtual ~Timer() {}

private slots:
    /// Calling this slot starts the timer with a timeout of one minute.
    void startMinuteTimer() {start(60 * 1000);}

private:
    //// The singleton object.
    static TimerPtr m_singleton;
};

#endif // TIMER_H
