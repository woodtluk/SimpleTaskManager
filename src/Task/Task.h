#ifndef TASK_H
#define TASK_H

#include <QTime>
#include <QSharedPointer>
#include <QVariant>

class Task;

typedef QSharedPointer<Task> TaskPtr;

class Task
{

public:
  explicit Task() {};
  explicit Task(QString strName);

  QString getName() const;
  void setName(QString strName);

  QString getDescription() const;
  void setDescription(QString strDescription);

  QTime getBeginTime() const;
  void setBeginTime(QTime time);

  QTime getDurationTime() const;
  void setDurationTime(QTime timeDuration);

  QTime getAlarmBeforeTaskTime() const;
  void setAlarmBeforeTaskTime(QTime time);


private:
  QString m_strTaskName;
  QString m_strTaskDescription;

  QTime m_timeBegin;
  QTime m_timeDuration;
  QTime m_timeAlarmBeforeTask;
};

Q_DECLARE_METATYPE(TaskPtr);

#endif // TASK_H
