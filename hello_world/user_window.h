#ifndef USER_WINDOW_H
#define USER_WINDOW_H

#include <QDialog>
#include "user.h"
#include"mainwindow.h"
namespace Ui {
class user_window;
}

class user_window : public QDialog
{
    Q_OBJECT


public:
    explicit user_window(QWidget *parent = nullptr);
    ~user_window();
    user mnuser;

private slots:
    void on_pushButton_clicked();

private:
    Ui::user_window *ui;
    MainWindow *mw;
};

#endif // USER_WINDOW_H
