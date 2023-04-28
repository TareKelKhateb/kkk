#include "user_play.h"
#include "ui_user_play.h"


user_play::user_play(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_play)
{
    ui->setupUi(this);
    load_data();
    on_Home_clicked();
    MainWindow m;
    main_user = m.user_number();



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




}





void user_play::on_Home_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->GW->setText(QString::number(adm.gw_num));
    ui->Points->setText(QString::number(main_user.points[adm.gw_num-2]));
    ui->TOTAL_POINTS->setText(QString::number(main_user.total_points));

    ui->p1->setText(QString::fromStdString(main_user.players[0].pl_name));
    ui->p2->setText(QString::fromStdString(main_user.players[1].pl_name));
    ui->p3->setText(QString::fromStdString(main_user.players[2].pl_name));
    ui->p4->setText(QString::fromStdString(main_user.players[3].pl_name));
    ui->p5->setText(QString::fromStdString(main_user.players[4].pl_name));


}


void user_play::on_TSM_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}




void user_play::on_STANDING_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

