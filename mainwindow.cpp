#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSystemTrayIcon>

#include "TaskDialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pTaskDialog(new TaskDialog(this)),
    trayIcon(new QSystemTrayIcon(this))
{
    ui->setupUi(this);

    m_pTaskDialog->show();

    trayIcon->setIcon(QIcon(":/img/applications-office.png"));
    trayIcon->show();
    trayIcon->showMessage("text", "blabla", QSystemTrayIcon::Information);
}

MainWindow::~MainWindow()
{
    delete ui;
}
