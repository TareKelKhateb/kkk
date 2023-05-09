#include "user_play.h"
#include "ui_user_play.h"
#include"QMessageBox"
#include "player_informationn.h"
#include <QThread>
#include <QTimer>
// to communicate between the two window(user_play && player_information)
player to_player_info;

user_play::user_play(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_play)
{
    ui->setupUi(this);

    this->setWindowFlag(Qt::WindowType::FramelessWindowHint);
    // get leagues' data
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

        int legid;
        int tmid ;

        inFile >> adm.player_id_generator;
        inFile >> tmid;
        inFile >> legid;
        adm.set_league_id(legid);
        adm.set_team_id(tmid);


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

    if(p_select == -1){
        QMessageBox::about(this,"ERROR","you need to select a player from your team first");
    }
    else{
    //reset budget
    tmpbudget+=tmp[p_select].price;
    //reset player with default constuctor
    player p;
    tmp[p_select]=p;
    // tmp[p_select].price = 0;
    //show players after modification
    load_tmp();
    }

}





void user_play::on_Home_clicked()
{

    ui->stackedWidget->setCurrentIndex(0);
    ui->Current_page->setText("Home");
    ui->GW->setText(QString::number(adm.gw_num));
    ui->Points->setText(QString::number(main_user.points[adm.gw_num-2]));
    ui->TOTAL_POINTS->setText(QString::number(main_user.total_points));
    ui->team_name->setText(QString::fromStdString(main_user.Team_name));

    // show players_name
    ui->p1->setText(QString::fromStdString(main_user.players[0].pl_name));
    ui->p2->setText(QString::fromStdString(main_user.players[1].pl_name));
    ui->p3->setText(QString::fromStdString(main_user.players[2].pl_name));
    ui->p4->setText(QString::fromStdString(main_user.players[3].pl_name));
    ui->p5->setText(QString::fromStdString(main_user.players[4].pl_name));



}



void user_play::load_tmp(){

    //show players && budget in the TSM
    ui->ptmp->setText(QString::fromStdString(tmp[0].pl_name));
    ui->ptmp_2->setText(QString::fromStdString(tmp[1].pl_name));
    ui->ptmp_3->setText(QString::fromStdString(tmp[2].pl_name));
    ui->ptmp_4->setText(QString::fromStdString(tmp[3].pl_name));
    ui->ptmp_5->setText(QString::fromStdString(tmp[4].pl_name));
    ui->Now_budget->setText(QString::number(tmpbudget));

}


void user_play::on_TSM_clicked()
{
    //get the right window
    ui->stackedWidget->setCurrentIndex(1);    
    ui->Current_page->setText("Transfer Market");
    //remove
    ui->Leagues->clear();

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

    ui->tableWidget->setRowCount(0);
    //get user sorted
    MainWindow m;
    user_sorted_point = m.sorted_users();
    //qDebug()<< user_sorted_point.size() << "queue size";

    //loop through all the data and show it in the table
    int i=0;
    while(!user_sorted_point.empty()){
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::fromStdString(user_sorted_point.top().second)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(user_sorted_point.top().first)));

        if(ui->tableWidget->item(i, 0)->text() == QString::fromStdString(main_user.get_username())){ // check if the current username matches the specific username
            for(int col = 0; col < ui->tableWidget->columnCount(); col++){
                QTableWidgetItem *item = ui->tableWidget->item(i, col);
                item->setBackground(Qt::green); // highlight the entire row by setting the background color to yellow
            }
        }
        user_sorted_point.pop();
        i++;
    }


}


void user_play::on_Leagues_currentIndexChanged(int index)
{
    ui->Teams->clear();
    //loop through all teams in the league(index) and put them in teams combobox
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

     //return the current player

    return adm.leagues[legindex].teams[tmindex].players[plindex];

}

player user_play::the_info_player(){

    return to_player_info;

}
void user_play::on_PLayer_info_clicked()
{
    //set the_player_info to the current player to send it to info window
    to_player_info=player_info_req();

    //call the window
    player_informationn p;
    p.setModal(true);
    p.exec();


    /* ui->gww->show();
    ui->gww_2->show();
    ui->ponts->show();

    for(int i=1;i<=36;i++){
        ui->gww_2->addItem(QString::number(i));
    }*/


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
    QApplication::closeAllWindows();
}


void user_play::on_gww_2_currentIndexChanged(int index)
{
    /*int legindex = ui->Leagues->currentIndex();
    int tmindex = ui->Teams->currentIndex();
    int plindex = ui->PLayers->currentIndex();


    if(index !=-1){
        ui->ponts->setText(QString::number(adm.leagues[legindex].teams[tmindex].players[plindex].arr_points[index]));
    }*/
}


void user_play::on_search_player_clicked()
{
    //player search
    string name = ui->player_search_name->text().toStdString();
    int lindx=0,tindex=0,pindex=0;
    bool found =false;

    adm.find_player_by_name(found,lindx,tindex,pindex,name);
    //qDebug()<<found<<" "<<lindx<<" "<<tindex<<" "<<pindex;

    //gui change player
    if(found){
    ui->Leagues->setCurrentIndex(lindx);
    ui->Teams->setCurrentIndex(tindex);
    ui->PLayers->setCurrentIndex(pindex);
    }
    else{

    QMessageBox::about(this,"ERROR","PLAYER NOT FOUND ");

    }





}


void user_play::on_pushButton_3_clicked()
{



    /*bool found =false;
    for(int i=0;i<5;i++){

    if(tmp[i].player_id == b.player_id){
            found = true;
            break;
    }
    }*/
    //check if a player selected
    if(p_select ==-1){

         QMessageBox::about(this,"Warning","Select a player from your team");

    }
    else if(main_user.get_lucky_spin() <= 0){

         QMessageBox::about(this,"Warning","you have 0 lucky spin left");
    }
    else{

         QMessageBox::StandardButton reply = QMessageBox::question(this,"Warning","Are you sure.the player you selected will be replaced.\n you have"+
                                                                                        QString::number(main_user.get_lucky_spin()) +"lucky spin left ",QMessageBox::Yes | QMessageBox::No);
         //wait for an answer for a user
         if(reply == QMessageBox::Yes){
            //tmp[p_select],,code random(leg,tmindex,plaindex),swap
            player ran_player = adm.pick_random_player();

            // check if a player is already in the team if so call the button recursively
            if(ran_player.player_id == tmp[p_select].player_id)
                on_pushButton_3_clicked();
            else{
                tmp[p_select]=ran_player;
                main_user.minus_lucky_spin();
            }


       }

    }

    load_tmp();



}








