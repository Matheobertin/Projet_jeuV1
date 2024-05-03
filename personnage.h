#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <QGraphicsItem>
#include <QLabel>

class Personnage{
private:
    QGraphicsPixmapItem *Perso;
    QGraphicsPixmapItem *Heal;
    QLabel* HealNb;
    int HealNbNb = 100;
    int ShieldNbNb = 0;
    QGraphicsPixmapItem *Shield;
    QLabel* ShieldNb;
    QGraphicsPixmapItem *PotionHeal;
    QGraphicsPixmapItem *PotionShield;
    QGraphicsPixmapItem *Armure;
    int typearmure = 1;
    int typeepee = 1;
    QGraphicsPixmapItem *Epee;
    QGraphicsPixmapItem* nbPotionHeal;
    QGraphicsPixmapItem* nbPotionShield;
    int nbnbPotionHeal = 0;
    int nbnbPotionShield = 0;
    QGraphicsPixmapItem* c;
    QGraphicsPixmapItem* v;
    int framemarche = 1;
    int attaque = 5;
public:
    Personnage();
    virtual ~Personnage();
    QGraphicsPixmapItem* getPersonnage(){return Perso;}
    QGraphicsPixmapItem* getHeal(){return Heal;}
    QGraphicsPixmapItem* getShield(){return Shield;}
    QGraphicsPixmapItem* getPotionHeal(){return PotionHeal;}
    QGraphicsPixmapItem* getPotionShield(){return PotionShield;}
    QGraphicsPixmapItem* getArmure(){return Armure;}
    QGraphicsPixmapItem* getEpee(){return Epee;}
    int gettypeepee(){return typeepee;}
    void settypeepee(int a){typeepee += a;}
    int gettypearmure(){return typearmure;}
    void settypearmure(int a){typearmure += a;}
    void setEpee(QImage a){Epee->setPixmap(QPixmap::fromImage(a));}
    void setnbPotionHeal(int v){
        nbnbPotionHeal += v;
        nbPotionHeal->setPixmap(QPixmap::fromImage(QImage(QString("C:/Users/mathe/OneDrive/Documents/Projet_jeu/")+QString::fromStdString(std::to_string(nbnbPotionHeal))+QString(".png"))));
    }
    QGraphicsPixmapItem* getnbPotionHeal(){return nbPotionHeal;}
    int getnbnbPotionHeal(){return nbnbPotionHeal;}
    int getnbnbPotionShield(){return nbnbPotionShield;}
    int getnbnbHeal(){return HealNbNb;}
    void setnbPotionShield(int v){
        nbnbPotionShield += v;
        nbPotionShield->setPixmap(QPixmap::fromImage(QImage(QString("C:/Users/mathe/OneDrive/Documents/Projet_jeu/")+QString::fromStdString(std::to_string(nbnbPotionShield))+QString(".png"))));
    }
    QGraphicsPixmapItem* getnbPotionShield(){return nbPotionShield;}
    QGraphicsPixmapItem* getc(){return c;}
    QGraphicsPixmapItem* getv(){return v;}
    QLabel* getHealNb(){return HealNb;}
    void setHealNb(int a){
        int newheal = HealNbNb+a;
        if(newheal > 100)
            newheal = 100;
        HealNb->setText(QString::fromStdString(std::to_string(newheal))+"/100");
        HealNbNb = newheal;}
    int getHealNbNb(){return HealNbNb;}
    int getShieldNbNb(){return ShieldNbNb;}
    QLabel* getShieldlNb(){return ShieldNb;}
    void setShieldlNb(int a){
        ShieldNb->setText(QString::fromStdString(std::to_string(ShieldNbNb+a))+"/100");}
    void setframemarche(bool a){
        if(a){
            framemarche++;
            Perso->setPixmap(QPixmap::fromImage(QImage(QString("C:/Users/mathe/OneDrive/Documents/Projet_jeu/personnage_droite")+QString::fromStdString(std::to_string(framemarche))+QString(".png"))));
        }
        if(framemarche == 2){
            framemarche = 0;
        }
    }
    int getattaque(){return attaque;}
    void setattaque(int v){attaque = v;}
};

#endif // PERSONNAGE_H
