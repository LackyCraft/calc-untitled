#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
double eq01=0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

/*
 * При нажатии кнопок 0-9 вызываем слот diget_num
 * Именно благодаря такой реализации мы не создавали кучу однотипных методов, а брали 10 сигналов кнопок которые уже оборазуются к одному методу digets_num()
 *
 * много методов
*/
connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digets_num()));
connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digets_num()));
connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digets_num()));
connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digets_num()));
connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digets_num()));
connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digets_num()));
connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digets_num()));
connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digets_num()));
connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digets_num()));
connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digets_num()));
connect(ui->pushButton_div,SIGNAL(clicked()),this,SLOT(math()));
connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math()));
connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math()));
connect(ui->pushButton_x,SIGNAL(clicked()),this,SLOT(math()));
connect(ui->pushButton_step,SIGNAL(clicked()),this,SLOT(math()));
connect(ui->pushButton_AC,SIGNAL(clicked()),this,SLOT(operation()));
connect(ui->pushButton_cos,SIGNAL(clicked()),this,SLOT(operation()));
connect(ui->pushButton_sin,SIGNAL(clicked()),this,SLOT(operation()));
connect(ui->pushButton_plus_and_minus,SIGNAL(clicked()),this,SLOT(operation()));

ui->pushButton_div->setCheckable(true);
ui->pushButton_plus->setCheckable(true);
ui->pushButton_minus->setCheckable(true);
ui->pushButton_x->setCheckable(true);
//ui->pushButton_sin->setCheckable(true);
//ui->pushButton_cos->setCheckable(true);
//ui->pushButton_plus_and_minus->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digets_num(){
    QPushButton *button = static_cast<QPushButton*>(sender());
//Вывод на экранчик
    ui->status->setText(QString::number((ui->status->text()+button->text()).toDouble(),'g',10));
}


void MainWindow::on_pushButton_dot_clicked()
{
  if(!(ui->status->text().contains('.'))) //есть ли точка
  ui->status->setText(ui->status->text()+'.');
}

void MainWindow::operation(){
    QPushButton *button = static_cast<QPushButton*>(sender());
//Вывод на экранчик
    if(button->text() == "AC"){
      ui->status->setText(QString::number(0));
      eq01=0;
    }else if(button->text() == "-/+"){
    ui->status->setText(QString::number(-1*(ui->status->text()).toDouble(),'g',10));
    }
    else if(button->text() == "sin"){
        ui->status->setText(QString::number(sin((ui->status->text()).toDouble()),'g',10));
        }else if(button->text() == "cos"){
        ui->status->setText(QString::number(cos((ui->status->text()).toDouble()),'g',10));
        }
}


//математика, флаги
void MainWindow::math()
{
   QPushButton *button = static_cast<QPushButton*>(sender());
   button->setCheckable(true);
   eq01=ui->status->text().toDouble();
   ui->status->setText("");
   button->setChecked(true);
}


//равно
void MainWindow::on_pushButton_eq_clicked()
{
 //QPushButton *button = static_cast<QPushButton*>(sender());
 double num_s,num_step;//num_s - сейчас на экране, степень это то что было
 num_step=eq01;
    num_s=ui->status->text().toDouble();
    if(ui->pushButton_plus->isChecked()){
    ui->status->setText(QString::number(num_s+eq01,'g',10));
    ui->pushButton_plus->setChecked(false);
    }else if(ui->pushButton_minus->isChecked()){
    ui->status->setText(QString::number(eq01-num_s,'g',10));
    ui->pushButton_minus->setChecked(false);
    }else if(ui->pushButton_div->isChecked()){
    ui->status->setText(QString::number(eq01/num_s,'g',10));
    ui->pushButton_div->setChecked(false);
    }else if(ui->pushButton_x->isChecked()){
    ui->status->setText(QString::number(eq01*num_s,'g',10));
    ui->pushButton_x->setChecked(false);
    }else if(ui->pushButton_step->isChecked()){
        if(num_s != 0 ){
        for(double i=num_s;i>1;i--)
            eq01*=num_step;
    ui->status->setText(QString::number(eq01));}
        else{ui->status->setText(QString::number(1));}
        ui->pushButton_x->setChecked(false);
    }
}
