#include "admin_form.h"
#include "ui_admin_form.h"
#include <QDir>

 admin adm;
using namespace  std ;

admin_form::admin_form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_form)
{
    ui->setupUi(this);
    home_labels_edit();
    //on_pushButton_3_clicked();
    on_pushButton_5_clicked() ;


}

void admin_form::home_labels_edit(){
    ui->GW_number->setText(QString::number(adm.gw_num));
    ui->leagues_num->setText(QString::number(adm.leagues.size()));

    int tmtotal = 0 ;

    for(int i=0;i<adm.leagues.size();i++){
        tmtotal+=adm.leagues[i].teams.size();
    }

    ui->Teams_num->setText(QString::number(tmtotal));


}

admin_form::~admin_form()
{
    delete ui;
}

void admin_form::on_pushButton_clicked()
{

}



void admin_form::on_ADD_clicked()
{
    adm.add_league(ui->league_new_name->text().toStdString(),1);
    home_labels_edit();
}



void admin_form::save_data(){


    std::ofstream outFile("leagues.txt", ios::out);

    if (outFile.is_open())
    {

        // Write the number of leagues
        outFile << adm.leagues.size() << std::endl;

        // Write the data for each league
        for (int leagueindx =0;leagueindx<adm.leagues.size();leagueindx++)
        {
            // Write the league name and ID
            outFile <<adm.leagues[leagueindx].displayLeagueName() << std::endl;
            outFile << adm.leagues[leagueindx].getLeagueId() << std::endl;


            outFile << adm.leagues[leagueindx].teams.size() << std::endl;

            // Write the data for each team
            for (int teamindx=0;teamindx<adm.leagues[leagueindx].teams.size();teamindx++)
            {
                // Write the team name and ID
                outFile << adm.leagues[leagueindx].teams[teamindx].team_name << std::endl;
                outFile << adm.leagues[leagueindx].teams[teamindx].team_id << std::endl;

                // Write the data for each player in the team
                for (int plindx ; plindx<11;plindx++)
                {
                    // Write the player name, ID, price, and goals
                    outFile << adm.leagues[leagueindx].teams[teamindx].players[plindx].pl_name << std::endl;
                    outFile << adm.leagues[leagueindx].teams[teamindx].players[plindx].player_id << std::endl;
                    outFile << adm.leagues[leagueindx].teams[teamindx].players[plindx].price << std::endl;

                    for (int i = 0; i < 36; i++)
                    {
                        outFile << adm.leagues[leagueindx].teams[teamindx].players[plindx].arr_goals[i] << " ";
                    }
                    outFile << std::endl;

                    for (int i = 0; i < 36; i++)
                    {
                        outFile << adm.leagues[leagueindx].teams[teamindx].players[plindx].arr_points[i] << " ";
                    }
                    outFile << std::endl;
                }
            }
        }

        // Close the file
        outFile.close();
    }
    else
    {
        std::cout << "Error: Unable to open file " << "leagues.txt" << " for writing." << std::endl;
    }



}




void admin_form::on_pushButton_2_clicked()
{

    player p1(ui->player0->text().toStdString());
    p1.player_id = adm.get_player_an_id();
    adm.players_map[p1.player_id]=p1;

    player p2(ui->player1->text().toStdString());
    p2.player_id = adm.get_player_an_id();
    adm.players_map[p2.player_id]=p2;

    player p3(ui->player2->text().toStdString());
    p3.player_id = adm.get_player_an_id();
    adm.players_map[p3.player_id]=p3;

    player p4(ui->player3->text().toStdString());
    p4.player_id = adm.get_player_an_id();
    adm.players_map[p4.player_id]=p4;

    player p5(ui->player4->text().toStdString());
    p5.player_id = adm.get_player_an_id();
    adm.players_map[p5.player_id]=p5;

    player p6(ui->player5->text().toStdString());
    p6.player_id = adm.get_player_an_id();
    adm.players_map[p6.player_id]=p6;


    player p7(ui->player6->text().toStdString());
    p7.player_id = adm.get_player_an_id();
    adm.players_map[p7.player_id]=p7;

    player p8(ui->player7->text().toStdString());
    p8.player_id = adm.get_player_an_id();
    adm.players_map[p8.player_id]=p8;

    player p9(ui->player8->text().toStdString());
    p9.player_id = adm.get_player_an_id();
    adm.players_map[p9.player_id]=p9;

    player p10(ui->player9->text().toStdString());
    p10.player_id = adm.get_player_an_id();
    adm.players_map[p10.player_id]=p10;

    player p11(ui->player10->text().toStdString());
    p11.player_id = adm.get_player_an_id();
    adm.players_map[p11.player_id]=p11;

    player players[] ={p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11};

    Team newT(ui->new_team_name->text().toStdString(),1234,players);
    int cur_league = ui->leagues->currentIndex();
    adm.leagues[cur_league].addTeam(newT);

}



void admin_form::on_tabWidget_2_tabBarClicked(int index)
{
    if(index  == 0){
        ui->leagues->clear();
        for(int i=0;i<adm.leagues.size();i++){
            ui->leagues->addItem(QString::fromStdString(adm.leagues[i].displayLeagueName()));
        }
    }
    else{

        ui->leagues_combo->clear();
        for(int i=0;i<adm.leagues.size();i++){
            ui->leagues_combo->addItem(QString::fromStdString(adm.leagues[i].displayLeagueName()));
        }

    }

}




void admin_form::on_leagues_combo_currentIndexChanged(int index)
{
    ui->teams->clear();
    qDebug() << index ;
    if(index != -1 )
    for(int i=0;i<adm.leagues[index].teams.size();i++){

         ui->teams->addItem(QString::fromStdString(adm.leagues[index].teams[i].team_name));
    }

}


void admin_form::on_teams_currentIndexChanged(int index)
{


    //get the current index of the team and league and display 11 players
   if(index !=-1 ){
    int leg_index = ui->leagues_combo->currentIndex();


         ui->p1->setText(QString::fromStdString(adm.leagues[leg_index].teams[index].players[0].pl_name));
         ui->p2->setText(QString::fromStdString(adm.leagues[leg_index].teams[index].players[1].pl_name));
         ui->p3->setText(QString::fromStdString(adm.leagues[leg_index].teams[index].players[2].pl_name));
         ui->p4->setText(QString::fromStdString(adm.leagues[leg_index].teams[index].players[3].pl_name));
         ui->p5->setText(QString::fromStdString(adm.leagues[leg_index].teams[index].players[4].pl_name));
         ui->p6->setText(QString::fromStdString(adm.leagues[leg_index].teams[index].players[5].pl_name));
         ui->p7->setText(QString::fromStdString(adm.leagues[leg_index].teams[index].players[6].pl_name));
         ui->p8->setText(QString::fromStdString(adm.leagues[leg_index].teams[index].players[7].pl_name));
         ui->p9->setText(QString::fromStdString(adm.leagues[leg_index].teams[index].players[8].pl_name));
         ui->p10->setText(QString::fromStdString(adm.leagues[leg_index].teams[index].players[9].pl_name));
         ui->p11->setText(QString::fromStdString(adm.leagues[leg_index].teams[index].players[10].pl_name));

    }

}




void admin_form :: clear_player_edit_team(){
    ui->p1->clear();
    ui->p2->clear();
    ui->p3->clear();
    ui->p4->clear();
    ui->p5->clear();
    ui->p6->clear();
    ui->p7->clear();
    ui->p8->clear();
    ui->p9->clear();
    ui->p10->clear();
    ui->p11->clear();

}

void admin_form::on_pushButton_4_clicked()
{



   // save the new_name again  in the leagues
    // save it in the map also
   int leg_index = ui->leagues_combo->currentIndex();
    int team_index = ui->teams->currentIndex();

    adm.leagues[leg_index].teams[team_index].players[0].pl_name = ui->p1->text().toStdString();
    adm.players_map[adm.leagues[leg_index].teams[team_index].players[0].player_id].pl_name=ui->p1->text().toStdString();

    adm.leagues[leg_index].teams[team_index].players[1].pl_name = ui->p2->text().toStdString();
    adm.players_map[adm.leagues[leg_index].teams[team_index].players[1].player_id].pl_name=ui->p2->text().toStdString();

    adm.leagues[leg_index].teams[team_index].players[2].pl_name = ui->p3->text().toStdString();
    adm.players_map[adm.leagues[leg_index].teams[team_index].players[2].player_id].pl_name=ui->p3->text().toStdString();

    adm.leagues[leg_index].teams[team_index].players[3].pl_name = ui->p4->text().toStdString();
    adm.players_map[adm.leagues[leg_index].teams[team_index].players[3].player_id].pl_name=ui->p4->text().toStdString();

    adm.leagues[leg_index].teams[team_index].players[4].pl_name = ui->p5->text().toStdString();
    adm.players_map[adm.leagues[leg_index].teams[team_index].players[4].player_id].pl_name=ui->p5->text().toStdString();

    adm.leagues[leg_index].teams[team_index].players[5].pl_name = ui->p6->text().toStdString();
    adm.players_map[adm.leagues[leg_index].teams[team_index].players[5].player_id].pl_name=ui->p6->text().toStdString();

    adm.leagues[leg_index].teams[team_index].players[6].pl_name = ui->p7->text().toStdString();
    adm.players_map[adm.leagues[leg_index].teams[team_index].players[6].player_id].pl_name=ui->p7->text().toStdString();

    adm.leagues[leg_index].teams[team_index].players[7].pl_name = ui->p8->text().toStdString();
    adm.players_map[adm.leagues[leg_index].teams[team_index].players[7].player_id].pl_name=ui->p8->text().toStdString();

    adm.leagues[leg_index].teams[team_index].players[8].pl_name = ui->p9->text().toStdString();
    adm.players_map[adm.leagues[leg_index].teams[team_index].players[8].player_id].pl_name=ui->p9->text().toStdString();

    adm.leagues[leg_index].teams[team_index].players[9].pl_name = ui->p10->text().toStdString();
    adm.players_map[adm.leagues[leg_index].teams[team_index].players[9].player_id].pl_name=ui->p10->text().toStdString();

    adm.leagues[leg_index].teams[team_index].players[10].pl_name = ui->p11->text().toStdString();
    adm.players_map[adm.leagues[leg_index].teams[team_index].players[10].player_id].pl_name=ui->p11->text().toStdString();



    //on_teams_currentIndexChanged(team_index);




}


/*void admin_form::on_admin_form_rejected()
{
  //  save_data();

}*/


void admin_form::on_pushButton_3_clicked()
{
    std::ofstream outFile("C:/Users/tarek/Documents/hello_world/leagues.txt");

    if (outFile.is_open())
    {

         qDebug() << "hello" << QDir::currentPath() ;

         // Write the number of leagues
         outFile << adm.gw_num <<std::endl;
         outFile << adm.leagues.size() << std::endl;

         // Write the data for each league
         for (int leagueindx =0;leagueindx<adm.leagues.size();leagueindx++)
         {
            // Write the league name and ID
            outFile <<adm.leagues[leagueindx].displayLeagueName() << std::endl;
            outFile << adm.leagues[leagueindx].getLeagueId() << std::endl;


            outFile << adm.leagues[leagueindx].teams.size() << std::endl;

            // Write the data for each team
            for (int teamindx=0;teamindx<adm.leagues[leagueindx].teams.size();teamindx++)
            {
                // Write the team name and ID
                outFile << adm.leagues[leagueindx].teams[teamindx].team_name << std::endl;
                outFile << adm.leagues[leagueindx].teams[teamindx].team_id << std::endl;

                // Write the data for each player in the team
                for (int plindx=0 ; plindx<11;plindx++)
                {
                    // Write the player name, ID, price, and goals
                    outFile << adm.leagues[leagueindx].teams[teamindx].players[plindx].pl_name << std::endl;
                    outFile << adm.leagues[leagueindx].teams[teamindx].players[plindx].player_id << std::endl;
                    outFile << adm.leagues[leagueindx].teams[teamindx].players[plindx].price << std::endl;

                    for (int i = 0; i < 36; i++)
                    {
                        outFile << adm.leagues[leagueindx].teams[teamindx].players[plindx].arr_goals[i] << " ";
                    }
                    outFile << std::endl;

                    for (int i = 0; i < 36; i++)
                    {
                        outFile << adm.leagues[leagueindx].teams[teamindx].players[plindx].arr_points[i] << " ";
                    }
                    outFile << std::endl;
                }
            }
         }

         // Close the file
         outFile.close();
    }
    else
    {
         std::cout << "Error: Unable to open file " << "leagues.txt" << " for writing." << std::endl;
    }

}


void admin_form::on_pushButton_5_clicked()
{
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


void admin_form::on_comboBox_2_currentIndexChanged(int index)
{

}


void admin_form::on_tabWidget_tabBarClicked(int index)
{
    //loop through all leagus and put the data in comboboxes

    ui->leagues_edit_goals->clear();
    if(index == 3){

         qDebug() << adm.leagues.size() <<" " ;
         for(int i=0;i<adm.leagues.size();i++){

            ui->leagues_edit_goals->addItem(QString::fromStdString(adm.leagues[i].leagueName));
          }

   // }

}

}


void admin_form::on_leagues_edit_goals_currentIndexChanged(int index)
{

    ui->Teams_editgoals->clear();
    if(index !=-1 ){

          for(int i=0;i<adm.leagues[index].teams.size();i++){

            ui->Teams_editgoals->addItem(QString::fromStdString(adm.leagues[index].teams[i].team_name));
          }
        }
}


void admin_form::on_Teams_editgoals_currentIndexChanged(int index)
{
        ui->player_editgoals->clear();
        int legindx = ui->leagues_edit_goals->currentIndex();
        if(index !=-1 && legindx !=-1 ){

          for(int i=0;i<11;i++){

            ui->player_editgoals->addItem(QString::fromStdString(adm.leagues[legindx].teams[index].players[i].pl_name));
          }
        }

}


void admin_form::on_player_editgoals_currentIndexChanged(int index)
{


        //push the player in the combo box

       int legindx = ui->leagues_edit_goals->currentIndex();
        int tmindx = ui->Teams_editgoals->currentIndex();
       if(legindx != -1 && tmindx != -1 && index != -1){
          ui->player_name_edit_goals->setText(QString::fromStdString(adm.leagues[legindx].teams[tmindx].players[index].pl_name));

       ui->Goalsscored->setValue(adm.leagues[legindx].teams[tmindx].players[index].arr_goals[adm.gw_num]);

          ui->price_edit->setValue(adm.leagues[legindx].teams[tmindx].players[index].price);
       }
}


void admin_form::on_savenewgoals_clicked()
{
       int legindx = ui->leagues_edit_goals->currentIndex();
       int tmindx = ui->Teams_editgoals->currentIndex();
       int plindx = ui->player_editgoals->currentIndex();


       if(legindx != -1 && tmindx != -1 && plindx != -1 && adm.gw_num >0){

       adm.leagues[legindx].teams[tmindx].players[plindx].update_goals(adm.gw_num,ui->Goalsscored->value());
       if(ui->price_edit->value() !=0.0 ){

            adm.leagues[legindx].teams[tmindx].players[plindx].price =  ui->price_edit->value();
       }

        }

}


void admin_form::on_NEXt_GW_clicked()
{




        for(int i=0;i<adm.leagues.size();i++){

             for(int j=0;j<adm.leagues[i].teams.size();j++){

                 for(int k=0;k<11;k++){

                        adm.leagues[i].teams[j].players[k].update_points(adm.gw_num);


                        if(adm.leagues[i].teams[j].players[k].price != 99.99 || adm.leagues[i].teams[j].players[k].price != 100000 ){


                            adm.leagues[i].teams[j].players[k].update_price_auto(adm.gw_num);

                        }


                    }
           }

        }

        adm.gw_num++;
        ui->GW_number->setText(QString::number(adm.gw_num));



}


void admin_form::on_tabWidget_currentChanged(int index)
{
        if(index == 0){

             ui->GW_number->setText(QString::number(adm.gw_num));
             home_labels_edit();
        }
}


void admin_form::on_leagues_currentIndexChanged(int index)
{

}

