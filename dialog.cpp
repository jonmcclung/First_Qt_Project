#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include <QDesktopWidget>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    int parentX = parent->pos().x();
    int parentY = parent->pos().y();
    int xOffset = 96, yOffset = 32;
    int myX = QApplication::desktop()->screenGeometry().width()
            - (parentX + xOffset)
            < width()
            ? parentX - xOffset
            : parentX + xOffset;
    int myY = parentY - yOffset < 0
            ? parentY + parent->height() + yOffset
            : parentY - yOffset;
    move(myX, myY);
}

Dialog::~Dialog()
{
    delete ui;
}
