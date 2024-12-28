#include "activity_log.h"
#include "qsqlquery.h"

activity_log::activity_log() {
    this->id=0;
    this->name="";
    this->categorie="";



}
activity_log::activity_log(int i,QString n ,QString c, QDate s,QDate e)
{
    id=i;
    name=n;
    categorie=c;
    start_time=s;
    end_time=e;

}
bool activity_log::add()
{
    QSqlQuery query;
    query.prepare("INSERT INTO activity_log (ID,app_name ,category,start_time,end_time) values(:id,:name,:categorie,:start_time,:end_tme)");
    query.bindValue(":id",id);
    query.bindValue(":name",name);
    query.bindValue(":categorie",categorie);
    query.bindValue(":start_time",start_time);
    query.bindValue(":end_time",end_time);
    return query.exec();
}
bool activity_log::modify()
{
    QSqlQuery query;
    QString querystring;
    querystring="update into activity_log set ";
    bool firstcase=true;
    if(!name.isEmpty())
    {
        if(!firstcase)querystring+=",";
        querystring+="app_name=:name";
        firstcase = false;
    }
    if(!categorie.isEmpty())
    {
        if(!firstcase)querystring+=",";
        querystring+="categorie=:categorie";
        firstcase = false;
    }
    if (!start_time.isNull()) {
        if (!firstcase) querystring += ", ";
        querystring += "start_time=:start_time";
        firstcase= false;
    }
    if (!end_time.isNull()) {
        if (!firstcase) querystring += ", ";
        querystring += "end_time=:end_time";
        firstcase= false;
    }
    if (firstcase) {

        return false;
    }
    querystring += " WHERE id=:id";


    query.prepare(querystring);
    if(!name.isEmpty())query.bindValue(":name",name);
    if(!categorie.isEmpty())query.bindValue(":categorie",categorie);
    if (!start_time.isNull())query.bindValue(":start_time",start_time);
    if (!end_time.isNull())query.bindValue(":end_time",end_time);
    query.bindValue(":id",id);


    return query.exec();




}
bool activity_log::_delete(int id)
{
    QSqlQuery query;
    query.prepare("DELETE from acticity_log where(id=:id");
    query.bindValue(":id",id);
    return query.exec();
}
QSqlQueryModel* activity_log::dispal()
{
    QSqlQueryModel*model=new QSqlQueryModel();
    model->setQuery("select ID,app_name ,category,start_time,end_time from activity_log ");
    return model;
}
