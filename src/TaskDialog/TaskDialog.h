#ifndef TASKDIALOG_H
#define TASKDIALOG_H

#include <QDialog>
#include<QDataWidgetMapper>

class TaskListModel;

namespace Ui {
class TaskDialog;
}

class TaskDialog : public QDialog
{
  Q_OBJECT

public:
  explicit TaskDialog(TaskListModel *model, QWidget *parent = 0);
  virtual ~TaskDialog();

  int createNewTask();
  void disableBrowseButtons(bool disable);

public slots:
  void setCurrentModelIndex(const QModelIndex &index);

private slots:
  void on_m_pOkAbbortButtonBox_accepted();
  void on_m_pOkAbbortButtonBox_rejected();

  void on_m_pButtonFirstTask_clicked();
  void on_m_pButtonPreviousTask_clicked();
  void on_m_pButtonNextTask_clicked();
  void on_m_pButtonLastTask_clicked();

  void updateButtons(int row);

private:
  void setupMapping();

private:
  Ui::TaskDialog *ui;

  TaskListModel   * const m_pTaskListModel;
  QDataWidgetMapper * const m_pDataWidgetMapper;

};

#endif // TASKDIALOG_H
