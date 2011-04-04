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

    void setDescription(QString strDescription) {
        m_strTaskDescription = strDescription;
    }

    QString getName() {
        return m_strTaskName;
    }

    void setName(QString strName) {
        m_strTaskName = strName;
    }

    QTime getBeginTime() {
      return m_timeBegin;
    }

    void setBeginTime(QTime time) {
      m_timeBegin = time;
    }

    QTime getDurationTime() {
      return m_timeDuration;
    }

    void setDurationTime(QTime timeDuration) {
      m_timeDuration = timeDuration;
    }

    QTime getAlarmBeforeTaskTime() {
      return m_timeAlarmBeforeTask;
    }

    void setAlarmBeforeTaskTime(QTime time) {
      m_timeAlarmBeforeTask = time;
    }


signals:

public slots:

private:
    QTime m_timeBegin;
    QTime m_timeAlarmBeforeTask;
    QTime m_timeDuration;

    QString m_strTaskName;
    QString m_strTaskDescription;
};

#endif // TASK_H
