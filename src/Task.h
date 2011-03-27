#ifndef TASK_H
#define TASK_H

#include <QTime>
#include <QSharedPointer>

class Task;

typedef QSharedPointer<Task> TaskPtr;

class Task
{

public:
  explicit Task() {};
  explicit Task(QString strName);


    QString getDescription() {
        return m_strTaskDescription;
    }

    QString getName() {
        return m_strTaskName;
    }

    QTime getBeginTime() {
      return m_timeBegin;
    }

    QTime getAlarmBeforeTaskTime() {
      return m_timeAlarmBeforeTask;
    }


signals:

public slots:

private:
    QTime m_timeBegin;
    QTime m_timeDuration;
    QTime m_timeAlarmBeforeTask;


    QString m_strTaskName;
    QString m_strTaskDescription;
};

#endif // TASK_H
