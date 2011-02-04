#ifndef TASKLISTMODEL_H
#define TASKLISTMODEL_H

#include <QAbstractListModel>
#include <QList>

#include "Task.h"

class TaskListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit TaskListModel(QObject *parent = 0);
    ~TaskListModel() {};
signals:

public slots:

private:
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;

private:
    QList<TaskPtr> m_lstTasks;
};

#endif // TASKLISTMODEL_H
