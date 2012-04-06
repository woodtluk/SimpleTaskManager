#include "NotifyDialog.h"
#include "ui_NotifyDialog.h"

NotifyDialog::NotifyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NotifyDialog)
{
    ui->setupUi(this);
}

NotifyDialog::~NotifyDialog()
{
    delete ui;
}
