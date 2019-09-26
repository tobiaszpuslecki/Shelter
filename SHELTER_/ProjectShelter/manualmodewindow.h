#ifndef MANUALMODEWINDOW_H
#define MANUALMODEWINDOW_H

#include <QDialog>
#include "ui_manualmodewindow.h"
#include "sqlcontroller.h"

namespace Ui {
class manualModeWindow;
}

class manualModeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit manualModeWindow(QWidget *parent = 0);
    ~manualModeWindow();

private slots:
    void on_pushButtonExit_clicked();

    void on_pushButtonConfirm_clicked();

private:
    Ui::manualModeWindow *ui;
};

#endif // MANUALMODEWINDOW_H
