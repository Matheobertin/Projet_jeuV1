#include "personnage.h"

Personnage::Personnage(){
    QImage imageperso("C:/Users/mathe/OneDrive/Documents/Projet_jeu/personnage_droite1.png");
    Perso = new QGraphicsPixmapItem(QPixmap::fromImage(imageperso));
    Perso->setScale(0.2);
    Perso->setPos(Perso->pos().rx(),680);

    QImage imageheal("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Heal.png");
    Heal = new QGraphicsPixmapItem(QPixmap::fromImage(imageheal));
    Heal->setScale(0.2);

    QImage imageshield("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Shield.png");
    Shield = new QGraphicsPixmapItem(QPixmap::fromImage(imageshield));
    Shield->setScale(0.2);

    QImage imagepotionheal("C:/Users/mathe/OneDrive/Documents/Projet_jeu/PotionHeal.jpg");
    PotionHeal = new QGraphicsPixmapItem(QPixmap::fromImage(imagepotionheal));
    PotionHeal->setScale(0.05);

    QImage imagepotionshield("C:/Users/mathe/OneDrive/Documents/Projet_jeu/PotionShield.jpg");
    PotionShield = new QGraphicsPixmapItem(QPixmap::fromImage(imagepotionshield));
    PotionShield->setScale(0.05);

    QImage imagearmure("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Armure.jpg");
    Armure = new QGraphicsPixmapItem(QPixmap::fromImage(imagearmure));
    Armure->setScale(0.1);

    QImage imageepee("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Epee.jpg");
    Epee = new QGraphicsPixmapItem(QPixmap::fromImage(imageepee));
    Epee->setScale(0.1);

    nbPotionHeal = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/0.png")));
    nbPotionHeal->setScale(0.1);

    nbPotionShield = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/0.png")));
    nbPotionShield->setScale(0.1);

    c = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/c.png")));
    c->setScale(0.1);

    v = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/v.png")));
    v->setScale(0.1);

    HealNb = new QLabel("100/100");
    HealNb->setFont(QFont("Arial",15));

    ShieldNb = new QLabel("0/100");
    ShieldNb->setFont(QFont("Arial",15));
}

Personnage::~Personnage() {

}
