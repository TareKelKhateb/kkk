#ifndef USER_PLAY_H
#define USER_PLAY_H

#include <QDialog>
#include"user.h"
#include"mainwindow.h"
#include "admin.h"
#include <fstream>


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
    user main_user;
    admin adm;
    map<int,player>map_players;



private slots:
    void on_pushButton_clicked();

    void on_Home_clicked();

    void on_TSM_clicked();

    void on_STANDING_clicked();

private:
    Ui::user_play *ui;
};

#endif // USER_PLAY_H
