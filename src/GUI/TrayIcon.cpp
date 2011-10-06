#include "TrayIcon.h"

TrayIcon::TrayIcon(QObject * parent) :
  QSystemTrayIcon(parent)
{
  setIcon(QIcon(":/img/applications-office.png"));

}
