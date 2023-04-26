#include "secondform.h"
#include "ui_secondform.h"
//#include "user.h"
#include "mainwindow.h"


admin k_admin;

Secondform::Secondform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Secondform)
{
    ui->setupUi(this);
}

Secondform::~Secondform()
{
    delete ui;
}

void Secondform::on_pushButton_clicked()
{

    MainWindow main;
    mnuser = main.user_number();

    ui->lineEdit->setText(QString::fromStdString(mnuser.get_username()));
}

