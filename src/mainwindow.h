#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QTimer>

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


private slots:
    void on_m_pActionRemoveTask_triggered();
    void on_m_pActionAddTask_triggered();
    void on_m_pActionQuit_triggered();

    void editTask(const QModelIndex& index);
    //void trayIconClicked(QSystemTrayIcon::ActivationReason reason);

    void setSimpleTimer(int sec) {m_pSimpleTimer->start(sec * 1000);}

    void showMessage();


private:
    Ui::MainWindow *ui;

    QSystemTrayIcon *m_pTrayIcon;
    QMenu * m_pTrayIconMenu;
    QAction * m_pSimpleTimerAction;

    SimpleTimerDialog * m_pSimpleTimerDialog;
    QTimer * m_pSimpleTimer;
    TaskListModel *m_pTaskListModel;
    TaskDialog* m_pTaskDialog;
  };

#endif // MAINWINDOW_H
