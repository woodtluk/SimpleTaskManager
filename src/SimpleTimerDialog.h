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

public slots:
  virtual void	accept();
  virtual void	reject();

signals:
    void acceptTimer(int msec);

private slots:
    void simpleTimerShot();
    //void acceptTimerSet(){}

private:
    QIntValidator * m_pIntValidator;
    QTimer * m_pSimpleTimer;

    Ui::SimpleTimerDialog *ui;
};

#endif // SIMPLETIMERDIALOG_H
