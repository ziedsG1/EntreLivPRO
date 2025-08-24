#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QSqlQueryModel>
#include"livreur.h"
#include"vehicule.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_goLivreur_clicked();

    void on_retour_ajoutLiv_clicked();

    void on_ajoutLiv_clicked();


    void on_retourChoix_clicked();

    void on_retourChoix2_clicked();

    void on_goVehicule_clicked();

    void on_RetourChoix2_clicked();

    void on_suppLiv_clicked();

    void on_triLiv_currentTextChanged(const QString &arg1);

    void on_rechLiv_textChanged(const QString &arg1);

    void on_retourVih_clicked();

    void on_ajoutV_clicked();

    void on_triveh_currentTextChanged(const QString &arg1);

    void on_rechveh_textChanged(const QString &arg1);

    void on_conf_ajoutLiv_clicked();

    void on_ajoutVih_clicked();

private:
    Ui::MainWindow *ui;
    QSqlQueryModel *Model_tabLiv ;
    QSqlQueryModel *Model_tabveh ;
    Livreur l ;
    Vehicule v ;
};
#endif // MAINWINDOW_H
