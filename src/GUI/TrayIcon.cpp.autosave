#include "TrayIcon.h"

TrayIcon::TrayIcon(QObject * parent) :
  QSystemTrayIcon(parent),
  m_pTrayIconMenu(new QMenu(this)),
  m_pSimpleTimerAction(new QAction(this)),
  m_pShowWindowAction(new QAction(this))
{
  setIcon(QIcon(":/img/applications-office.png"));

  m_pTrayIconMenu->addAction(m_pSimpleTimerAction);
  m_pTrayIconMenu->addAction(m_pShowWindowAction);
  m_pTrayIconMenu->addAction(ui->m_pActionQuit);

  m_pTrayIcon->setContextMenu(m_pTrayIconMenu);
}
