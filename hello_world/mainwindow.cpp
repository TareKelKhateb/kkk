
#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "user.h"
#include <vector>
#include "user_window.h"
#include "admin_form.h"
#include "user_play.h"
vector<user>users;
user main_user ;
int user_numberr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->label_39->setPixmap(QPixmap(":/img/img/logo_transparent.png"));

    this->setWindowFlag(Qt::WindowType::FramelessWindowHint);

    user b("123","123","zamalek");

    users.push_back(b);
}

MainWindow::~MainWindow()
{
    delete ui;
}

user MainWindow:: user_number(){

    return users[user_numberr] ;
}


void MainWindow::add_new_user(string usn , string pss , string tmname){

    user new_user(usn,pss,tmname);
    users.push_back(new_user);

}



void MainWindow::on_pushButton_clicked()
{

    //user_num="3";

    string us_name = ui->name->text().toStdString() ;
    string pass = ui->password->text().toStdString() ;
    if(us_name == "admin" && pass == "admin"){

        admin_form ad;
        ad.setModal(true);
        ad.exec();
    }




    bool ok =false ;
    for(int i=0;i<users.size();i++){


        if(users[i].get_username() == us_name  && users[i].get_password() == pass ){


          //  ok =true;
            user_numberr=i;

          user_play p;
          p.setModal(true);
          p.exec();


        }
    }





}


void MainWindow::on_pushButton_2_clicked()
{
    user_window secs;
    secs.setModal(true);
    secs.exec();
}

