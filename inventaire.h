#ifndef INVENTAIRE_H
#define INVENTAIRE_H

#include <QGraphicsItem>
#include <QLabel>
#include <QDebug>

class Inventaire{
private:
    QGraphicsPixmapItem *inventaire;
    QGraphicsPixmapItem *EpeeInventaire;
    QGraphicsPixmapItem *ArmureInventaire;
    QGraphicsPixmapItem *UpgradeArmure;
    QGraphicsPixmapItem *UpgradeEpee;
    QGraphicsPixmapItem *itemBois;
    QGraphicsPixmapItem *itemPierre;
    QGraphicsPixmapItem* itemFer;
    QGraphicsPixmapItem* itemDiamant;
    QGraphicsPixmapItem* nbBois;
    QGraphicsPixmapItem* nbPerre;
    QGraphicsPixmapItem* nbFer;
    QGraphicsPixmapItem* nbDiamant;
    int nbnbbois = 0;
    int nbnbpierre = 0;
    int nbnbfer = 0;
    int nbnbdiamant = 0;
public:
    Inventaire();
    virtual ~Inventaire();
    QGraphicsPixmapItem* getInventaire(){return inventaire;}
    QGraphicsPixmapItem* getEpeeInventaire(){return EpeeInventaire;}
    QGraphicsPixmapItem* getArmureInventaire(){return ArmureInventaire;}
    QGraphicsPixmapItem* getUpgradeArmure(){return UpgradeArmure;}
    QGraphicsPixmapItem* getUpgradeEpee(){return UpgradeEpee;}
    QGraphicsPixmapItem* getitemBois(){return itemBois;}
    QGraphicsPixmapItem* getitemPierre(){return itemPierre;}
    QGraphicsPixmapItem* getitemFer(){return itemFer;}
    QGraphicsPixmapItem* getitemDiamant(){return itemDiamant;}
    QGraphicsPixmapItem* getnbBois(){return nbBois;}
    QGraphicsPixmapItem* getnbPierre(){return nbPerre;}
    QGraphicsPixmapItem* getnbFer(){return nbFer;}
    QGraphicsPixmapItem* getnbDiamant(){return nbDiamant;}
    int getnbnbbois(){return nbnbbois;}
    int getnbnbpierre(){return nbnbpierre;}
    int getnbnbfer(){return nbnbfer;}
    int getnbnbdiamant(){return nbnbdiamant;}
    void setitem(int a){
        switch (a) {
        case 1:
            nbnbbois++;
            break;
        case 2:
            nbnbpierre++;
            break;
        case 3:
            nbnbfer++;
            break;
        case 4:
            nbnbdiamant++;
            break;
        default:
            break;
        }
    }
    void setImage(QImage image){
        inventaire->setPixmap(QPixmap::fromImage(image));
        EpeeInventaire->setPixmap(QPixmap::fromImage(image));
        ArmureInventaire->setPixmap(QPixmap::fromImage(image));
        UpgradeArmure->setPixmap(QPixmap::fromImage(image));
        UpgradeEpee->setPixmap(QPixmap::fromImage(image));
        itemBois->setPixmap(QPixmap::fromImage(image));
        itemPierre->setPixmap(QPixmap::fromImage(image));
        itemFer->setPixmap(QPixmap::fromImage(image));
        itemDiamant->setPixmap(QPixmap::fromImage(image));
        nbBois->setPixmap(QPixmap::fromImage(image));
        nbPerre->setPixmap(QPixmap::fromImage(image));
        nbFer->setPixmap(QPixmap::fromImage(image));
        nbDiamant->setPixmap(QPixmap::fromImage(image));
    }
    void setImage(){
        inventaire->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/inventaire.png")));
        //EpeeInventaire->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Epee.jpg")));
        //ArmureInventaire->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Armure.jpg")));
        UpgradeArmure->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/upgrade.png")));
        UpgradeEpee->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/upgrade.png")));
        itemBois->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/bois.jpg")));
        itemPierre->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/pierre.jpg")));
        itemFer->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/fer.jpg")));
        itemDiamant->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/diamant.jpg")));
        nbBois->setPixmap(QPixmap::fromImage(QImage(QString("C:/Users/mathe/OneDrive/Documents/Projet_jeu/")+QString::fromStdString(std::to_string(nbnbbois))+QString(".png"))));
        nbPerre->setPixmap(QPixmap::fromImage(QImage(QString("C:/Users/mathe/OneDrive/Documents/Projet_jeu/")+QString::fromStdString(std::to_string(nbnbpierre))+QString(".png"))));
        nbFer->setPixmap(QPixmap::fromImage(QImage(QString("C:/Users/mathe/OneDrive/Documents/Projet_jeu/")+QString::fromStdString(std::to_string(nbnbfer))+QString(".png"))));
        nbDiamant->setPixmap(QPixmap::fromImage(QImage(QString("C:/Users/mathe/OneDrive/Documents/Projet_jeu/")+QString::fromStdString(std::to_string(nbnbdiamant))+QString(".png"))));
    }
    void setnbbois(int a){nbnbbois -= a;}
    void setnbpierre(int a){nbnbpierre -= a;}
    void setnbfer(int a){nbnbfer -= a;}
    void setnbdiamant(int a){nbnbdiamant -= a;}
};

#endif // INVENTAIRE_H
