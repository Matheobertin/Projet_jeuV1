#ifndef GOLEM_H
#define GOLEM_H

#include <QGraphicsItem>
#include <QDebug>

class Golem{
private:
    QGraphicsPixmapItem *golem;
    bool golemPos = false;
    bool golemAttaque = false;
    int golemType;
    float golemVie = 20;
    float t1 = 0;
    float t3 = 0;
    float t4 = 0;
    float t4bis = 0;
    float t5 = 0;
    int framemarche = 0;
    float t6 = 0;
    float t7 = 60;
    int frameattaque = 0;
    int attaque = 5;
public:
    Golem(int,int,int);
    QGraphicsPixmapItem* getGolem(){return golem;}
    float getGolemVie(){return golemVie;}
    void setGolemVie(float v){golemVie+=v;}
    bool getGolemAttaque(){return golemAttaque;}
    void setGolemAttaque(bool v){golemAttaque = v;}
    bool getGolemPos(){return golemPos;}
    void setGolemPos(bool v){golemPos = v;}
    float gett1(){return t1;}
    void sett1(float v){t1 += v;if(v == 0)t1=0;}
    float gett3(){return t3;}
    void sett3(float v){t3 += v;if(v == 0)t3=0;}
    float gett4(){return t4;}
    void sett4(float v){t4 += v;if(v == 0)t4=0;}
    float gett4bis(){return t4bis;}
    void sett4bis(float v){t4bis += v;if(v == 0)t4bis=0;}
    float gett7(){return t7;}
    void sett7(float v){t7 += v;if(v == 0)t7=0;}
    int getGolemType(){return golemType;}
    void setFrameAttaque(int v){frameattaque = v;}
    QImage attaquegolem(){
        switch(golemType){
        case 1:
            return QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/golemPierreAttaque.png");
            break;
        case 2:
            return QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/golemPierreAttaque.png");
            break;
        case 3:
            return QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/golemFerAttaque.png");
            break;
        }return QImage();}
    void setframemarche(bool a){
        if(a && t5==5){
            framemarche++;
            switch(golemType){
            case 1:
                golem->setPixmap(QPixmap::fromImage(QImage(QString("C:/Users/mathe/OneDrive/Documents/Projet_jeu/golemBoisMarche")+QString::fromStdString(std::to_string(framemarche))+QString(".png"))));
                if(golemPos)
                    golem->setPixmap(QPixmap::fromImage(QImage(golem->pixmap().toImage().mirrored(true,false))));
                break;
            case 2:
                golem->setPixmap(QPixmap::fromImage(QImage(QString("C:/Users/mathe/OneDrive/Documents/Projet_jeu/golemPierreMarche")+QString::fromStdString(std::to_string(framemarche))+QString(".png"))));
                if(golemPos)
                    golem->setPixmap(QPixmap::fromImage(QImage(golem->pixmap().toImage().mirrored(true,false))));
                break;
            case 3:
                golem->setPixmap(QPixmap::fromImage(QImage(QString("C:/Users/mathe/OneDrive/Documents/Projet_jeu/golemFerMarche")+QString::fromStdString(std::to_string(framemarche))+QString(".png"))));
                if(!golemPos)
                    golem->setPixmap(QPixmap::fromImage(QImage(golem->pixmap().toImage().mirrored(true,false))));
                break;
            }
            t5=0;
        }
        t5++;
        if(framemarche == 3){
            framemarche = 0;
        }
    }
    void setframeattaque(bool a, QPointF f){
        if(a && t6==2){
            frameattaque++;
            switch(golemType){
            case 1:
                golem->setPixmap(QPixmap::fromImage(QImage(QString("C:/Users/mathe/OneDrive/Documents/Projet_jeu/golemBoisAttaque")+QString::fromStdString(std::to_string(frameattaque))+QString(".png"))));
                if(golem->pos().rx() > f.rx())
                    golem->setPixmap(QPixmap::fromImage(QImage(golem->pixmap().toImage().mirrored(true,false))));
                break;
            case 2:
                golem->setPixmap(QPixmap::fromImage(QImage(QString("C:/Users/mathe/OneDrive/Documents/Projet_jeu/golemPierreAttaque")+QString::fromStdString(std::to_string(frameattaque))+QString(".png"))));
                if(golem->pos().rx() > f.rx())
                    golem->setPixmap(QPixmap::fromImage(QImage(golem->pixmap().toImage().mirrored(true,false))));
                break;
            case 3:
                golem->setPixmap(QPixmap::fromImage(QImage(QString("C:/Users/mathe/OneDrive/Documents/Projet_jeu/golemFerAttaque")+QString::fromStdString(std::to_string(frameattaque))+QString(".png"))));
                if(golem->pos().rx() < f.rx())
                    golem->setPixmap(QPixmap::fromImage(QImage(golem->pixmap().toImage().mirrored(true,false))));
                break;
            }
            t6=0;
        }
        t6++;
        if(frameattaque == 6){
            frameattaque = 0;
        }
    }
    int getattaque(){return attaque;}
    virtual ~Golem();
};

#endif // GOLEM_H
