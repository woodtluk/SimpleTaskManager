#include "TaskListView.h"

TaskListView::TaskListView(QWidget *parent) :
    QListView(parent)
{
  /// @todo
  setEditTriggers(QAbstractItemView::SelectedClicked | QAbstractItemView::EditKeyPressed);
#warning todo!
  }
