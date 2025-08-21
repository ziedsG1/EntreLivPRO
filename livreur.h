#ifndef LIVREUR_H
#define LIVREUR_H

#include <QString>
#include<QSqlQueryModel>
#include<QSqlQuery>
class Livreur {
private:
    int id;
    QString nom;
    QString prenom;
    int num;
    QString email;

public:
    // --- Constructeurs ---
    Livreur() = default;
    Livreur(int id, const QString& nom, const QString& prenom, int num, const QString& email)
        : id(id), nom(nom), prenom(prenom), num(num), email(email) {}

    // --- Getters ---
    int getId() const { return id; }
    QString getNom() const { return nom; }
    QString getPrenom() const { return prenom; }
    int getNum() const { return num; }
    QString getEmail() const { return email; }

    // --- Setters ---
    void setId(int newId) { id = newId; }
    void setNom(const QString& newNom) { nom = newNom; }
    void setPrenom(const QString& newPrenom) { prenom = newPrenom; }
    void setNum(int newNum) { num = newNum; }
    void setEmail(const QString& newEmail) { email = newEmail; }


    void afficher(QSqlQueryModel *model);
    bool supprimer(int id);
    void trie(QSqlQueryModel *model, QString critere);
    void recherche(QSqlQueryModel *model , QString critere , QString ch);

};

#endif // LIVREUR_H
