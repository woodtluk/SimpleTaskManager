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

    void addTask(TaskPtr task) {
      m_taskToAdd = task;
      insertRow(m_lstTasks.count());
      reset();  ///< @todo Use beginResetModel() and endResetModel() instead
    }

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;

    bool insertRow ( int row, const QModelIndex & parent = QModelIndex() );
    bool removeRow ( int row, const QModelIndex & parent = QModelIndex() );


signals:

public slots:
  void checkTasksForAlarm();
private:

private slots:

private:
    QList<TaskPtr> m_lstTasks;
    TaskPtr m_taskToAdd;
};

#endif // TASKLISTMODEL_H
