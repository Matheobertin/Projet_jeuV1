#include "plateforme.h"

Plateforme::Plateforme(int v1, int v2, int v3, int v4){
    QBrush q;
    q.setTextureImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/cobble.jpg"));
    plateforme = new QGraphicsRectItem(v1, v2, v3, v4);
    plateforme->setBrush(q);
    plateforme->setPen(QPen(Qt::NoPen));
}

Plateforme::~Plateforme() {

}
