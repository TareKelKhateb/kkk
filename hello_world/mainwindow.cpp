
#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "user.h"
#include <vector>
#include "user_window.h"
#include "admin_form.h"
#include "user_play.h"
#include "QMessageBox"

vector<user>users;
user main_user ;
int user_numberr;
priority_queue<pair<int,string>>user_sorted;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->label_39->setPixmap(QPixmap(":/img/img/logo_transparent.png"));


    this->setWindowFlag(Qt::WindowType::FramelessWindowHint);
    load_data();

    /*user b("123","123","zamalek");

    users.push_back(b);*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

user MainWindow:: user_number(){

    return users[user_numberr] ;
}

void MainWindow::save_data(){

    std::ofstream outfile("C:/Users/tarek/Documents/hello_world/users.txt");
    qDebug() << users.size() ;
    outfile<<users.size()<<endl;
    for (int i=0;i<users.size();i++) {
        outfile << users[i].get_username() << endl;
        outfile << users[i].get_password() << endl;
        outfile << users[i].Team_name << endl;
        outfile << users[i].budget << endl;
        outfile << users[i].total_points << endl;

        // write the points array
        for (int j = 0; j < 36; j++) {
            outfile << users[i].points[j] << " ";
        }
        outfile<<endl;

        // write the players_ids array
        for (int j = 0; j < 5; j++) {
            outfile << users[i].players_ids[j] << " ";
        }

        outfile << '\n'; // end the line
    }

    outfile.close(); // close the file

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

    else{


    bool ok =false ;
    for(int i=0;i<users.size();i++){


        if(users[i].get_username() == us_name  && users[i].get_password() == pass ){


          //  ok =true;
          user_numberr=i;
          qDebug() <<user_numberr;
          ok=true;
          user_play p;
          p.setModal(true);
          p.exec();


        }
    }
    //show error message if not found
    if(!ok){

        QMessageBox::about(this,"ERROR","WRONGE USERNAME OR PASSWORD");
    }
  }





}

void MainWindow::load_data(){




        std::ifstream infile("C:/Users/tarek/Documents/hello_world/users.txt");
        int num_users;
        infile >> num_users;
        users.resize(num_users);
        for (int i = 0; i < num_users; i++) {

          string u,p;
          infile >> u;
          infile >> p;

          infile >> users[i].Team_name;
          infile >> users[i].budget;
          infile >> users[i].total_points;
          users[i].set_username(u);
          users[i].set_password(p);
        //  users[i].Team_name="ali";

          for (int j = 0; j < 36; j++) {
              infile >> users[i].points[j];
          }

          for (int j = 0; j < 5; j++) {
              infile >> users[i].players_ids[j];
          }

        }

        infile.close();


}

void MainWindow::calc_points(int GW , map<int,player>player_map){

        qDebug() << player_map.size() <<" hiii";

        for(int i=0;i<users.size();i++){
          int gw_points=0;
          for(int j=0;j<5;j++){

              //load the players using the map
              users[i].players[j]=player_map[users[i].players_ids[j]];
              //calc points for each player
              users[i].total_points += users[i].players[j].arr_points[GW-1];
              //calc gw points
              gw_points+=users[i].players[j].arr_points[GW-1];


          }

          users[i].points[GW-1] = gw_points;



        }


}


void MainWindow::on_pushButton_2_clicked()
{
    user_window secs;
    secs.setModal(true);
    secs.exec();
}

void MainWindow::save_mainuser_data(user mnu){

    qDebug()<<user_numberr<< "user_number";
    users[user_numberr]=mnu;
    save_data();
}
priority_queue<pair<int,string>> MainWindow::sorted_users(){

    if(user_sorted.size() != users.size()){
            for(int i=0;i<users.size();i++){

                user_sorted.push({users[i].total_points,users[i].get_username()});
            }
    }

    return user_sorted ;
}

