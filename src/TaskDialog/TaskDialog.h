#ifndef TASKDIALOG_H
#define TASKDIALOG_H

#include <QDialog>
#include<QDataWidgetMapper>

class TaskListModel;



namespace Ui {
    class TaskDialog;
}

class TaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TaskDialog(TaskListModel *model, QWidget *parent = 0);
    virtual ~TaskDialog();

    void disableBrowseButtons(bool disable);
  public slots:
    void	revert() {m_pDataWidgetMapper->revert();}
    virtual void	setCurrentIndex(int index){m_pDataWidgetMapper->setCurrentIndex(index);}
    void	setCurrentModelIndex(const QModelIndex &index){m_pDataWidgetMapper->setCurrentModelIndex(index);}
    bool	submit(){return m_pDataWidgetMapper->submit();}
    void	toFirst(){m_pDataWidgetMapper->toFirst();}
    void	toLast(){m_pDataWidgetMapper->toLast();}
    void	toNext(){m_pDataWidgetMapper->toNext();}
    void	toPrevious(){m_pDataWidgetMapper->toPrevious();}

  private slots:
      void on_m_pOkAbbortButtonBox_accepted();
      void on_m_pOkAbbortButtonBox_rejected();

private:
    Ui::TaskDialog *ui;

    QDataWidgetMapper *m_pDataWidgetMapper;
};

#endif // TASKDIALOG_H
