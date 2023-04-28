#include "user_window.h"
#include "ui_user_window.h"
//#include "user.h"
#include "mainwindow.h"

user_window::user_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_window)
{
    ui->setupUi(this);
    /*user_window u;
    u.setStyleSheet(".QWidget{background-image:" + "url(" +":/img/img/wepik-export-20230424120105.png" + ");" + "border:0px}");*/
}

user_window::~user_window()
{
    delete ui;
}

void user_window::on_pushButton_clicked()
{
    string user_name,password,tmname;
    user_name = ui->user_name_reg->text().toStdString();
    password = ui->password_reg->text().toStdString();
    tmname = ui->Team_name->text().toStdString();

    MainWindow m;
    m.add_new_user(user_name,password,tmname);
    hide();
    mw = new MainWindow(this);
    mw->show();



}

