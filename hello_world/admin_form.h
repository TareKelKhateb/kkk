#ifndef ADMIN_FORM_H
#define ADMIN_FORM_H

#include <QDialog>
#include "admin.h"
#include "QDebug"
#include <fstream>
#include <QCloseEvent>

namespace Ui {
class admin_form;
}

class admin_form : public QDialog
{
    Q_OBJECT

public:
    explicit admin_form(QWidget *parent = nullptr);
    ~admin_form();
    void home_labels_edit();

private slots:
   // void admin_form::reject();
    void save_data();
    void clear_player_edit_team();

    void on_pushButton_clicked();

    void on_ADD_clicked();

    void on_pushButton_2_clicked();



    void on_tabWidget_2_tabBarClicked(int index);




    void on_leagues_combo_currentIndexChanged(int index);

    void on_teams_currentIndexChanged(int index);



    void on_pushButton_4_clicked();



    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_tabWidget_tabBarClicked(int index);

    void on_leagues_edit_goals_currentIndexChanged(int index);

    void on_Teams_editgoals_currentIndexChanged(int index);

    void on_player_editgoals_currentIndexChanged(int index);

    void on_savenewgoals_clicked();

    void on_NEXt_GW_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_leagues_currentIndexChanged(int index);

private:
    Ui::admin_form *ui;
};

#endif // ADMIN_FORM_H
