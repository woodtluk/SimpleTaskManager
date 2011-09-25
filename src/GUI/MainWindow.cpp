#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSystemTrayIcon>
#include <QModelIndex>
#include <QDebug>

#include "../Task/Task.h"
#include "../TaskDialog/TaskDialog.h"
#include "TaskListModel.h"
#include "../Timer/Timer.h"

#include "Config.h"


MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  m_pTrayIcon(new QSystemTrayIcon(this)),
  m_pTaskListModel(new TaskListModel(this)),
  m_pTaskDialog(new TaskDialog(m_pTaskListModel, this))
{
  ui->setupUi(this);

  ui->m_pListView->setModel(m_pTaskListModel);
  connect(ui->m_pListView, SIGNAL(doubleClicked(const QModelIndex&)),SLOT(editTask(const QModelIndex&)));


  setWindowIcon(QIcon(":/img/applications-office.png"));

  // Timer
  connect(Timer::getInstance().data(), SIGNAL(timeout()), m_pTaskListModel, SLOT(checkTasksForAlarm()));

  qDebug() << "Version: "
           << APPLICATION_VERSION_MAJOR << "." <<
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

void MainWindow::on_m_pActionAddTask_triggered()
{
#warning Fix this
  qWarning("Isnt Working yet");
  /// @todo isn't working yet
  /*QDialog::DialogCode*/ int code = m_pTaskDialog->createNewTask();

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
  /// @todo addapt this to the task dialog with data mapper
#warning Fix this
  qWarning("Isnt Working yet");
  /// @todo isn't working yet
  m_pTaskDialog->setCurrentModelIndex(index);
  m_pTaskDialog->disableBrowseButtons(false);
  
  /*QDialog::DialogCode*/ int code = m_pTaskDialog->exec();

}

void MainWindow::showMessage() {
  m_pTrayIcon->setIcon(windowIcon());
  m_pTrayIcon->show();
  m_pTrayIcon->showMessage("Time:", QTime::currentTime().toString(), QSystemTrayIcon::Information);
}

