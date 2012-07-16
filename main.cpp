#include <QtGui/QApplication>
#include "converterwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ConverterWidget w;
    w.show();
    
    return a.exec();
}
