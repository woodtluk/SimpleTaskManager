#ifndef NOTIFYDIALOG_H
#define NOTIFYDIALOG_H

#include <QDialog>

namespace Ui {
    class NotifyDialog;
}

class NotifyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NotifyDialog(QWidget *parent = 0);
    ~NotifyDialog();
    void addTaskToList();

private:
    Ui::NotifyDialog *ui;
};

#endif // NOTIFYDIALOG_H
