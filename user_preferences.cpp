#include "user_preferences.h"
#include "qsqlquery.h"

user_preferences::user_preferences() {}
user_preferences::user_preferences(int i ,QString sn ,QString sv )
{
    id=i;
    setting_name=sn;
    setting_value=sv;
}
bool user_preferences::add()
{
    QSqlQuery query;
    query.prepare("INSERT INTO user_preferences (ID,setting_name,setting_value ) values(:id,:sn,:sv)");
    query.bindValue(":id",id);
    query.bindValue(":sn",setting_name);
    query.bindValue(":sv",setting_value);
    return query.exec();

}
QSqlQueryModel* user_preferences::dispal()
{
    QSqlQueryModel*model=new QSqlQueryModel();
    model->setQuery("select ID,setting_name,setting_value from user_preferences ");
    return model;



}
bool user_preferences::modify()
{
    QSqlQuery query;
    QString querystring;
    querystring="update into user_preferences set ";
    bool firstcase=true;
    if(!setting_name.isEmpty())
    {
        if(!firstcase)querystring+=",";
        querystring+="setting_name=:sn";
        firstcase = false;
    }
    if(!setting_name.isEmpty())
    {
        if(!firstcase)querystring+=",";
        querystring+="setting_value=:sv";
        firstcase = false;
    }
    if (firstcase) {

        return false;
    }
    querystring += " WHERE id=:id";


    query.prepare(querystring);
    if(!setting_name.isEmpty())query.bindValue(":name",setting_name);
    if(!setting_value.isEmpty())query.bindValue(":name",setting_value);
    query.bindValue(":id",id);


    return query.exec();

}
bool user_preferences::_delete()
{
    QSqlQuery query;
    query.prepare("DELETE from user_preferences where(id=:id");
    query.bindValue(":id",id);
    return query.exec();

}
