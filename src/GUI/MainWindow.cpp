#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSystemTrayIcon>
#include <QModelIndex>
#include <QDebug>
#include <QMessageBox>

#include "../Task/Task.h"
#include "../TaskDialog/TaskDialog.h"
#include "TaskListModel.h"
#include "../Timer/Timer.h"
#include "SimpleTimerDialog.h"
#include "Config.h"


MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  m_pTrayIcon(new QSystemTrayIcon(this)),
  m_pTaskListModel(new TaskListModel(this)),
    m_pTaskDialog(new TaskDialog(m_pTaskListModel, this)),
    m_pTrayIconMenu(new QMenu(this)),
    m_pSimpleTimerAction(new QAction(tr("Simple Timer"),this)),
    m_pShowWindowAction(new QAction(tr("Show Window"),this)),
    m_pSimpleTimerDialog(new SimpleTimerDialog(this))
{
  ui->setupUi(this);

  ui->m_pListView->setModel(m_pTaskListModel);
  connect(ui->m_pListView, SIGNAL(doubleClicked(const QModelIndex&)),SLOT(editTask(const QModelIndex&)));


  setWindowIcon(QIcon(":/img/applications-office.png"));

  // Timer
  connect(Timer::getInstance().data(), SIGNAL(timeout()), m_pTaskListModel, SLOT(checkTasksForAlarm()));

  m_pTrayIcon->setIcon(QIcon(":/img/applications-office.png"));
  m_pTrayIconMenu->addAction(m_pSimpleTimerAction);
  m_pTrayIconMenu->addAction(m_pShowWindowAction);
  m_pTrayIconMenu->addAction(ui->m_pActionQuit);
  m_pTrayIcon->setContextMenu(m_pTrayIconMenu);
  m_pTrayIcon->show();

  connect(m_pSimpleTimerAction, SIGNAL(triggered()),
          m_pSimpleTimerDialog, SLOT(show()));
  connect(m_pShowWindowAction, SIGNAL(triggered()),
          this, SLOT(show()));
  connect(m_pShowWindowAction, SIGNAL(triggered()),
          this, SLOT(rise()));


  connect(Timer::getInstance().data(), SIGNAL(timeout()),
          this, SLOT(minuteTimeout()));

  qDebug() << APPLICATION_VERSION_MAJOR << "." <<
              APPLICATION_VERSION_MINOR;

}

MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::on_m_pActionQuit_triggered()
{
  QCoreApplication::quit();
}

/// @todo handle abborting editing new task
void MainWindow::on_m_pActionAddTask_triggered()
{
  /*QDialog::DialogCode int code = */ m_pTaskDialog->createNewTask();

}

void MainWindow::on_m_pActionRemoveTask_triggered()
{
  QModelIndex index = ui->m_pListView->selectionModel()->currentIndex();
  if(index.isValid())
  {
    m_pTaskListModel->removeTask(index.row());
  }
}

void MainWindow::editTask(const QModelIndex& index) {
  m_pTaskDialog->setCurrentModelIndex(index);
  m_pTaskDialog->disableBrowseButtons(false);

  /*QDialog::DialogCode*/ int code = m_pTaskDialog->exec();

}

void MainWindow::minuteTimeout() {
  for (quint32 i=0; i<m_pTaskListModel->rowCount(); ++i) {
    TaskPtr task = m_pTaskListModel->getTask(i);
    checkIfAlarm(task);
  }
}

void MainWindow::showMessage(QString strName) const {
  m_pTrayIcon->setIcon(windowIcon());
  m_pTrayIcon->show();
  m_pTrayIcon->showMessage("Time:", QTime::currentTime().toString(), QSystemTrayIcon::Information);

  QMessageBox::information(NULL, "Timer elapsed!", strName);
}

void MainWindow::checkIfAlarm(TaskPtr task) const {
  QTime now = QTime::currentTime();
  int  alarmTimeHour = task->getBeginTime().hour() - task->getAlarmBeforeTaskTime().hour();
  int  alarmTimeMin = task->getBeginTime().minute() - task->getAlarmBeforeTaskTime().minute();

  qDebug() << now.hour() << " " << alarmTimeHour << " " << now.minute() << " " << alarmTimeMin;

  if (now.hour() == alarmTimeHour && now.minute() == alarmTimeMin) {
    showMessage(task->getName());
  }
}

void MainWindow::changeEvent(QEvent* e) {
  switch (e->type()) {
    case QEvent::LanguageChange: this->ui->retranslateUi(this);
      break;
    case QEvent::WindowStateChange:
            if (this->windowState() & Qt::WindowMinimized) {
              QTimer::singleShot(250, this, SLOT(hide()));
            }
      break;

    default:
      break;
    } /* switch (e->type()) */

    QMainWindow::changeEvent(e);
}
