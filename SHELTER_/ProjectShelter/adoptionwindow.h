#ifndef ADOPTIONWINDOW_H
#define ADOPTIONWINDOW_H

#include <QDialog>
#include "ui_adoptionwindow.h"
#include "sqlcontroller.h"
#include <QMessageBox>

namespace Ui {
class adoptionWindow;
}

class adoptionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit adoptionWindow(QWidget *parent = 0);
    ~adoptionWindow();

private slots:
    void on_pushButtonCancel_clicked();

    void on_pushButtonConfirm_clicked();

private:
    Ui::adoptionWindow *ui;
};

#endif // ADOPTIONWINDOW_H
