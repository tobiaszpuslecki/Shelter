#include <QApplication>
#include "mainwindow.h"
#include "loginwindow.h"
#include "sqlcontroller.h"

int main(int argc, char **argv)
{


 QApplication app(argc, argv);

 loginWindow l;
 l.show();

 return app.exec();
}
