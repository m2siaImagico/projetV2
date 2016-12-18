#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fichetechniqueimage.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    //le Menu principal

    void on_actionOuvrir_triggered();
    void on_actionEnregistrer_sous_triggered();
    void on_actionQuitter_triggered();
    void on_actionAjouter_triggered();
    void on_actionSupprimer_triggered();

    void on_actionPermitons_triggered();

    void on_actionNouveau_triggered();

private:

    enum{
        SOURCE,
        TITRE ,
        NUMERO ,
        COUT ,
        ACCES
    };

    Ui::MainWindow *ui;
    void AjouterFicheTechnique(const FichetechniqueImage &ptrFcheTech);

};

#endif // MAINWINDOW_H
