#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ajouterdialogfiche.h"
#include <iostream>

//QMAKE_CXXFLAGS += std=gnu++14

using namespace std;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList  Structuredonnes {"Id", "Sources", "Titre", "Numero", "Cout", "Acces"};
    ui->tableWidget->setColumnCount(Structuredonnes.size());
    ui->tableWidget->setHorizontalHeaderLabels(Structuredonnes);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOuvrir_triggered()
{

}

void MainWindow::on_actionEnregistrer_sous_triggered()
{

}

void MainWindow::on_actionQuitter_triggered()
{
    close();
}

void MainWindow::on_actionAjouter_triggered()
{
    AJouterDialogFiche fc(this);

    // sil'utilisateur click sur Annuler

    if (fc.exec() == QDialog::Rejected){
     return;
    }

    //si l'utilisateur click sur Accepter

     AjouterFicheTechnique(fc.getFicheTechnique()) ;


}

void MainWindow::on_actionSupprimer_triggered()
{
    cout<<"Totot"<<endl;
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}


void MainWindow::AjouterFicheTechnique(const FichetechniqueImage &ptrFcheTech)
{
    const int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    //Ajouter une ligne


    ui->tableWidget->setItem(row,SOURCE,new QTableWidgetItem(ptrFcheTech.getSource()));
    ui->tableWidget->setItem(row,TITRE, new QTableWidgetItem(ptrFcheTech.getTitre()));
    ui->tableWidget->setItem(row, NUMERO, new QTableWidgetItem(ptrFcheTech.getNumero()));
    ui->tableWidget->setItem(row, COUT, new QTableWidgetItem(ptrFcheTech.getCout()));
    ui->tableWidget->setItem(row,ACCES, new QTableWidgetItem(ptrFcheTech.getAcces()));

}
