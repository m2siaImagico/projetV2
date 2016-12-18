#ifndef FICHETECHNIQUEIMAGE_H
#define FICHETECHNIQUEIMAGE_H

#include<QString>


class FichetechniqueImage
{
private :
    QString _Source;
    QString _titre;
    QString _Numero;
    QString _Cout;
    QString _Acces;
    QString _NomImage;

public:
    FichetechniqueImage(const QString &Source ="", const QString &titre =""
                        ,const QString &Numero ="", const QString &Cout ="",
                        const QString &Acces ="");

    //mise à jour attribues
    void setSource(const QString &Source );
    void setTitre(const QString &titre );
    void setNumero(const QString &Numero );
    void setCout(const QString &Cout );
    void setAcces(const QString &Acces );

    //recuperer attribues
    QString getSource() const;
    QString getTitre() const;
    QString getNumero() const;
    QString getCout() const;
    QString getAcces() const;
};

#endif // FICHETECHNIQUEIMAGE_H
