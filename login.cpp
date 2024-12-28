#include "login.h"
#include "ui_login.h"
#include<QSqlQuery>
login::login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}
login::login(int id,int age,int telephone,QString email,QString name)
{
    this->id=id;
    this->age=age;
    this->telephone=telephone;
    this->email=email;
    this->name=name;

}
bool login::_register()
{
    QSqlQuery query;
    query.prepare("insert int login (id,age,telephone,email,name) values (:id,:age,:telephone,:email,:name)  ");
    query.bindValue(":id",id);
    query.bindValue(":age",age);
    query.bindValue(":telephone",telephone);
    query.bindValue(":email",email);
    query.bindValue(":name",name);
    return query.exec();

}

void login::_login()
{


}

login::~login()
{
    delete ui;
}
