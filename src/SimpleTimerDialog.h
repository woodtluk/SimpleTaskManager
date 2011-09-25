#ifndef SIMPLETIMERDIALOG_H
#define SIMPLETIMERDIALOG_H

#include <QDialog>

class QIntValidator;

namespace Ui {
    class SimpleTimerDialog;
}

class SimpleTimerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SimpleTimerDialog(QWidget *parent = 0);
    ~SimpleTimerDialog();

signals:
    void acceptTimer(int msec);

private slots:
        void acceptTimerSet(){}

private:
    QIntValidator * m_pIntValidator;

    Ui::SimpleTimerDialog *ui;
};

#endif // SIMPLETIMERDIALOG_H
