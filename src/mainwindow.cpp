#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSystemTrayIcon>

#include "Task.h"
#include "TaskDialog.h"
#include "TaskListModel.h"
#include "Timer.h"

#include "Config.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pTrayIcon(new QSystemTrayIcon(this)),
    m_pTaskListModel(new TaskListModel(this))
{
  ui->setupUi(this);

  setWindowIcon(QIcon(":/img/applications-office.png"));

  void checkTasksForAlarm();


  ui->m_pListView->setModel(m_pTaskListModel);

  connect(Timer::getInstance().data(), SIGNAL(timeout()), m_pTaskListModel, SLOT(checkTasksForAlarm()));

  std::cout << "Version: "
            << APPLICATION_VERSION_MAJOR << "." <<
            APPLICATION_VERSION_MINOR << std::endl;
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
    TaskDialog dialog(newTask, this);
    if (QDialog::Accepted == dialog.exec()) {
        /// @todo add task to list
    }
}

void MainWindow::showMessage() {
  m_pTrayIcon->setIcon(windowIcon());
  m_pTrayIcon->show();
  m_pTrayIcon->showMessage("Time:", QTime::currentTime().toString(), QSystemTrayIcon::Information);
}
