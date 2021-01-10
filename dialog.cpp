#include "dialog.h"
#include "ui_dialog.h"
#include "threadtest.h"
#include <QRandomGenerator>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    m_pThread = new ThreadTest(this);
    m_pThread->start();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::resizeEvent(QResizeEvent*)
{
    qDebug() << "w=" << this->width() << " h=" << this->height();
    ui->stackedWidget->setFixedSize(this->width(), this->height());
}


void Dialog::on_pb_vibration_clicked()
{

}

void Dialog::on_pb_settings_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Dialog::on_pb_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_pb_setitem_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Dialog::on_pb_gateway_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void Dialog::on_pb_datatrend_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Dialog::on_pb_ok_gateway_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Dialog::on_pb_ok_trend_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Dialog::on_pb_ok_item_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void Dialog::setLabel(int num)
{
    int v = QRandomGenerator::global()->bounded(100, 20000);
    ui->label_03->setNum(num);
    ui->label_05->setNum(v);
    ui->label_10->setNum(v+num);
    ui->label_25->setNum(v-num);
    ui->label_50->setNum(num*num);
    ui->label_100->setNum(num*2);
}
