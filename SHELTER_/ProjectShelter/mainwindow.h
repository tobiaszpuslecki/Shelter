#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include "sqlcontroller.h"
#include "ui_mainwindow.h"
#include "newanimalwindow.h"
#include "adoptionwindow.h"
#include "filtersearchwindow.h"
#include "manualmodewindow.h"
#include "ownerwindow.h"

namespace Ui {
class mainWindow;
}

class mainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = 0);
    ~mainWindow();

    void disabledAllButtons();

private slots:
    void on_pushButtonExit_clicked();

    void on_pushButtonFound_clicked();

    void on_pushButtonAdoption_clicked();

    void on_pushButtonFilterSearch_clicked();

    void on_pushButton_clicked();

    void on_pushButtonOwner_clicked();

private:
    Ui::mainWindow *ui;


};



#endif // MAINWINDOW_H
