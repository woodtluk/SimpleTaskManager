#include "TaskDialog.h"
#include "ui_TaskDialog.h"

#include "Task.h"

TaskDialog::TaskDialog(TaskPtr task, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskDialog),
    m_pTask(task)
{
    ui->setupUi(this);
}

TaskDialog::~TaskDialog()
{
    delete ui;
}
