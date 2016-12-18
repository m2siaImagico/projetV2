#include "ajouterdialogfiche.h"
#include "ui_ajouterdialogfiche.h"

//test
AJouterDialogFiche::AJouterDialogFiche(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AJouterDialogFiche)
{
    ui->setupUi(this);
}

FichetechniqueImage AJouterDialogFiche::getFicheTechnique() const
{
    return _fichetech;
}

AJouterDialogFiche::~AJouterDialogFiche()
{
    delete ui;
}

void AJouterDialogFiche::on_buttonBox_accepted()
{
    //Ajoutder les données du formulaire
    _fichetech.setSource(ui->SoucheFichelineEdit->text());
    _fichetech.setTitre(ui->TitreFichelineEdit->text());
    _fichetech.setNumero(ui->NumeroFichelineEdit_4->text());
    _fichetech.setCout(ui->CoutFichelineEdit->text());
    _fichetech.setAcces(ui->accesFichelineEdit->text());

    accept();
}

void AJouterDialogFiche::on_buttonBox_rejected()
{
    reject();
}
