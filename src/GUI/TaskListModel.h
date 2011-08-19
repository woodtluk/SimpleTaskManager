#ifndef TASKLISTMODEL_H
#define TASKLISTMODEL_H

#include <QAbstractListModel>
#include <QList>

#include "../Task/Task.h"

class TaskListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit TaskListModel(QObject *parent = 0);
    virtual ~TaskListModel() {};

    void addTask(TaskPtr task) {
      beginResetModel();
      m_taskToAdd = task;
      insertRow(m_lstTasks.count());
      endResetModel();
    }

    void removeTask(int row)
    {
     removeRow(row);
    }

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
   // bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags ( const QModelIndex & index ) const;

    bool setData(const QModelIndex& index, const QVariant& value, int role=Qt::EditRole);

    TaskPtr getTask(int index) const;

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
