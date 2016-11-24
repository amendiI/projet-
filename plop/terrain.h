#ifndef TERRAIN_H
#define TERRAIN_H

#include <QObject>
#include <QRect>

class terrain : public QObject
{
private:

    char type;
    int resistance;
    bool bloque;
    QRect* aff;

    //Q_OBJECT
public:
    //explicit terrain(QObject *parent = 0);
    terrain(char type,bool bloque,int resistance);//constructeur
    void impact();//change les données car explosion

    char gettype() const;//retourne le type
    bool getbloque() const;//renvoi 1 si le terrain est bloquant
    int getresistance() const;//retourne la resistance actuelle du terrain

    void setall(char type,bool bloque,int resistance);
    void settype(char type);
    void setbloque(bool bloque);
    void setresistance(int resistance);
    void setaff(int x,int y);

signals:

public slots:
};

#endif // TERRAIN_H
