#include "TaskDialog.h"
#include "ui_TaskDialog.h"

#include <QDataWidgetMapper>

#include "Task.h"
#include "TaskListModel.h"

#include <QDebug>

TaskDialog::TaskDialog(TaskListModel *pModel, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskDialog),
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

void TaskDialog::on_m_pOkAbbortButtonBox_rejected()
{
  done(QDialog::Rejected);
}

void TaskDialog::on_m_pOkAbbortButtonBox_accepted()
{
  /// @todo use data mapper
  /*m_pTask->setName(ui->m_pLineEditTaskName->text());
  m_pTask->setDescription(ui->m_pTextEditTaskDescription->document()->toPlainText());

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
  done(QDialog::Accepted);
}
