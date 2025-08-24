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
    model->setQuery("SELECT * FROM livreur WHERE " + critere + " LIKE '%" + ch + "%'") ;
}
bool Livreur:: ajout()
{
    QSqlQuery query ;
    query.prepare("INSERT INTO livreur (id, nom, prenom, num, email) "
                  "VALUES (:id, :nom, :prenom, :num, :email)");
    query.bindValue(":id",    id);
    query.bindValue(":nom",   nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":num",   num);
    query.bindValue(":email", email);
    if(query.exec())
    {
        return true ;
    }
    else
    {
        return false ;
    }
}
