#ifndef ACTIVITY_LOG_H
#define ACTIVITY_LOG_H
#include<QString>
#include<QDate>
#include<QSqlQueryModel>
#include<QSqlQuery>
class activity_log
{
public:
    activity_log();
    ~activity_log();
    activity_log(int,QString,QString,QDate,QDate);
    bool add();
    QSqlQueryModel*dispal();
    bool modify();
    bool _delete(int id);

private:
    int id;
    QString name,categorie;
    QDate start_time,end_time;
};

#endif // ACTIVITY_LOG_H
