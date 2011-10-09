#include "TrayIcon.h"

#include <QMenu>
#include <QAction>

#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "SimpleTimerDialog.h"

TrayIcon::TrayIcon(MainWindow * parent) :
  QSystemTrayIcon(parent),
  m_pTrayIconMenu(new QMenu(parent)),
  m_pSimpleTimerAction(new QAction(tr("Simple Timer"),this)),
  m_pShowWindowAction(new QAction(tr("Show Window"),this)),
  m_pActionQuit(new QAction(tr("&Quit"), this)),
  m_pSimpleTimerDialog(new SimpleTimerDialog(parent))
{
  setIcon(QIcon(":/img/applications-office.png"));

  m_pTrayIconMenu->addAction(m_pSimpleTimerAction);
  m_pTrayIconMenu->addAction(m_pShowWindowAction);
  m_pTrayIconMenu->addAction(m_pActionQuit);

  setContextMenu(m_pTrayIconMenu);

  connect(m_pSimpleTimerAction, SIGNAL(triggered()), m_pSimpleTimerDialog, SLOT(show()));
  connect(m_pShowWindowAction, SIGNAL(triggered()), parent, SLOT(bringUpWindowFromTray()));
  connect(m_pActionQuit, SIGNAL(triggered()), parent, SLOT(on_m_pActionQuit_triggered()));

  connect(this, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), SLOT(trayIconClicked(QSystemTrayIcon::ActivationReason)));
  connect(this, SIGNAL(trayIconActivated()), parent, SLOT(bringUpWindowFromTray()));

  show();
}

void TrayIcon::trayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
  if (QSystemTrayIcon::DoubleClick == reason) {
    emit trayIconActivated();
  }
}
