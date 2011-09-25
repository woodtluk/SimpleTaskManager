#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSystemTrayIcon>
#include <QModelIndex>

#include "Task.h"
#include "TaskDialog.h"
#include "TaskListModel.h"
#include "Timer.h"
#include "SimpleTimerDialog.h"
#include "Config.h"

//#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pTrayIcon(new QSystemTrayIcon(this)),
    m_pTaskListModel(new TaskListModel(this)),
    m_pTaskDialog(new TaskDialog(m_pTaskListModel, this)),
    m_pTrayIconMenu(new QMenu(this)),
    m_pSimpleTimerAction(new QAction(tr("Simple Timer"),this)),
    m_pSimpleTimerDialog(new SimpleTimerDialog(this)),
    m_pSimpleTimer(new QTimer(this))
{
  ui->setupUi(this);

  setWindowIcon(QIcon(":/img/applications-office.png"));

 // void checkTasksForAlarm();

  ui->m_pListView->setEditTriggers(QAbstractItemView::SelectedClicked | QAbstractItemView::EditKeyPressed);

  connect(ui->m_pListView, SIGNAL(doubleClicked(const QModelIndex&)),SLOT(editTask(const QModelIndex&)));

  ui->m_pListView->setModel(m_pTaskListModel);

  connect(Timer::getInstance().data(), SIGNAL(timeout()), m_pTaskListModel, SLOT(checkTasksForAlarm()));

  m_pTrayIcon->setIcon(QIcon(":/img/applications-office.png"));
  m_pTrayIconMenu->addAction(m_pSimpleTimerAction);
  m_pTrayIcon->setContextMenu(m_pTrayIconMenu);
  m_pTrayIcon->show();

  connect(m_pSimpleTimerAction, SIGNAL(triggered()),
          m_pSimpleTimerDialog, SLOT(show()));
  connect(m_pSimpleTimerDialog, SIGNAL(acceptSetTimer(int)), m_pSimpleTimer, SLOT(start(int)));
  connect(m_pSimpleTimerDialog, SIGNAL(rejected()), m_pSimpleTimer, SLOT(stop()));




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


    /*QDialog::DialogCode*/ int code = m_pTaskDialog->addNewTask();

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
  m_pTaskDialog->disableBrowseButtons(false);
  
  /*QDialog::DialogCode*/ int code = m_pTaskDialog->exec();

}

void MainWindow::showMessage() {
  m_pTrayIcon->setIcon(windowIcon());
  m_pTrayIcon->show();
  m_pTrayIcon->showMessage("Time:", QTime::currentTime().toString(), QSystemTrayIcon::Information);
}



