#include "admin_home.h"
#include "ui_admin_home.h"

admin_home::admin_home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin_home)
{
    ui->setupUi(this);
}

admin_home::~admin_home()
{
    delete ui;
}
