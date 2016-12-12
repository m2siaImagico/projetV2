#include "fichetechniqueimage.h"


FichetechniqueImage::FichetechniqueImage(const QString &Source, const QString &titre, const QString &Numero,
                                         const QString &Cout, const QString &Acces)
{
        _Source=Source ;
        _titre =titre ;
        _Numero = Numero;
        _Cout = Cout;
        _Acces = Acces;
}

void FichetechniqueImage::setSource(const QString &Source)
{
    _Source = Source;
}

void FichetechniqueImage::setTitre(const QString &titre)
{
    _titre = titre;
}

void FichetechniqueImage::setNumero(const QString &Numero)
{
    _Numero = Numero;
}

void FichetechniqueImage::setCout(const QString &Cout)
{
    _Cout = Cout;
}

void FichetechniqueImage::setAcces(const QString &Acces)
{
    _Acces = Acces;
}

QString FichetechniqueImage::getSource() const
{
    return _Source;
}

QString FichetechniqueImage::getTitre() const
{
    return _titre;
}

QString FichetechniqueImage::getNumero() const
{

}

QString FichetechniqueImage::getCout() const
{
    return _Cout;
}

QString FichetechniqueImage::getAcces() const
{
    return _Acces;
}
