#include "TaskListModel.h"

#include <QMessageBox>

#include "../Timer/Timer.h"
#include "../Task/Task.h"

TaskListModel::TaskListModel(QObject *parent) :
  QAbstractItemModel(parent)
{
#warning Remove this:
  m_lstTasks << TaskPtr(new Task("a")) << TaskPtr(new Task("b"))
             << TaskPtr(new Task("c"))  << TaskPtr(new Task("d")) ;

  int i=3;
  foreach(TaskPtr task, m_lstTasks) {
    task->setBeginTime(QTime(i,1+5));
    i+=2;
  }
}

int TaskListModel::rowCount(const QModelIndex & parent /* = QModelIndex() */) const {
  return m_lstTasks.count();
}

int TaskListModel::columnCount(const QModelIndex &parent /* = QModelIndex() */) const {
  return 5;
}

QVariant TaskListModel::data(const QModelIndex & index, int role /*= Qt::DisplayRole*/) const {
  if (!index.isValid())
    return QVariant();

  if (Qt::DisplayRole == role || Qt::EditRole == role) {
    switch (index.column()) {
    case 0: return m_lstTasks.at(index.row())->getName();
      break;
    case 1: return m_lstTasks.at(index.row())->getDescription();
      break;
    case 2: return m_lstTasks.at(index.row())->getBeginTime();
      break;
    case 3: return m_lstTasks.at(index.row())->getDurationTime();
      break;
    case 4: return m_lstTasks.at(index.row())->getAlarmBeforeTaskTime();
      break;
    default:
      return QVariant();
    } // switch (index.column())
  }

  return QVariant();
}

bool TaskListModel::setData(const QModelIndex& index, const QVariant& value, int role /*=Qt::EditRole*/) {
  if (!index.isValid())
    return false;

  if (Qt::DisplayRole == role || Qt::EditRole == role) {
    TaskPtr task = m_lstTasks.at(index.row());
    switch (index.column()) {
    case 0:  task->setName(value.toString());
             return true;
      break;
    case 1: task->setDescription(value.toString());
            return true;
      break;
    case 2: task->setBeginTime(value.toTime());
            return true;
      break;
    case 3: task->setDurationTime(value.toTime());
            return true;
      break;
    case 4: task->setAlarmBeforeTaskTime(value.toTime());
            return true;
      break;
    default:
      return false;
    } // switch (index.column())
  }

  return false;
}

QModelIndex TaskListModel::index(int row, int column,
                                 const QModelIndex &parent /* = QModelIndex() */) const {
  return createIndex(row, column);
}

QModelIndex TaskListModel::parent(const QModelIndex &child) const {
  return QModelIndex();
}

const TaskPtr TaskListModel::getTask(int index) const {
  return m_lstTasks.at(index);
}

Qt::ItemFlags TaskListModel::flags(const QModelIndex & index) const {
  Q_UNUSED(index);

  return Qt::ItemIsSelectable	| Qt::ItemIsEditable | Qt::ItemIsEnabled;
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
  m_lstTasks.insert(row, m_taskToAdd);
  endInsertRows();

  return true;
}

bool TaskListModel::removeRow ( int row, const QModelIndex & parent /* = QModelIndex() */)
{
  beginRemoveRows(parent, row, row);
  m_lstTasks.removeAt(row);
  endRemoveRows();

  return true;
}
