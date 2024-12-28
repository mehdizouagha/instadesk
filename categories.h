#ifndef CATEGORIES_H
#define CATEGORIES_H
#include<QString>
#include<QDate>
#include<QSqlQueryModel>
class categories
{
public:
    categories();
    ~categories();
    categories(int,QString);
    bool add();
    QSqlQueryModel*dispal();
    bool modify();
    bool _delete(int id);
private:

    int id ;
    QString name;

};

#endif // CATEGORIES_H
