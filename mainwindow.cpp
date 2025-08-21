#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"connection.h"
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Model_tabLiv= new QSqlQueryModel();
    ui->setupUi(this);
    ui->tabLiv->setModel(Model_tabLiv);
    Connection c;
    if (c.createconnect() == false )
    {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("connection failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                            QObject::tr("connection succes.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
    l.afficher(Model_tabLiv) ;
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





