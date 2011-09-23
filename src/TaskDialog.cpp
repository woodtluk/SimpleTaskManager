#include "TaskDialog.h"
#include "ui_TaskDialog.h"

#include <QDataWidgetMapper>

#include "Task.h"
#include "TaskListModel.h"

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

    //ui->m_pLineEditTaskName->setText(m_pTask->getName());
    /** @todo ui->m_pTextEditTaskDescription->document()->set;

    m_pTask->setBeginTime(ui->m_pTimeEditBegin->time());

    QString timeText = ui->m_pComboBoxAlarmBefore->currentText();
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


    m_pTask->setAlarmBeforeTaskTime(timeBeforeAlarm);

    m_pTask->setDurationTime(ui->m_pTimeEditDuration->time());



    */
}

TaskDialog::~TaskDialog()
{
    delete ui;
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
    m_pDataWidgetMapper->toFirst();
}

void TaskDialog::on_m_pButtonPreviousTask_clicked()
{
    m_pDataWidgetMapper->toPrevious();
}

void TaskDialog::on_m_pButtonNextTask_clicked()
{
    m_pDataWidgetMapper->toNext();
}

void TaskDialog::on_m_pButtonLastTask_clicked()
{
    m_pDataWidgetMapper->toLast();
}

int TaskDialog::addNewTask()
{
    TaskPtr newTask = TaskPtr(new Task());
    m_pTaskListModel->addTask(newTask);

    m_pDataWidgetMapper->toLast();
    disableBrowseButtons(true);

    return exec();


}
