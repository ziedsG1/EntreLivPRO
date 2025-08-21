#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("EntreLiv1");
    db.setUserName("system");
    db.setPassword("sys");
if (db.open())
test=true;





    return  test;
}
