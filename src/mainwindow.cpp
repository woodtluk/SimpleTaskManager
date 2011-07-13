#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSystemTrayIcon>
#include <QModelIndex>

#include "Task.h"
#include "TaskDialog.h"
#include "TaskListModel.h"
#include "Timer.h"

#include "Config.h"

//#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pTrayIcon(new QSystemTrayIcon(this)),
    m_pTaskListModel(new TaskListModel(this)),
    m_pTaskDialog(new TaskDialog(m_pTaskListModel, this))
{
  ui->setupUi(this);

  setWindowIcon(QIcon(":/img/applications-office.png"));

 // void checkTasksForAlarm();

  ui->m_pListView->setEditTriggers(QAbstractItemView::SelectedClicked | QAbstractItemView::EditKeyPressed);

  connect(ui->m_pListView, SIGNAL(doubleClicked(const QModelIndex&)),SLOT(editTask(const QModelIndex&)));

  ui->m_pListView->setModel(m_pTaskListModel);

  connect(Timer::getInstance().data(), SIGNAL(timeout()), m_pTaskListModel, SLOT(checkTasksForAlarm()));

 /* std::cout << "Version: "
            << APPLICATION_VERSION_MAJOR << "." <<
            APPLICATION_VERSION_MINOR << std::endl;*/
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

    TaskPtr newTask = TaskPtr(new Task());
    m_pTaskListModel->addTask(newTask);

    m_pTaskDialog->toLast();

    /*QDialog::DialogCode*/ int code = m_pTaskDialog->exec();
    if (QDialog::Accepted == code) {
        m_pTaskDialog->submit();
    }
    else
    {
      m_pTaskDialog->revert();
    }
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
  m_pTaskDialog->setCurrentModelIndex(index);
  /*QDialog::DialogCode*/ int code = m_pTaskDialog->exec();
  if (QDialog::Accepted == code) {
    m_pTaskDialog->submit();
    ui->m_pListView->update(index);
  }
  else
  {
    m_pTaskDialog->revert();
  }
}

void MainWindow::showMessage() {
  m_pTrayIcon->setIcon(windowIcon());
  m_pTrayIcon->show();
  m_pTrayIcon->showMessage("Time:", QTime::currentTime().toString(), QSystemTrayIcon::Information);
}

