#ifndef TASKDIALOG_H
#define TASKDIALOG_H

#include <QDialog>
#include<QDataWidgetMapper>

class TaskListModel;

namespace Ui {
class TaskDialog;
}

/// This dialog is used to create and edit tasks.
class TaskDialog : public QDialog
{
  Q_OBJECT

public:
  /// Creates a TaskDialog with a given model.
  explicit TaskDialog(TaskListModel *model, QWidget *parent = 0);
  virtual ~TaskDialog();

  /// Used to create a new task that is imediately shown in the dialog.
  /// @todo Implement this properly. Take special care of aborting when creating a new task.
  int createNewTask();
  /// The browse buttons are needed only when browsing through existing tasks. When a new
  /// task is created the buttons need to be disabled.
  void disableBrowseButtons(bool disable);

public slots:
  /// @todo Implement this properly
  void setCurrentModelIndex(const QModelIndex &index);

private slots:
  void on_m_pOkAbbortButtonBox_accepted();
  void on_m_pOkAbbortButtonBox_rejected();

  void on_m_pButtonFirstTask_clicked();
  void on_m_pButtonPreviousTask_clicked();
  void on_m_pButtonNextTask_clicked();
  void on_m_pButtonLastTask_clicked();

  void submitAndUpdateButtons(int row);

private:
  /// Setup the mapping between the model and the widgets.
  void setupMapping();

private:
  Ui::TaskDialog *ui;

  TaskListModel   * const m_pTaskListModel;
  QDataWidgetMapper * const m_pDataWidgetMapper;

};

#endif // TASKDIALOG_H
