#ifndef ADMIN_HOME_H
#define ADMIN_HOME_H

#include <QWidget>

namespace Ui {
class admin_home;
}

class admin_home : public QWidget
{
    Q_OBJECT

public:
    explicit admin_home(QWidget *parent = nullptr);
    ~admin_home();

private:
    Ui::admin_home *ui;
};

#endif // ADMIN_HOME_H
