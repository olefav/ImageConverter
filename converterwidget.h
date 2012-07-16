#ifndef CONVERTERWIDGET_H
#define CONVERTERWIDGET_H

#include <QtGui/QWidget>

namespace Ui {
class ConverterWidget;
}

class ConverterWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit ConverterWidget(QWidget *parent = 0);
    ~ConverterWidget();
    
private:
    Ui::ConverterWidget *ui;
    QImage image;
private slots:
    void loadImage();
    void saveImage();
};

#endif // CONVERTERWIDGET_H
