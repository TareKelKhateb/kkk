
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "user.h"
#include <fstream>
#include <string>
#include<bits/stdc++.h>
#include <sstream>
#include <queue>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    user user_number();
    void add_new_user(string name , string pass , string tmname);
    void save_data();
    void calc_points(int gw,map<int , player> player_map);
    void save_mainuser_data(user mnu);
    priority_queue<pair<int,string>>sorted_users();


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void load_data();

private:
    Ui::MainWindow *ui;




    //second_form *sec;
};

#endif // MAINWINDOW_H
