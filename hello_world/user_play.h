#ifndef USER_PLAY_H
#define USER_PLAY_H

#include <QDialog>
#include"user.h"
#include"mainwindow.h"
#include "admin.h"
#include <fstream>
#include"player_informationn.h"

namespace Ui {
class user_play;
}

class user_play : public QDialog
{
    Q_OBJECT

public:
    explicit user_play(QWidget *parent = nullptr);
    ~user_play();
    void load_data();
    player the_info_player();
    player player_info_req();
    void load_tmp();
    user main_user;
    admin adm;
    map<int,player>map_players;
    player tmp[5];
    double  tmpbudget = 0;
    int p_select =-1;
    priority_queue<pair<int,string>> user_sorted_point;



private slots:
    void on_pushButton_clicked();

    void on_Home_clicked();

    void on_TSM_clicked();

    void on_STANDING_clicked();

    void on_Leagues_currentIndexChanged(int index);

    void on_Teams_currentIndexChanged(int index);

    void on_PLayers_currentIndexChanged(int index);

    void on_p1p_clicked();

    void on_p2p_clicked();

    void on_p3p_clicked();

    void on_p4p_clicked();

    void on_p5p_clicked();

    void on_PLayer_info_clicked();

    void on_BUY_clicked();

    void on_BUY_2_clicked();

    void on_pushButton_2_clicked();

    void on_gww_2_currentIndexChanged(int index);

    void on_search_player_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::user_play *ui;
    QTimer *timer;
};

#endif // USER_PLAY_H
