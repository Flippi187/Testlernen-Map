#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inputDB()
{
    m_name = ui->nameIn->toPlainText();
    m_num = ui->numIn->value();

    db.insert({m_name, m_num});
}

void MainWindow::on_sendButton_clicked()
{
    inputDB();
    ui->output->addItem(m_name + "\t" + QString::number(m_num));
}


void MainWindow::on_reqButton_clicked()
{
    m_reqName = ui->nameReq->toPlainText();

    if(db.find(m_reqName) != db.end())
    {
        m_numOut = db.at(m_reqName);
        ui->numOut->setText(QString::number(m_numOut));
        ui->light->setStyleSheet("Background-color: green");
    } else {
        ui->numOut->setText("Not found!");
        ui->light->setStyleSheet("Background-color: red");
    }
}
