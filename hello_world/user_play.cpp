#include "user_play.h"
#include "ui_user_play.h"
#include"QMessageBox"

user_play::user_play(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_play)
{
    ui->setupUi(this);
    load_data();
    //get the user from mainwindow
    MainWindow m;
    main_user = m.user_number();
    //load user's team
    main_user.load_players(map_players);
    on_Home_clicked();



}

user_play::~user_play()
{
    delete ui;
}


void user_play::load_data(){




    std::ifstream inFile("C:/Users/tarek/Documents/hello_world/leagues.txt");

    if (inFile.is_open()) {

        inFile >> adm.gw_num;
        int numLeagues;
        inFile >> numLeagues;
        qDebug() <<numLeagues ;

        //std::vector<league> leagues;
        adm.leagues.resize(numLeagues);

        // Read data for each league
        for (int i = 0; i < numLeagues; i++) {


            int leagueId, numTeams;
            inFile >> adm.leagues[i].leagueName >> leagueId >> numTeams;
            adm.leagues[i].setID(leagueId);


            //League league(leagueName, leagueId);
            adm.leagues[i].teams.resize(numTeams);
            // Read data for each team
            for (int j = 0; j < numTeams; j++) {

                inFile >> adm.leagues[i].teams[j].team_name >> adm.leagues[i].teams[j].team_id ;

                // Team team(teamName, teamId);

                // Read data for each player
                for (int k = 0; k < 11; k++) {

                    // std::string playerName;
                    // int playerId, price;
                    inFile >> adm.leagues[i].teams[j].players[k].pl_name >> adm.leagues[i].teams[j].players[k].player_id >> adm.leagues[i].teams[j].players[k].price;

                    // Player player(playerName, playerId, price);

                    // Read goals and points scored by the player in 36 matches
                    for (int l = 0; l < 36; l++) {

                        inFile >> adm.leagues[i].teams[j].players[k].arr_goals[l];

                    }

                    for (int l = 0; l < 36; l++) {

                        inFile >> adm.leagues[i].teams[j].players[k].arr_points[l];

                    }

                    map_players[adm.leagues[i].teams[j].players[k].player_id] = adm.leagues[i].teams[j].players[k];

                }

            }

        }

        qDebug() << adm.leagues.size() << adm.leagues[0].teams.size();

        inFile.close();

        // Process the read data here
        // ...
    }
    else {
        std::cout << "Error: Unable to open file " << "leagues.txt" << " for reading." << std::endl;
    }



}

void user_play::on_pushButton_clicked()
{
    //assign the player to null
  /*  tmp[p_select].pl_name="NONE";
    tmp[p_select].player_id=-1;*/


  //..add qmessage that every player with NONE canot be sold

    tmpbudget+=tmp[p_select].price;

    player p;
    tmp[p_select]=p;
    tmp[p_select].price = 0;
    load_tmp();

}





void user_play::on_Home_clicked()
{

    ui->stackedWidget->setCurrentIndex(0);
    ui->Current_page->setText("Home");
    ui->GW->setText(QString::number(adm.gw_num));
    ui->Points->setText(QString::number(main_user.points[adm.gw_num-2]));
    ui->TOTAL_POINTS->setText(QString::number(main_user.total_points));
    ui->team_name->setText(QString::fromStdString(main_user.Team_name));


    ui->p1->setText(QString::fromStdString(main_user.players[0].pl_name));
    ui->p2->setText(QString::fromStdString(main_user.players[1].pl_name));
    ui->p3->setText(QString::fromStdString(main_user.players[2].pl_name));
    ui->p4->setText(QString::fromStdString(main_user.players[3].pl_name));
    ui->p5->setText(QString::fromStdString(main_user.players[4].pl_name));



}



void user_play::load_tmp(){


    ui->ptmp->setText(QString::fromStdString(tmp[0].pl_name));
    ui->ptmp_2->setText(QString::fromStdString(tmp[1].pl_name));
    ui->ptmp_3->setText(QString::fromStdString(tmp[2].pl_name));
    ui->ptmp_4->setText(QString::fromStdString(tmp[3].pl_name));
    ui->ptmp_5->setText(QString::fromStdString(tmp[4].pl_name));
    ui->Now_budget->setText(QString::number(tmpbudget));

}


void user_play::on_TSM_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);    
    ui->Current_page->setText("Transfer Market");


    //push all leagues

    for(int i=0;i<adm.leagues.size();i++){
        ui->Leagues->addItem(QString::fromStdString(adm.leagues[i].leagueName));
    }


    //make a tmp players array  and show the players
    for(int i=0;i<5;i++){

        tmp[i]=main_user.players[i];
    }
    tmpbudget = main_user.budget;

    load_tmp();


}




void user_play::on_STANDING_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

    ui->Current_page->setText("Standing");
}


void user_play::on_Leagues_currentIndexChanged(int index)
{
    ui->Teams->clear();
    if(index !=-1){

        for(int i=0;i<adm.leagues[index].teams.size();i++){

            ui->Teams->addItem(QString::fromStdString(adm.leagues[index].teams[i].team_name));
        }
    }
}


void user_play::on_Teams_currentIndexChanged(int index)
{

    ui->PLayers->clear();
    int legindex = ui->Leagues->currentIndex();
    if(index !=-1 && legindex >=0 && legindex <=100){

        for(int i=0;i<11;i++){

            ui->PLayers->addItem(QString::fromStdString(adm.leagues[legindex].teams[index].players[i].pl_name));
        }
    }
}


void user_play::on_PLayers_currentIndexChanged(int index)
{
    int legindex = ui->Leagues->currentIndex();
    int tmindex = ui->Teams->currentIndex();
    ui->gww_2->hide();
    ui->gww->hide();
    ui->ponts->hide();
    if(index !=-1){


        ui->Player_namee->setText(QString::fromStdString(adm.leagues[legindex].teams[tmindex].players[index].pl_name));
        ui->Price->setText(QString::number(adm.leagues[legindex].teams[tmindex].players[index].price));
    }
}


void user_play::on_p1p_clicked()
{
    p_select=0;
}


void user_play::on_p2p_clicked()
{

    p_select=1;
}


void user_play::on_p3p_clicked()
{

    p_select=2;
}


void user_play::on_p4p_clicked()
{

    p_select=3;
}


void user_play::on_p5p_clicked()
{
    p_select=4;
}

player user_play::player_info_req(){

    int legindex = ui->Leagues->currentIndex();
    int tmindex = ui->Teams->currentIndex();
    int plindex = ui->PLayers->currentIndex();



    return adm.leagues[legindex].teams[tmindex].players[plindex];

}
void user_play::on_PLayer_info_clicked()
{

    ui->gww->show();
    ui->gww_2->show();
    ui->ponts->show();

    for(int i=1;i<=36;i++){
        ui->gww_2->addItem(QString::number(i));
    }


}





void user_play::on_BUY_clicked()
{
    //return the current player
    player b = player_info_req();
    // check if the player already in the team



    bool found =false;
    for(int i=0;i<5;i++){

        if(tmp[i].player_id == b.player_id){
            found = true;
            break;
        }
    }


    if(tmpbudget + tmp[p_select].price < b.price ){

        //qmessage do not have enough money
        QMessageBox::about(this,"ERROR","you don't have enough money to purchase this player");
    }
    else if(found == true){
        //qmessage the player is in your team
        QMessageBox::about(this,"ERROR","the player is already in your team");
    }
    else if(p_select ==- 1){
        //qmessage select a player

        QMessageBox::about(this,"ERROR","you need to select a player from your team first");

    }
    else{
        //assign new player then show him
        tmpbudget+=tmp[p_select].price;
        tmpbudget-=b.price;
        tmp[p_select]=b;
        load_tmp();

    }


}


void user_play::on_BUY_2_clicked()
{
    //assign_players
    main_user.assign_players(tmp);
    main_user.budget=tmpbudget;


}


void user_play::on_pushButton_2_clicked()
{
    //save the data and close the application

    MainWindow m;
    m.save_mainuser_data(main_user);
}


void user_play::on_gww_2_currentIndexChanged(int index)
{
    int legindex = ui->Leagues->currentIndex();
    int tmindex = ui->Teams->currentIndex();
    int plindex = ui->PLayers->currentIndex();


    if(index !=-1){
        ui->ponts->setText(QString::number(adm.leagues[legindex].teams[tmindex].players[plindex].arr_points[index]));
    }
}

