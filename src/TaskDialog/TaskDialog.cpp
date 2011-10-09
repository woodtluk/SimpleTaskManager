#include "TaskDialog.h"
#include "ui_TaskDialog.h"

#include <QDataWidgetMapper>

#include "../Task/Task.h"
#include "../GUI/TaskListModel.h"

#include <QDebug>
#include <QMessageBox>

TaskDialog::TaskDialog(TaskListModel *pModel, QWidget *parent) :
  QDialog(parent),
  ui(new Ui::TaskDialog),
  m_pTaskListModel(pModel),
  m_pDataWidgetMapper(new QDataWidgetMapper(this))
{
  ui->setupUi(this);

  m_pDataWidgetMapper->setModel(pModel);
  setupMapping();
  connect(m_pDataWidgetMapper, SIGNAL(currentIndexChanged(int)),
          this, SLOT(submitAndUpdateButtons(int)));

    /** @todo Converting the combo box to a time and vice versa.
    QTime timeBeforeAlarm;
    bool bOk = false;
    if (timeText.contains(tr("Minute"))) {
      timeText = timeText.remove(tr("Minutes"), Qt::CaseInsensitive);
      // could be only "Minute";
      timeText = timeText.remove(tr("Minute"), Qt::CaseInsensitive);

      timeText  = timeText.trimmed();
      timeBeforeAlarm = QTime(0, timeText.toInt(&bOk));
    }
    else if(timeText.contains(tr("Hour"))) {
      timeText = timeText.remove(tr("Hours"), Qt::CaseInsensitive);
      // could be only "Hour"
      timeText = timeText.remove(tr("Hour"), Qt::CaseInsensitive);

      timeText  = timeText.trimmed();
      timeBeforeAlarm = QTime(timeText.toInt(&bOk), 0);
    }
    else {
      qFatal("could not parse time string");
    }

    Q_ASSERT(bOk);

*/
}

TaskDialog::~TaskDialog()
{
  delete ui;
}

void TaskDialog::setupMapping() {

  m_pDataWidgetMapper->addMapping(ui->m_pLineEditTaskName, 0);
  m_pDataWidgetMapper->addMapping(ui->m_pTextEditTaskDescription, 1);
  m_pDataWidgetMapper->addMapping(ui->m_pTimeEditBegin, 2);
  m_pDataWidgetMapper->addMapping(ui->m_pTimeEditDuration, 3);
  m_pDataWidgetMapper->addMapping(ui->m_pComboBoxAlarmBefore, 4);

  //m_pDataWidgetMapper->setRootIndex(QModelIndex());
  m_pDataWidgetMapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);


  /*connect(m_pDataWidgetMapper, SIGNAL(currentIndexChanged(int)),
          m_pDataWidgetMapper, SLOT(submit()));*/

}

void TaskDialog::disableBrowseButtons(bool disable)
{
  ui->m_pWidgetBrowseButtons->setVisible(!disable);
}

void TaskDialog::on_m_pOkAbbortButtonBox_rejected()
{
  m_pDataWidgetMapper->revert();
  done(QDialog::Rejected);
}


void TaskDialog::on_m_pOkAbbortButtonBox_accepted()
{
  if (ui->m_pLineEditTaskName->text().isEmpty()) {
    QMessageBox::warning(this, "Missing Task Name", "You need to provide at least a name for your task");
    return;
  }

  m_pDataWidgetMapper->submit();
  done(QDialog::Accepted);
}


void TaskDialog::on_m_pButtonFirstTask_clicked()
{
  m_pDataWidgetMapper->submit();
  m_pDataWidgetMapper->toFirst();
}

void TaskDialog::on_m_pButtonPreviousTask_clicked()
{
    m_pDataWidgetMapper->submit();
  m_pDataWidgetMapper->toPrevious();
}

void TaskDialog::on_m_pButtonNextTask_clicked()
{
    m_pDataWidgetMapper->submit();
  m_pDataWidgetMapper->toNext();
}

void TaskDialog::on_m_pButtonLastTask_clicked()
{
    m_pDataWidgetMapper->submit();
  m_pDataWidgetMapper->toLast();
}

int TaskDialog::createNewTask()
{
  TaskPtr newTask = TaskPtr(new Task());
  m_pTaskListModel->addTask(newTask);

  m_pDataWidgetMapper->toLast();
  disableBrowseButtons(true);

  int execResult = exec();
  switch (execResult) {
  case QDialog::Accepted:
    // acept new task data
    m_pDataWidgetMapper->submit();
    break;
  case QDialog::Rejected:
    // delete new added task
    m_pTaskListModel->removeLastTask();
    break;
  }

  return execResult;
}

void TaskDialog::submitAndUpdateButtons(int row)
{
  setFocus();
  m_pDataWidgetMapper->submit();

  ui->m_pButtonFirstTask->setEnabled(row > 0);
  ui->m_pButtonPreviousTask->setEnabled(row > 0);

  ui->m_pButtonNextTask->setEnabled(row < m_pTaskListModel->rowCount() - 1);
  ui->m_pButtonLastTask->setEnabled(row < m_pTaskListModel->rowCount() - 1);
}

void	TaskDialog::setCurrentModelIndex(const QModelIndex &index) {
  m_pDataWidgetMapper->setCurrentModelIndex(index);
}

