#include "simpletimerdialog.h"
#include "ui_simpletimerdialog.h"

#include <QIntValidator>
#include <QMessageBox>
#include <QTimer>

SimpleTimerDialog::SimpleTimerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SimpleTimerDialog),
    m_pIntValidator(new QIntValidator(this)),
    m_pSimpleTimer(new QTimer(this))

{
    ui->setupUi(this);

    m_pIntValidator->setRange(1, 9999);
    ui->m_pLineEdit->setValidator(m_pIntValidator);
}

SimpleTimerDialog::~SimpleTimerDialog()
{
  delete ui;
}

void SimpleTimerDialog::accept()
{
  bool bOk;
  quint8 mins = ui->m_pLineEdit->text().toUInt(&bOk);
  Q_ASSERT(bOk);

  if (!bOk) {
    reject();
  }
  else
  {
    m_pSimpleTimer->singleShot(mins * 1000 * 60, this, SLOT(simpleTimerShot()));
    QDialog::accept();
  }


}
void SimpleTimerDialog::reject() {
  m_pSimpleTimer->stop();
  QDialog::reject();
}

void SimpleTimerDialog::simpleTimerShot() {
  QMessageBox::warning(this, "Timer finished!", "Timer finished!");
}
