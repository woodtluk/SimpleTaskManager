#ifndef TASKDIALOG_H
#define TASKDIALOG_H

#include <QDialog>

#include "Task.h"

namespace Ui {
    class TaskDialog;
}

class TaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TaskDialog(TaskPtr task, QWidget *parent = 0);
    ~TaskDialog();

private:
    Ui::TaskDialog *ui;

    TaskPtr m_pTask;
};

#endif // TASKDIALOG_H
