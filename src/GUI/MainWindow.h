#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSystemTrayIcon>
#include "../Task/Task.h"

#include "TrayIcon.h"


class QMenu;
class QModelIndex;
class TaskDialog;
class TaskListModel;
class SimpleTimerDialog;
class QFile;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

  friend class TrayIcon;

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

protected:
  virtual void changeEvent(QEvent* e);

private slots:
  void on_m_pActionRemoveTask_triggered();
  void on_m_pActionAddTask_triggered();
  void on_m_pActionQuit_triggered();

  void editTask(const QModelIndex& index);
  void bringUpWindowFromTray();

  void minuteTimeout();

private:
  void showMessage(QString strName) const;
  void checkIfAlarm(TaskPtr task) const;

private:
  Ui::MainWindow *ui;

  TaskListModel *m_pTaskListModel;
  TaskDialog* m_pTaskDialog;
  TrayIcon *m_pTrayIcon;

  QFile * m_pTasksFile;
};

#endif // MAINWINDOW_H
