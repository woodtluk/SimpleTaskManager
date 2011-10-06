#ifndef TASKLISTMODEL_H
#define TASKLISTMODEL_H

#include <QAbstractListModel>
#include <QList>

#include "../Task/Task.h"

class TaskListModel : public QAbstractItemModel
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

  void removeLastTask() {
    removeRow(m_lstTasks.count() - 1);
  }

  virtual int rowCount(const QModelIndex & parent = QModelIndex()) const;
  virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;

  QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
  virtual Qt::ItemFlags flags ( const QModelIndex & index ) const;

  bool setData(const QModelIndex& index, const QVariant& value, int role=Qt::EditRole);

  const TaskPtr getTask(int index) const;

  bool insertRow ( int row, const QModelIndex & parent = QModelIndex() );
  bool removeRow ( int row, const QModelIndex & parent = QModelIndex() );

  virtual QModelIndex index(int row, int column,
                            const QModelIndex &parent = QModelIndex()) const;
  virtual QModelIndex parent(const QModelIndex &child) const;

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
