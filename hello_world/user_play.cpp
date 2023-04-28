#include "user_play.h"
#include "ui_user_play.h"

user_play::user_play(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_play)
{
    ui->setupUi(this);


}

user_play::~user_play()
{
    delete ui;
}

void user_play::on_pushButton_clicked()
{
    MainWindow m;
    main_user = m.user_number();
    ui->label->setText(QString::fromStdString(main_user.get_username()));


}

