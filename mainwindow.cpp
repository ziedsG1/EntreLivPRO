#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"connection.h"
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Model_tabLiv= new QSqlQueryModel();
    Model_tabveh= new QSqlQueryModel();
    ui->setupUi(this);
    ui->tabLiv->setModel(Model_tabLiv);
    ui->tabveh->setModel(Model_tabveh);
    Connection c;
    if (!c.createconnect())
    {
        QMessageBox::critical(
            nullptr,
            QObject::tr("Base de données"),
            QObject::tr("Échec de connexion.\n"
                        "Cliquez sur Annuler pour quitter."),
            QMessageBox::Cancel
        );
    }
    else
    {
        QMessageBox::information(
            nullptr,
            QObject::tr("Base de données"),
            QObject::tr("Connexion réussie.\n"
                        "Cliquez sur OK pour continuer."),
            QMessageBox::Ok
        );
    }
    l.afficher(Model_tabLiv) ;
    v.afficher(Model_tabveh);
    ui->choix->show();
    ui->livreur->hide();
    ui->grp_ajoutLiv->hide();
    ui->vehicule->hide();
    ui->grp_ajoutVih->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_goLivreur_clicked()
{
    ui->livreur->show();
    ui->choix->hide();
    ui->grp_ajoutLiv->hide();
    ui->grp_ajoutVih->hide();

}


void MainWindow::on_retour_ajoutLiv_clicked()
{
    ui->livreur->show();
    ui->choix->hide();
    ui->grp_ajoutLiv->hide();
}


void MainWindow::on_ajoutLiv_clicked()
{
    ui->livreur->hide();
    ui->choix->hide();
    ui->grp_ajoutLiv->show();
    ui->grp_ajoutVih->hide();

}

void MainWindow::on_retourChoix_clicked()
{
    ui->livreur->hide();
    ui->choix->show();
    ui->grp_ajoutLiv->hide();
    ui->grp_ajoutVih->hide();


}


void MainWindow::on_retourChoix2_clicked()
{
    ui->livreur->hide();
    ui->choix->show();
    ui->grp_ajoutLiv->hide();
    ui->vehicule->hide();
    ui->grp_ajoutVih->hide();


}


void MainWindow::on_goVehicule_clicked()
{
    ui->livreur->hide();
    ui->choix->hide();
    ui->grp_ajoutLiv->hide();
    ui->vehicule->show();
    ui->grp_ajoutVih->hide();

}


void MainWindow::on_RetourChoix2_clicked()
{
    ui->livreur->hide();
    ui->choix->show();
    ui->grp_ajoutLiv->hide();
    ui->vehicule->hide();
    ui->grp_ajoutVih->hide();
}


void MainWindow::on_suppLiv_clicked()
{
    if(l.supprimer(ui->rechLiv->text().toInt()))
    {
        QMessageBox::critical(nullptr, QObject::tr("suppretion succes"),
                            QObject::tr("succes.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        l.afficher(Model_tabLiv);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("suppretion echouer"),
                            QObject::tr("echouer.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_triLiv_currentTextChanged(const QString &arg1)
{
    l.trie(Model_tabLiv , arg1);
}

void MainWindow::on_rechLiv_textChanged(const QString &arg1)
{
    l.recherche(Model_tabLiv , ui->rechLiv->text() , arg1);
}



void MainWindow::on_ajoutV_clicked()
{
    ui->livreur->hide();
    ui->choix->hide();
    ui->grp_ajoutLiv->hide();
    ui->vehicule->hide();
    ui->grp_ajoutVih->show();

}



void MainWindow::on_retourVih_clicked()
{
    ui->livreur->hide();
    ui->choix->hide();
    ui->grp_ajoutLiv->hide();
    ui->vehicule->show();
    ui->grp_ajoutVih->hide();

}






void MainWindow::on_triveh_currentTextChanged(const QString &arg1)
{
    v.trie(Model_tabveh , arg1);
}

void MainWindow::on_rechveh_textChanged(const QString &arg1)
{
    v.recherche(Model_tabveh , ui->triveh->currentText() , arg1);
}

void MainWindow::on_conf_ajoutLiv_clicked()
{
    Livreur l(ui->ID->text().toInt(),
              ui->NOM->text(),
              ui->PRENOM->text(),
              ui->NUM->text().toInt(),
              ui->EMAIL->text());
    if(l.ajout())
    {
        QMessageBox::critical(
            nullptr,
            QObject::tr("Base de données"),
            QObject::tr("Échec de connexion.\n"
                        "Cliquez sur Annuler pour quitter."),
            QMessageBox::Cancel
        );
        l.trie(Model_tabLiv , ui->triLiv->currentText());
        ui->NOM->clear();
    }
    else
    {
        QMessageBox::information(
            nullptr,
            QObject::tr("Base de données"),
            QObject::tr("Connexion réussie.\n"
                        "Cliquez sur OK pour continuer."),
            QMessageBox::Ok
        );
    }
}

void MainWindow::on_ajoutVih_clicked()
{
    QString image = "";
    Vehicule v(ui->IDL->text().toInt(),
              ui->MAT->text().toInt(),
              ui->TYPE->text(),
               image
               );


    if(v.ajout())
    {
        QMessageBox::critical(
            nullptr,
            QObject::tr("Base de données"),
            QObject::tr("Échec de connexion.\n"
                        "Cliquez sur Annuler pour quitter."),
            QMessageBox::Cancel
        );
        v.trie(Model_tabveh , ui->triLiv->currentText());
        ui->IDL->clear();
        ui->MAT->clear();
        ui->TYPE->clear();
    }
    else
    {
        QMessageBox::information(
            nullptr,
            QObject::tr("Base de données"),
            QObject::tr("Connexion réussie.\n"
                        "Cliquez sur OK pour continuer."),
            QMessageBox::Ok
        );
    }
}
