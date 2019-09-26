#ifndef FILTERSEARCHWINDOW_H
#define FILTERSEARCHWINDOW_H

#include <QDialog>
#include "ui_filtersearchwindow.h"
#include "sqlcontroller.h"
#include "shelter.h"
#include <QMessageBox>

namespace Ui {
class filterSearchWindow;
}

class filterSearchWindow : public QDialog
{
    Q_OBJECT

public:
    explicit filterSearchWindow(QWidget *parent = 0);
    ~filterSearchWindow();

private slots:

    void on_pushButtonCancel_clicked();

    void on_pushButtonLeftArrow_clicked();

    void on_pushButtonRightArrow_clicked();

    void on_pushButtonSearch_clicked();

private:
    Ui::filterSearchWindow *ui;
};

#endif // FILTERSEARCHWINDOW_H
