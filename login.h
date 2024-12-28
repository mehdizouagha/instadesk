#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    login(int,int,int,QString,QString);
    bool _register();
    void _login();

private:
    Ui::login *ui;
    int id,age,telephone;
    QString email,name;
};

#endif // LOGIN_H
