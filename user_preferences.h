#ifndef USER_PREFERENCES_H
#define USER_PREFERENCES_H
#include<QString>
#include<QDate>
#include<QSqlQueryModel>
#include<QSqlQuery>
class user_preferences
{
public:
    user_preferences();
    ~user_preferences();
    user_preferences(int,QString,QString);
    bool add();
    QSqlQueryModel*dispal();
    bool modify();
    bool _delete();
private:
    int id;
    QString setting_name;
    QString setting_value;
};

#endif // USER_PREFERENCES_H
