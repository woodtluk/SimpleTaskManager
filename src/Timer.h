#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTimer>
#include <QSharedPointer>

class Timer;

typedef QSharedPointer<Timer> TimerPtr;

class Timer : public QTimer
{
  Q_OBJECT
  Q_DISABLE_COPY(Timer)

public:
  static TimerPtr getInstance();

private:
    Timer();
public:
    virtual ~Timer() {}
private slots:

    void startMinuteTimer() {start(60 * 1000);}

private:
    static TimerPtr m_singleton;
};

#endif // TIMER_H
