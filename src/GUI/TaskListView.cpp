#include "TaskListView.h"

TaskListView::TaskListView(QWidget *parent) :
    QListView(parent)
{
  setEditTriggers(QAbstractItemView::SelectedClicked | QAbstractItemView::EditKeyPressed);
}
