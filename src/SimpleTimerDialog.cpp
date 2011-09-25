#include "simpletimerdialog.h"
#include "ui_simpletimerdialog.h"

#include <QIntValidator>


SimpleTimerDialog::SimpleTimerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SimpleTimerDialog),
    m_pIntValidator(new QIntValidator(this))
{
    ui->setupUi(this);

    m_pIntValidator->setRange(1, 9999);
    ui->m_pLineEdit->setValidator(m_pIntValidator);
}

SimpleTimerDialog::~SimpleTimerDialog()
{
    delete ui;
}
