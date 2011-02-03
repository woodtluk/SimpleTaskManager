#include "Task.h"

Task::Task(QObject *parent) :
    QObject(parent)
{
}

Task::Task(QString strName, QObject *parent) :
    QObject(parent),
    m_strTaskName(strName)
{
}
