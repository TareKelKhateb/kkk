#ifndef PLAYER_INFORMATIONN_H
#define PLAYER_INFORMATIONN_H

#include <QDialog>
#include "user_play.h"
namespace Ui {
class player_informationn;
}

class player_informationn : public QDialog
{
    Q_OBJECT

public:
    explicit player_informationn(QWidget *parent = nullptr);
    ~player_informationn();
    void show_gw_points();
    void  return_the_player();
    player cur;



private slots:
    void on_ALL_GW_currentIndexChanged(int index);

private:
    Ui::player_informationn *ui;
};

#endif // PLAYER_INFORMATIONN_H
