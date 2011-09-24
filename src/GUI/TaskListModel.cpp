#include "TaskListModel.h"

#include <QMessageBox>

#include "../Timer/Timer.h"
#include "../Task/Task.h"

TaskListModel::TaskListModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

int TaskListModel::rowCount(const QModelIndex & parent /* = QModelIndex() */) const {
    return m_lstTasks.count();
}

QVariant TaskListModel::data(const QModelIndex & index, int role /*= Qt::DisplayRole*/) const {
    if (!index.isValid())
        return QVariant();

    if (Qt::DisplayRole == role || Qt::EditRole == role) {
        return m_lstTasks.at(index.row())->getName();
    }

    return QVariant();
}


bool TaskListModel::setData(const QModelIndex& index, const QVariant& value, int role /*=Qt::EditRole*/) {
  if (!index.isValid())
      return false;
/// @todo do this properly and take data widget mapper in account
  if (Qt::EditRole == role) {
    m_lstTasks.at(index.row())->setName(value.toString());
  }

  return false;
}

TaskPtr TaskListModel::getTask(int index) const {
  return m_lstTasks.at(index);
}

Qt::ItemFlags TaskListModel::flags ( const QModelIndex & index ) const {
  Q_UNUSED(index);

  return Qt::ItemIsSelectable	| Qt::ItemIsEditable | Qt::ItemIsDragEnabled | Qt::ItemIsEnabled;
}

void TaskListModel::checkTasksForAlarm() {
  QTime currentTime = QTime::currentTime();
  foreach(TaskPtr task, m_lstTasks) {
    if(task->getBeginTime().hour() - task->getAlarmBeforeTaskTime().hour() == currentTime.hour() &&
       task->getBeginTime().minute() - task->getAlarmBeforeTaskTime().minute() == currentTime.minute()) {
      QString st = tr("Alarm");
      QMessageBox::information(0, st, st);//, QMessageBox::Ok,QMessageBox::Ok);
    }
  }
}

bool TaskListModel::insertRow ( int row, const QModelIndex & parent /*= QModelIndex()*/ )
{
  beginInsertRows(parent, row, row);

  m_lstTasks.append(m_taskToAdd);

  endInsertRows();

  return true;
}

bool TaskListModel::removeRow ( int row, const QModelIndex & parent /* = QModelIndex() */)
{
  beginRemoveColumns(parent, row, row);
  m_lstTasks.removeAt(row);
  endRemoveColumns();

  return true;
}
