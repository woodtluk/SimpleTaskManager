#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QTime>
#include <QSharedPointer>

class Task;

typedef QSharedPointer<Task> TaskPtr;

class Task : public QObject
{
    Q_OBJECT
public:
    explicit Task(QObject *parent = 0);

signals:

public slots:

private:
    QTime m_timeBegin;
    QTime m_timeDuration;

    QString m_strTaskName;
    QString m_strTaskDescription;
};

#endif // TASK_H
