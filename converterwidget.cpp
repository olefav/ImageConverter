#include "converterwidget.h"
#include "ui_converterwidget.h"

#include <QImageWriter>
#include <QImageReader>
#include <QFileDialog>
#include <QList>
#include <QByteArray>
#include <QMessageBox>

ConverterWidget::ConverterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConverterWidget)
{
    ui->setupUi(this);
}

void ConverterWidget::loadImage()
{
    QList<QByteArray> sFormats = QImageReader::supportedImageFormats();

    QString formats;

    foreach (QByteArray format, sFormats) {
        formats += "(*." + format + ")" + ";;";
    }

    //now we can try to read all the files:
    formats += "(*.*);;";

    QString fileName = QFileDialog::getOpenFileName(0, tr("Open"), QApplication::applicationDirPath(), formats);

    QImageReader reader(fileName);

    image = reader.read();

    if(reader.error() != QImageReader::UnknownError) {
        QMessageBox::critical(0, tr("Error"), reader.errorString());
    }
}

void ConverterWidget::saveImage()
{
    if (image.isNull()) {
        QMessageBox::warning(0, tr("Error"), tr("Image not loaded!"));
        return;
    }

    QList<QByteArray> sFormats = QImageWriter::supportedImageFormats();

    QString formats;

    foreach (QByteArray format, sFormats) {
        formats += "(*." + format + ")" + ";;";
    }

    QString fileName = QFileDialog::getSaveFileName(0, tr("Save"), QApplication::applicationDirPath(), formats);

    QImageWriter writer (fileName);

    if (!writer.write(image)) {
        QMessageBox::critical(0, tr("Error"), writer.errorString());
    }

}

ConverterWidget::~ConverterWidget()
{
    delete ui;
}
