#ifndef TRAYICON_H
#define TRAYICON_H

#include <QSystemTrayIcon>

class TrayIcon : public QSystemTrayIcon
{
public:
    TrayIcon(QObject * parent = 0);

private:
    QMenu * m_pTrayIconMenu;
    QAction * m_pSimpleTimerAction;
    QAction * m_pShowWindowAction;


};

#endif // TRAYICON_H
