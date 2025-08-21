#include "livreur.h"
#include<QDebug>

void Livreur ::  afficher(QSqlQueryModel *model)
{
    model->setQuery("SELECT * FROM Livreur;");
}
bool Livreur :: supprimer(int id)
{
    QSqlQuery query ;
    query.prepare("delete from livreur where id=:id") ;
    query.bindValue(":id" , id) ;
    if(query.exec())
    {
        return true ;
    }
    else
    {
        return false ;
    }
}
void Livreur :: trie(QSqlQueryModel *model, QString critere)
{
    model->setQuery("Select * from livreur order by " + critere + " ASC") ;
}
void Livreur:: recherche(QSqlQueryModel *model , QString critere , QString ch)
{
    qDebug() << critere << " " << ch ;
    model->setQuery("SELECT * FROM livreur WHERE " + critere + " LIKE '%" + ch + "%'") ;
}
