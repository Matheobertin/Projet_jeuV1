#ifndef CPP_QT_TPMINIPROJET_MYSCENE_H
#define CPP_QT_TPMINIPROJET_MYSCENE_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include <QPainter>
#include <QRectF>
#include "myview.h"
#include "personnage.h"
#include "plateforme.h"
#include "inventaire.h"
#include "golem.h"

class MyScene : public QGraphicsScene{
    Q_OBJECT
private:
    QTimer* timer;
    QList<Plateforme*> plateformes;
    QList<Golem*> Golems;
    Personnage personnage;
    Inventaire inventaire;
    int vitesse = 15;
    float gravity = 10;
    float t = 0;
    float t5 = 30;
    QGraphicsPixmapItem *fond;
    QSet<int> pressedKeys;
    bool isjumping = false;
    bool isground;
    bool persoAttaque = false;
    bool inventaireouvert = false;
    int chrono = 0;
    int temps = 0;
    QLabel* chronometre;
public:
    MyScene(QObject* parent = nullptr);
    virtual ~MyScene();
protected:
    void keyPressEvent(QKeyEvent* event)override;
    void keyReleaseEvent(QKeyEvent* event)override;
public slots:
    void update();
};


#endif //CPP_QT_TPMINIPROJET_MYSCENE_H
