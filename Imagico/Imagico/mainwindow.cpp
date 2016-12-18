#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ajouterdialogfiche.h"
#include <iostream>
#include "QDomDocument"
#include"QDomElement"
#include"QFile"
#include"QFileDialog"
#include"QMessageBox"
#include"QTextStream"

//QMAKE_CXXFLAGS += std=gnu++14

using namespace std;

//git test

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

     auto NomFichier = QFileDialog::getOpenFileName(this,"I-magico Ouvrir fichier XML",
                                                    QDir::rootPath(),"Fichier XML (*.xml)");
    QFile fichier(NomFichier);

    //tester si le fichier est vide, si oui alors retour
    if (NomFichier.isEmpty())
    {
        return;
    }

    if (!fichier.open(QIODevice::ReadOnly  | QIODevice::Text))
    {
           QMessageBox::critical(this,"Erreur",fichier.errorString());
            return;
    }

    //sauvegarder le contenu du fichier xml dans une variable doc

    QDomDocument doc;
    doc.setContent(&fichier);
    fichier.close();

    //Parcourir le fichier xml

    int i(0);
    auto root   = doc.firstChild().toElement(); //l'element parent "FICHESTECNIQUES"
    auto nbfils = root.firstChild().toElement();
    while(!nbfils.isNull())
    {
        i++;

        //on recuperer l'attribu et la sauvegarder dans une variable attr
        auto Numero = nbfils.attribute("Numero");
        auto Source = nbfils.firstChild().toElement().text();
        auto Titre = nbfils.firstChild().nextSibling().toElement().text();
        auto Cout  = nbfils.firstChild().nextSibling().nextSibling().toElement().text();
        auto Acces  = nbfils.firstChild().nextSibling().nextSibling().nextSibling().toElement().text();


        AjouterFicheTechnique(FichetechniqueImage(Source, Titre, Numero,Cout, Acces));

        //on passe au 2ème fiche technique de l'image suivante => le 2ème parent dans notre fichier xml
        nbfils = nbfils.nextSibling().toElement();
    }
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

void MainWindow::on_actionPermitons_triggered()
{
    cout<< "good bye";
    close();
}

void MainWindow::on_actionNouveau_triggered()
{
    //code c++
    cout<< "ajouter une nouvelle image"<<endl;
}
