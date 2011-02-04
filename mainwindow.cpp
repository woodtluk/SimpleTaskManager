#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSystemTrayIcon>

#include "Task.h"
#include "TaskDialog.h"
#include "TaskListModel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    trayIcon(new QSystemTrayIcon(this))
{
    ui->setupUi(this);

    setWindowIcon(QIcon(":/img/applications-office.png"));

    ui->m_pListView->setModel(new TaskListModel(this));

    trayIcon->setIcon(windowIcon());
    trayIcon->show();
    trayIcon->showMessage("text", "blabla", QSystemTrayIcon::Information);
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
