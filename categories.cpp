#include "categories.h"
#include "qsqlquery.h"

categories::categories() {}
categories::categories(int i,QString n)
{
    id=i ;
     name=n;
}
bool categories::add()
{
    QSqlQuery query;
    query.prepare("INSERT INTO categorie (ID,name ) values(:id,:name)");
    query.bindValue(":id",id);
    query.bindValue(":name",name);
    return query.exec();
}
QSqlQueryModel*dispal()
{
    QSqlQueryModel*model=new QSqlQueryModel();
    model->setQuery("select ID,name from categorie ");
    return model;

}
bool categories:: modify()
{
    QSqlQuery query;
    QString querystring;
    querystring="update into categorie set ";
    bool firstcase=true;
    if(!name.isEmpty())
    {
        if(!firstcase)querystring+=",";
        querystring+="name=:name";
        firstcase = false;
    }
    if (firstcase) {

        return false;
    }
    querystring += " WHERE id=:id";


    query.prepare(querystring);
    if(!name.isEmpty())query.bindValue(":name",name);
    query.bindValue(":id",id);


    return query.exec();

}
bool _delete(int id)
{
    QSqlQuery query;
    query.prepare("DELETE from acticity_log where(id=:id");
    query.bindValue(":id",id);
    return query.exec();


}
