#ifndef PLATEFORME_H
#define PLATEFORME_H

#include <QGraphicsItem>
#include <QPainter>

class Plateforme{
private:
    QGraphicsRectItem* plateforme;
public:
    Plateforme(int,int,int,int);
    QGraphicsRectItem* getPlateforme(){return plateforme;}
    virtual ~Plateforme();
};

#endif // PLATEFORME_H
