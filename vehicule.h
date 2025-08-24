#ifndef VEHICULE_H
#define VEHICULE_H

#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class Vehicule
{
private:
    int mat;
    QString type ;
    QString image;
    int id_L ;
public:
    // --- Constructeurs ---
    Vehicule() = default;
    Vehicule(int idL, int mat, const QString& type, const QString& image)
            : mat(mat), type(type), image(image), id_L(idL) {}
    // --- Getters ---
    int getMat() const noexcept { return mat; }
    const QString& getType() const noexcept { return type; }
    const QString& getImage() const noexcept { return image; }
    int getIdL() const noexcept { return id_L; }

        // --- Setters ---
        void setMat(int newMat) noexcept { mat = newMat; }
        void setType(const QString& newType) { type = newType; }
        void setImage(const QString& newImage) { image = newImage; }
        void setIdL(int newIdL) noexcept { id_L = newIdL; }
    // --- Méthodes Base de Données ---
    void afficher(QSqlQueryModel *model);
    bool supprimer(int mat);
    void trie(QSqlQueryModel *model, QString critere);
    void recherche(QSqlQueryModel *model, QString critere, QString valeur);
    bool ajout() ;
};

#endif // VEHICULE_H
