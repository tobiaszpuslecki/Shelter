#ifndef NEWANIMALWINDOW_H
#define NEWANIMALWINDOW_H

#include "sqlcontroller.h"
#include <QDialog>
#include "ui_newanimalwindow.h"
#include "sqlcontroller.h"
#include <QMessageBox>

namespace Ui {
class newAnimalWindow;
}

class newAnimalWindow : public QDialog
{
    Q_OBJECT

public:
    explicit newAnimalWindow(QWidget *parent = 0);
    ~newAnimalWindow();






private slots:


    void on_pushButtonCancel_clicked();

    void on_pushButtonConfirm_clicked();

private:
    Ui::newAnimalWindow *ui;

};

#endif // NEWANIMALWINDOW_H
