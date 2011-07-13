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
    virtual ~TaskDialog();

    void disableBrowseButtons(bool disable);
private:
    Ui::TaskDialog *ui;

    TaskPtr m_pTask;

private slots:
    void on_m_pOkAbbortButtonBox_accepted();
    void on_m_pOkAbbortButtonBox_rejected();
};

#endif // TASKDIALOG_H
