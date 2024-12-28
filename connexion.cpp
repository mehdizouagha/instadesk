#include "connexion.h"

connexion::connexion() {}
bool connexion::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("activity_tracker.db");

    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
    } else {
        qDebug() << "Database connected successfully!";
        qDebug() << "Database Path:"  << QSqlDatabase::database().databaseName();
        test = true;
    }



    return  test;
}
void connexion::initializeDatabase() {

    QSqlQuery query;
    if (!query.exec(R"(
        CREATE TABLE IF NOT EXISTS activity_log (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            app_name TEXT NOT NULL,
            category TEXT DEFAULT 'Uncategorized',
            start_time DATETIME NOT NULL,
            end_time DATETIME NOT NULL
        );
    )")) {
        qDebug() << "Error creating activity_log table:" << query.lastError();
    }
    if (!query.exec(R"(
        CREATE TABLE IF NOT EXISTS login (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            age INTEGER DEFAULT 'Uncategorized',
            email TEXT NOT NULL,
            telephone INTEGER NOT NULL
        );
    )")) {
        qDebug() << "Error creating login table:" << query.lastError();
    }
    if (!query.exec(R"(
        CREATE TABLE IF NOT EXISTS categories (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT UNIQUE NOT NULL
        );
    )")) {
        qDebug() << "Error creating categories table:" << query.lastError();
    }

    if (!query.exec(R"(
        CREATE TABLE IF NOT EXISTS user_preferences (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            setting_name TEXT UNIQUE NOT NULL,
            setting_value TEXT NOT NULL
        );
    )")) {
        qDebug() << "Error creating user_preferences table:" << query.lastError();
    }
}


