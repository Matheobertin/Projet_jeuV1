#include "golem.h"

Golem::Golem(int x,int y,int type){
    QImage imagegolem;
    switch(type){
        case 1:
            imagegolem = QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/golemBoisMarche1.png");
            golemVie = 20;
            attaque = 5;
            break;
        case 2:
            imagegolem = QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/golemPierreMarche1.png");
            golemVie = 40;
            attaque = 10;
            break;
        case 3:
            imagegolem = QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/golemFerMarche1.png");
            attaque = 15;
            break;
    }
    golemType = type;
    golem = new QGraphicsPixmapItem(QPixmap::fromImage(imagegolem));
    golem->setScale(0.15);
    golem->setPos(x,y);
}

Golem::~Golem() {

}
