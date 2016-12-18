#ifndef AJOUTERDIALOGFICHE_H
#define AJOUTERDIALOGFICHE_H

#include <QDialog>
#include"fichetechniqueimage.h"

namespace Ui {
class AJouterDialogFiche;
}

class AJouterDialogFiche : public QDialog
{
    Q_OBJECT

public:
    explicit AJouterDialogFiche(QWidget *parent = nullptr);
    FichetechniqueImage getFicheTechnique() const;

    ~AJouterDialogFiche();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::AJouterDialogFiche *ui;
    FichetechniqueImage _fichetech;
};

#endif // AJOUTERDIALOGFICHE_H
