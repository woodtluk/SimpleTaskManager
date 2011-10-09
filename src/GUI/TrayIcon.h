#ifndef TRAYICON_H
#define TRAYICON_H

#include <QSystemTrayIcon>

class MainWindow;

class SimpleTimerDialog;
class QAction;


class TrayIcon : public QSystemTrayIcon
{
  Q_OBJECT

public:
  TrayIcon(MainWindow * parent = 0);

signals:
  void trayIconActivated();

private slots:
  void trayIconClicked(QSystemTrayIcon::ActivationReason reason);

private:
    QMenu * m_pTrayIconMenu;
    QAction * m_pSimpleTimerAction;
    QAction * m_pShowWindowAction;
    QAction * m_pActionQuit;

    SimpleTimerDialog *m_pSimpleTimerDialog;

};

#endif // TRAYICON_H
