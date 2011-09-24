#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


class QSystemTrayIcon;
class QMenu;
class QModelIndex;
class TaskDialog;
class TaskListModel;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:
  void setupTaskList();

private slots:
  void on_m_pActionRemoveTask_triggered();
  void on_m_pActionAddTask_triggered();
  void on_m_pActionQuit_triggered();

  void editTask(const QModelIndex& index);
  void showMessage();

private:
  Ui::MainWindow *ui;
  QSystemTrayIcon *m_pTrayIcon;

  TaskListModel *m_pTaskListModel;
  TaskDialog* m_pTaskDialog;
};

#endif // MAINWINDOW_H
