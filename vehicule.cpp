#include "vehicule.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>
#include <QDebug>

void Vehicule::afficher(QSqlQueryModel *model)
{
    model->setQuery("SELECT * FROM VEHICUL");
}

bool Vehicule::supprimer(int mat)
{
    QSqlQuery query;
    query.prepare("DELETE FROM VEHICUL WHERE mat = :mat");
    query.bindValue(":mat", mat);
    return query.exec();
}

void Vehicule::trie(QSqlQueryModel *model, QString critere)
{
    model->setQuery("Select * from VEHICUL order by " + critere + " ASC") ;
}

void Vehicule::recherche(QSqlQueryModel *model, QString critere, QString valeur)
{
    model->setQuery("SELECT * FROM VEHICUL WHERE " + critere + " LIKE '%" + valeur + "%'") ;
}
bool Vehicule:: ajout()
{

    QSqlQuery query ;
    query.prepare("INSERT INTO VEHICUL (matricul, type, image, id_l) "
                  "VALUES (:matricul, :type, :image, :id_l)");
    query.bindValue(":matricul", mat);
    query.bindValue(":type", type);
    query.bindValue(":image", image);
    query.bindValue(":id_l", id_L);

    if(query.exec())
    {
        return true ;
    }
    else
    {
        return false ;
    }
}
