
#include "player_informationn.h"
#include "ui_player_informationn.h"

player_informationn::player_informationn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::player_informationn)
{

    ui->setupUi(this);

    user_play u;
    cur=u.the_info_player();
    //qDebug()<<cur.player_id<<"sure";
    ui->player_name_info->setText(QString::fromStdString(cur.pl_name));
    ui->Total_points_info->setText(QString::number(cur.totalpoints()));
    show_gw_points();


}

player_informationn::~player_informationn()
{
    delete ui;
}

void player_informationn::return_the_player(){


}



void player_informationn::show_gw_points(){

    for(int i=1;i<=36;i++){
        ui->ALL_GW->addItem(QString::number(i));
    }
}

void player_informationn::on_ALL_GW_currentIndexChanged(int index)
{
    if(index!=-1){
        ui->Gw_points_per_each->setText(QString::number(cur.arr_points[index]));
    }
}

