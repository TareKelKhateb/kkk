#ifndef USER_PLAY_H
#define USER_PLAY_H

#include <QDialog>
#include"user.h"
#include"mainwindow.h"

namespace Ui {
class user_play;
}

class user_play : public QDialog
{
    Q_OBJECT

public:
    explicit user_play(QWidget *parent = nullptr);
    ~user_play();

    user main_user;

private slots:
    void on_pushButton_clicked();

private:
    Ui::user_play *ui;
};

#endif // USER_PLAY_H
