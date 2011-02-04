#include "TaskListModel.h"

TaskListModel::TaskListModel(QObject *parent) :
    QAbstractListModel(parent)
{
    for (int i=0; i<5; i++)
        m_lstTasks.append(TaskPtr(new Task(QString::number(i))));
}

int TaskListModel::rowCount(const QModelIndex & parent /* = QModelIndex() */) const {
    return m_lstTasks.count();
}

QVariant TaskListModel::data(const QModelIndex & index, int role /*= Qt::DisplayRole*/) const {
    if (!index.isValid())
        return QVariant();

    if (Qt::DisplayRole == role) {
        return m_lstTasks.at(index.row())->getName();
    }

    return QVariant();

}
