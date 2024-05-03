#include "inventaire.h"

Inventaire::Inventaire(){
    inventaire = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/rien.png")));
    inventaire->setScale(2);

    EpeeInventaire = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/rien.png")));
    EpeeInventaire->setScale(0.2);

    ArmureInventaire = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/rien.png")));
    ArmureInventaire->setScale(0.2);

    UpgradeArmure = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/rien.png")));
    UpgradeArmure->setScale(0.5);

    UpgradeEpee = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/rien.png")));
    UpgradeEpee->setScale(0.5);

    itemBois = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/rien.png")));
    itemBois->setScale(0.5);

    itemPierre = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/rien.png")));
    itemPierre->setScale(0.5);

    itemFer = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/rien.png")));
    itemFer->setScale(0.5);

    itemDiamant = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/rien.png")));
    itemDiamant->setScale(0.5);

    nbBois = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/rien.png")));
    nbBois->setScale(0.15);

    nbPerre = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/rien.png")));
    nbPerre->setScale(0.15);

    nbFer = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/rien.png")));
    nbFer->setScale(0.15);

    nbDiamant = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/rien.png")));
    nbDiamant->setScale(0.15);
}

Inventaire::~Inventaire() {

}
