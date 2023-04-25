#ifndef SECONDFORM_H
#define SECONDFORM_H
#pragma once
#include <QDialog>
#include "user.h"
//#include "all_files.h"
#include"admin.h"
//admin k_admin;

namespace Ui {
class Secondform;
}

class Secondform : public QDialog
{
    Q_OBJECT


public:
    explicit Secondform(QWidget *parent = nullptr);
    ~Secondform();
    user mnuser;


private slots:
    void on_pushButton_clicked();

private:
    Ui::Secondform *ui;
};

#endif // SECONDFORM_H
