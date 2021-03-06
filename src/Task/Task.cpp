#include "Task.h"


Task::Task(QString strName) :
  m_strTaskName(strName)
{
}

QString Task::getName() const {
  return m_strTaskName;
}

void Task::setName(QString strName) {
  m_strTaskName = strName;
}

QString Task::getDescription() const {
  return m_strTaskDescription;
}

void Task::setDescription(QString strDescription) {
  m_strTaskDescription = strDescription;
}

QTime Task::getBeginTime() const {
  return m_timeBegin;
}

void Task::setBeginTime(QTime time) {
  m_timeBegin = time;
}

QTime Task::getDurationTime() const {
  return m_timeDuration;
}

void Task::setDurationTime(QTime timeDuration) {
  m_timeDuration = timeDuration;
}

QTime Task::getAlarmBeforeTaskTime() const {
  return m_timeAlarmBeforeTask;
}

void Task::setAlarmBeforeTaskTime(QTime time) {
  m_timeAlarmBeforeTask = time;
}

