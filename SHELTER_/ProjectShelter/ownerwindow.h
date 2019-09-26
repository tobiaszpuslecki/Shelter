#ifndef OWNERWINDOW_H
#define OWNERWINDOW_H

#include <QDialog>
#include "ui_ownerwindow.h"
#include "sqlcontroller.h"

namespace Ui {
class ownerWindow;
}

class ownerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ownerWindow(QWidget *parent = 0);
    ~ownerWindow();

private slots:
    void on_pushButtonCancel_clicked();

    void on_pushButtonConfirm_clicked();

private:
    Ui::ownerWindow *ui;
};

#endif // OWNERWINDOW_H
