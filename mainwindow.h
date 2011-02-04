#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


class QSystemTrayIcon;
class TaskDialog;
class QMenu;

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
    Ui::MainWindow *ui;

    TaskDialog* m_pTaskDialog;
    QSystemTrayIcon *trayIcon;

private slots:
    void on_m_pActionAddTask_triggered();
    void on_m_pActionQuit_triggered();
};

#endif // MAINWINDOW_H
