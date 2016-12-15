#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onButtonClick);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resetButton()
{
    ui->pushButton->setText(tr("Click me again!"));
    ui->pushButton->setEnabled(true);
}

void MainWindow::onButtonClick(int)
{
    Dialog* dialog = new Dialog(this);
    ui->pushButton->setText(tr("Thanks!"));
    ui->pushButton->setEnabled(false);
    dialog->show();
    QTimer::singleShot(3000, this, SLOT(resetButton()));
}
