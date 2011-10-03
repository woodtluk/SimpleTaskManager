#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../Task/Task.h"

class QSystemTrayIcon;
class QMenu;
class QModelIndex;
class TaskDialog;
class TaskListModel;
class SimpleTimerDialog;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

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
  //void trayIconClicked(QSystemTrayIcon::ActivationReason reason);

  void minuteTimeout();

private:
  void showMessage(QString strName) const;
  void checkIfAlarm(TaskPtr task) const;

private:
  Ui::MainWindow *ui;

  SimpleTimerDialog * m_pSimpleTimerDialog;
  TaskListModel *m_pTaskListModel;
  TaskDialog* m_pTaskDialog;

  QSystemTrayIcon *m_pTrayIcon;
  QMenu * m_pTrayIconMenu;
  QAction * m_pSimpleTimerAction;
  QAction * m_pShowWindowAction;
};

#endif // MAINWINDOW_H
