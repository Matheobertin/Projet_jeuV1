#include "MyScene.h"

MyScene::MyScene(QObject* parent) : QGraphicsScene(parent) {

    //Initialisation du fond
        QImage image("C:/Users/mathe/OneDrive/Documents/Projet_jeu/background.jpg");
        fond = new QGraphicsPixmapItem(QPixmap::fromImage(image));
        fond->setScale(2);
        fond->setPos(0,-145);
        this->addItem((fond));
    //

    //Création Golems
        Golem* golem = new Golem(180,420,1);
        this->addItem((golem->getGolem()));
        Golems.append(golem);

        golem = new Golem(1180,420,1);
        this->addItem((golem->getGolem()));
        Golems.append(golem);

        golem = new Golem(2000,420,2);
        this->addItem((golem->getGolem()));
        Golems.append(golem);

        golem = new Golem(3000,420,2);
        this->addItem((golem->getGolem()));
        Golems.append(golem);

        golem = new Golem(3800,420,3);
        this->addItem((golem->getGolem()));
        Golems.append(golem);
    //

    //Création Plateformes
        Plateforme* plateforme = new Plateforme(0, 800, 700, 10);
        this->addItem(plateforme->getPlateforme());
        plateformes.append(plateforme);

        plateforme = new Plateforme(1100, 800, 1400, 10);
        this->addItem(plateforme->getPlateforme());
        plateformes.append(plateforme);

        plateforme = new Plateforme(800, 660, 200, 10);
        this->addItem(plateforme->getPlateforme());
        plateformes.append(plateforme);

        plateforme = new Plateforme(200, 520, 400, 10);
        this->addItem(plateforme->getPlateforme());
        plateformes.append(plateforme);

        plateforme = new Plateforme(1200, 520, 400, 10);
        this->addItem(plateforme->getPlateforme());
        plateformes.append(plateforme);

        plateforme = new Plateforme(2600, 660, 200, 10);
        this->addItem(plateforme->getPlateforme());
        plateformes.append(plateforme);

        plateforme = new Plateforme(2000, 520, 400, 10);
        this->addItem(plateforme->getPlateforme());
        plateformes.append(plateforme);

        plateforme = new Plateforme(2900, 800, 1400, 10);
        this->addItem(plateforme->getPlateforme());
        plateformes.append(plateforme);

        plateforme = new Plateforme(3000, 520, 400, 10);
        this->addItem(plateforme->getPlateforme());
        plateformes.append(plateforme);

        plateforme = new Plateforme(3800, 520, 400, 10);
        this->addItem(plateforme->getPlateforme());
        plateformes.append(plateforme);

        plateforme = new Plateforme(4400, 660, 200, 10);
        this->addItem(plateforme->getPlateforme());
        plateformes.append(plateforme);
    //

    //Initialisation Personnage
        this->addItem(personnage.getPersonnage());
        this->addItem(personnage.getArmure());
        this->addItem(personnage.getEpee());
        this->addItem(personnage.getHeal());
        this->addItem(personnage.getShield());
        this->addItem(personnage.getPotionShield());
        this->addItem(personnage.getnbPotionShield());
        this->addItem(personnage.getPotionHeal());
        this->addItem(personnage.getnbPotionHeal());
        this->addItem(personnage.getc());
        this->addItem(personnage.getv());
        this->addWidget(personnage.getHealNb());
        this->addWidget(personnage.getShieldlNb());
    //

    //Initialisation inventaire
        this->addItem(inventaire.getInventaire());
        this->addItem(inventaire.getArmureInventaire());
        this->addItem(inventaire.getEpeeInventaire());
        this->addItem(inventaire.getUpgradeArmure());
        this->addItem(inventaire.getUpgradeEpee());
        this->addItem(inventaire.getitemBois());
        this->addItem(inventaire.getitemPierre());
        this->addItem(inventaire.getitemFer());
        this->addItem(inventaire.getitemDiamant());
        this->addItem(inventaire.getnbBois());
        this->addItem(inventaire.getnbPierre());
        this->addItem(inventaire.getnbFer());
        this->addItem(inventaire.getnbDiamant());
    //

    //Initialisation chronometre
        chronometre = new QLabel("00:00");
        chronometre->setFont(QFont("Arial",20));
        this->addWidget(chronometre);
    //

    //Timer
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(update()));
        timer->start(20); //toutes les 30 millisecondes
    //
}

MyScene::~MyScene() {

}

void MyScene::update() {
    QGraphicsRectItem* plateforme = plateformes[0]->getPlateforme();
    QGraphicsPixmapItem* Personnage = personnage.getPersonnage();

    auto views = this->views();
    views[1]->centerOn(Personnage);

    //Gravité
        if(!isground && !isjumping){
            Personnage->setPos(Personnage->pos().rx(),Personnage->pos().ry()+gravity*2);
            //Tomber dans le vide
            if(Personnage->pos().ry() > 1000){
                Personnage->setPos(0,680);
                if(personnage.getnbnbHeal() > 20)
                    personnage.setHealNb(-(personnage.getnbnbHeal()-20));
            }
            //Collission avec Golem
            for (int var = 0; var < std::size(Golems); ++var) {
                if(Personnage->collidesWithItem(Golems[var]->getGolem())){
                    if(Golems[var]->getGolem()->pos().rx()-Personnage->pos().rx() > 0){
                        Personnage->setPos(Personnage->pos().rx()-vitesse*1.5,Personnage->pos().ry());
                    }else{
                        Personnage->setPos(Personnage->pos().rx()+vitesse*1.5,Personnage->pos().ry());
                    }
                }
            }
        }
    //

    //Detection si Collision avec Plateforme
        for (int var = 0; var < std::size(plateformes); ++var) {
            if(Personnage->collidesWithItem(plateformes[var]->getPlateforme()))
                plateforme = plateformes[var]->getPlateforme();
        }
    //

    //Sur plateforme
        if(Personnage->collidesWithItem(plateforme) && (Personnage->pos().ry() == 700 || Personnage->pos().ry() == 560 || Personnage->pos().ry() == 420)){
            isground = true;
        }else{
            isground = false;
        }
    //

    //Droite
        if(pressedKeys.contains(Qt::Key_D)){
            Personnage->setPos(Personnage->pos().rx()+vitesse,Personnage->pos().ry());
            //Collision avec plateformes
                for (int var = 0; var < std::size(plateformes); ++var) {
                    if(Personnage->collidesWithItem(plateformes[var]->getPlateforme())){
                        if(Personnage->pos().ry()!=700 && Personnage->pos().ry()!=560 && Personnage->pos().ry()!=420)
                            Personnage->setPos(Personnage->pos().rx()-vitesse,Personnage->pos().ry());
                    }
                }
            //

            //Collision avec Golem
                for (int var = 0; var < std::size(Golems); ++var) {
                    if(Personnage->collidesWithItem(Golems[var]->getGolem()))
                        Personnage->setPos(Personnage->pos().rx()-vitesse,Personnage->pos().ry());
                }
                personnage.setframemarche(true);
            //
        }
    //

    //Gauche
        if(pressedKeys.contains(Qt::Key_Q) && Personnage->pos().rx()>0){
            Personnage->setPos(Personnage->pos().rx()-vitesse,Personnage->pos().ry());
            //Collision avec plateformes
                for (int var = 0; var < std::size(plateformes); ++var){
                    if(Personnage->collidesWithItem(plateformes[var]->getPlateforme())){
                        if(Personnage->pos().ry()!=700 && Personnage->pos().ry() != 560 && Personnage->pos().ry()!=420)
                            Personnage->setPos(Personnage->pos().rx()+vitesse,Personnage->pos().ry());
                    }
                }
            //

            //Collision avec Golem
                for (int var = 0; var < std::size(Golems); ++var) {
                    if(Personnage->collidesWithItem(Golems[var]->getGolem()))
                        Personnage->setPos(Personnage->pos().rx()+vitesse,Personnage->pos().ry());
                }
                Personnage->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/personnage_gauche.png")));
            //
        }
    //

    //Saut
        if(pressedKeys.contains(Qt::Key_Space) && isground){
            t = 0;
            isground = false;
            isjumping = true;
        }
    //

    //Saute
        if(isjumping){
            if(t!=10){
                Personnage->setPos(Personnage->pos().rx(),Personnage->pos().ry()-gravity*2);
                for (int var = 0; var < std::size(plateformes); ++var) {
                    if(Personnage->collidesWithItem(plateformes[var]->getPlateforme())){
                        Personnage->setPos(Personnage->pos().rx(),Personnage->pos().ry()+gravity*2);
                        isjumping = false;
                    }
                }
                t+=1;
            }else{
                isjumping = false;
                t = 0;
            }
        }
    //

    //Attaque
        if(pressedKeys.contains(Qt::Key_B)){
            persoAttaque= true;
        }
        if(t5 == 30){
            for (int var = 0; var < std::size(Golems); ++var) {
                if((abs(Personnage->pos().rx() - Golems[var]->getGolem()->pos().rx())) < 150 && Golems[var]->getGolem()->pos().ry()-Personnage->pos().ry() > -10  && !Golems[var]->getGolem()->pixmap().isNull()){
                    if(persoAttaque){
                        Personnage->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/personnage_droite_attaque.png")));
                        t5 = 0;
                        if(Golems[var]->getGolemVie() != 0)
                            Golems[var]->setGolemVie(-personnage.getattaque());
                        if(Golems[var]->getGolemVie() == 0 && !Golems[var]->getGolem()->pixmap().isNull()){
                            inventaire.setitem(Golems[var]->getGolemType());
                            personnage.setnbPotionHeal(1);
                            Golems[var]->getGolem()->setPixmap(QPixmap::fromImage(QImage()));
                        }
                    }
                }
            }
        }else{
            persoAttaque = false;
            Personnage->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/personnage_droite1.png")));
            t5+=1;
        }
    //

    //Mouvement Golem
        for (int var = 0; var < std::size(Golems); ++var){
            Golem* golem = Golems[var];
            if(golem->getGolemVie() != 0){ //Si Golem en Vie
                if(golem->gett1() != 70 && !golem->getGolemAttaque()){ //Temps entre chaques déplacements
                    QGraphicsRectItem* plateforme = plateformes[0]->getPlateforme();
                    for (int var = 0; var < std::size(plateformes); ++var) { //Détéction plateforme collision
                        if(golem->getGolem()->collidesWithItem(plateformes[var]->getPlateforme())){
                            plateforme = plateformes[var]->getPlateforme();
                        }
                    }
                    if(!golem->getGolemPos()){ //A gauche vers droite
                        golem->getGolem()->setPos(golem->getGolem()->pos().rx()+vitesse/3.5,golem->getGolem()->pos().ry());
                        if(golem->getGolem()->pos().rx()+golem->getGolem()->pixmap().size().width()*0.15 > plateforme->rect().right()+30)
                            golem->getGolem()->setPos(golem->getGolem()->pos().rx()-vitesse/3.5,golem->getGolem()->pos().ry());
                    }
                    if(golem->getGolemPos()){ //A droite vers gauche
                        golem->getGolem()->setPos(golem->getGolem()->pos().rx()-vitesse/3.5,golem->getGolem()->pos().ry());
                        if(golem->getGolem()->pos().rx() < plateforme->rect().left()-70)
                            golem->getGolem()->setPos(golem->getGolem()->pos().rx()+vitesse/3.5,golem->getGolem()->pos().ry());
                    }
                    golem->setframemarche(true);
                    golem->sett1(1);
                    golem->sett3(0);
                }else{
                    if(golem->getGolemAttaque()){
                        if(abs(golem->getGolem()->pos().rx()-Personnage->pos().rx())<150){ //Detection distance avec joueur
                            if(golem->gett7() == 60){
                                if(golem->gett4bis() == 1){ //Temps entre les frames attaques
                                    golem->setframeattaque(true, personnage.getPersonnage()->pos());
                                    golem->sett4bis(0);
                                }else{
                                    golem->sett4bis(1);
                                }
                                if(golem->gett4() == 27){ //Temps entre chaques degats
                                    golem->sett4(0);
                                    golem->sett7(0);
                                    switch(golem->getGolemType()){
                                    case 1:
                                        golem->getGolem()->setPixmap(QPixmap::fromImage(QImage(QString("C:/Users/mathe/OneDrive/Documents/Projet_jeu/golemBoisAttaque1.png"))));
                                        break;
                                    case 2:
                                        golem->getGolem()->setPixmap(QPixmap::fromImage(QImage(QString("C:/Users/mathe/OneDrive/Documents/Projet_jeu/golemPierreAttaque1.png"))));
                                        break;
                                    case 3:
                                        golem->getGolem()->setPixmap(QPixmap::fromImage(QImage(QString("C:/Users/mathe/OneDrive/Documents/Projet_jeu/golemFerAttaque1.png"))));
                                        break;
                                    }
                                    golem->setFrameAttaque(0);
                                    if(personnage.getShieldNbNb()>=20){
                                        personnage.setShieldlNb(-golem->getattaque());
                                    }else if(personnage.getShieldNbNb()>0){
                                        personnage.setHealNb(-(personnage.getShieldNbNb()-golem->getattaque()));
                                        personnage.setShieldlNb(-personnage.getShieldNbNb());
                                    }
                                    personnage.setHealNb(-golem->getattaque());
                                }else{
                                    golem->sett4(1);
                                }
                            }else{
                                golem->sett7(1);
                            }
                        }else{ //Golem se dirige vers joueur
                            golem->setframemarche(true);
                            if(Personnage->pos().rx()>golem->getGolem()->pos().rx()){
                                golem->getGolem()->setPos(golem->getGolem()->pos().rx()+vitesse/5,golem->getGolem()->pos().ry());
                                if(golem->getGolem()->pos().rx()+golem->getGolem()->pixmap().size().width()*0.15 > plateforme->rect().right())
                                    golem->getGolem()->setPos(golem->getGolem()->pos().rx()-vitesse/5,golem->getGolem()->pos().ry());
                            }else{
                                golem->getGolem()->setPos(golem->getGolem()->pos().rx()-vitesse/5,golem->getGolem()->pos().ry());
                                if(golem->getGolem()->pos().rx()+golem->getGolem()->pixmap().size().width()*0.15 > plateforme->rect().right())
                                    golem->getGolem()->setPos(golem->getGolem()->pos().rx()+vitesse/5,golem->getGolem()->pos().ry());
                            }
                        }
                    }else{
                        golem->setGolemPos(!golem->getGolemPos());
                        if(golem->gett3()==20)
                            golem->sett1(0);
                        golem->sett3(1);
                    }
                }
            }
        }
    //

    //Detection Golem
        for (int var = 0; var < std::size(Golems); ++var){
            Golem* golem = Golems[var];
            if(abs(golem->getGolem()->pos().rx() - Personnage->pos().rx()) < 400 && golem->getGolem()->pos().ry()-Personnage->pos().ry()>-50){
                golem->setGolemAttaque(true);
            }else{
                golem->setGolemAttaque(false);
            }
        }
    //

    //Position Barres (Vie et Armure)
        personnage.getHeal()->setPos(abs(views[1]->viewportTransform().dx())+views[1]->size().width()-130,abs(views[1]->viewportTransform().dy())-10);
        personnage.getShield()->setPos(abs(views[1]->viewportTransform().dx())+views[1]->size().width()-130,abs(views[1]->viewportTransform().dy())+20);
        switch(personnage.getHealNbNb()){
        case 100:
            personnage.getHeal()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Heal100.png")));
            break;
        case 95:
            personnage.getHeal()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Heal95.png")));
            break;
        case 90:
            personnage.getHeal()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Heal90.png")));
            break;
        case 85:
            personnage.getHeal()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Heal85.png")));
            break;
        case 80:
            personnage.getHeal()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Heal80.png")));
            break;
        case 75:
            personnage.getHeal()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Heal75.png")));
            break;
        case 70:
            personnage.getHeal()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Heal70.png")));
            break;
        case 65:
            personnage.getHeal()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Heal65.png")));
            break;
        case 60:
            personnage.getHeal()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Heal60.png")));
            break;
        case 55:
            personnage.getHeal()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Heal55.png")));
            break;
        case 50:
            personnage.getHeal()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Heal50.png")));
            break;
        case 45:
            personnage.getHeal()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Heal45.png")));
            break;
        case 40:
            personnage.getHeal()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Heal40.png")));
            break;
        case 35:
            personnage.getHeal()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Heal35.png")));
            break;
        case 30:
            personnage.getHeal()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Heal30.png")));
            break;
        case 25:
            personnage.getHeal()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Heal25.png")));
            break;
        case 20:
            personnage.getHeal()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Heal20.png")));
            break;
        case 15:
            personnage.getHeal()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Heal15.png")));
            break;
        case 10:
            personnage.getHeal()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Heal10.png")));
            break;
        case 5:
            personnage.getHeal()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Heal5.png")));
            break;
        case 0:
            personnage.getHeal()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Heal0.png")));
            break;
        }
        switch(personnage.getShieldNbNb()){
        case 100:
            personnage.getShield()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Shield100.png")));
            break;
        case 95:
            personnage.getShield()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Shield95.png")));
            break;
        case 90:
            personnage.getShield()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Shield90.png")));
            break;
        case 85:
            personnage.getShield()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Shield85.png")));
            break;
        case 80:
            personnage.getShield()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Shield80.png")));
            break;
        case 75:
            personnage.getShield()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Shield75.png")));
            break;
        case 70:
            personnage.getShield()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Shield70.png")));
            break;
        case 65:
            personnage.getShield()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Shield65.png")));
            break;
        case 60:
            personnage.getShield()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Shield60.png")));
            break;
        case 55:
            personnage.getShield()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Shield55.png")));
            break;
        case 50:
            personnage.getShield()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Shield50.png")));
            break;
        case 45:
            personnage.getShield()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Shield45.png")));
            break;
        case 40:
            personnage.getShield()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Shield40.png")));
            break;
        case 35:
            personnage.getShield()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Shield35.png")));
            break;
        case 30:
            personnage.getShield()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Shield30.png")));
            break;
        case 25:
            personnage.getShield()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Shield25.png")));
            break;
        case 20:
            personnage.getShield()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Shield20.png")));
            break;
        case 15:
            personnage.getShield()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Shield15.png")));
            break;
        case 10:
            personnage.getShield()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Shield10.png")));
            break;
        case 5:
            personnage.getShield()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Shield5.png")));
            break;
        case 0:
            personnage.getShield()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/Shield0.png")));
            break;
        }

    //

    //Position Potions (Vie et Armure)
        personnage.getPotionHeal()->setPos(abs(views[1]->viewportTransform().dx())+10,abs(views[1]->viewportTransform().dy())+views[1]->size().height()-90);
        personnage.getnbPotionHeal()->setPos(abs(views[1]->viewportTransform().dx())+80,abs(views[1]->viewportTransform().dy())+views[1]->size().height()-85);
        personnage.getc()->setPos(abs(views[1]->viewportTransform().dx())+6,abs(views[1]->viewportTransform().dy())+views[1]->size().height()-150);
        personnage.getPotionShield()->setPos(abs(views[1]->viewportTransform().dx())+150,abs(views[1]->viewportTransform().dy())+views[1]->size().height()-90);
        personnage.getnbPotionShield()->setPos(abs(views[1]->viewportTransform().dx())+220,abs(views[1]->viewportTransform().dy())+views[1]->size().height()-85);
        personnage.getv()->setPos(abs(views[1]->viewportTransform().dx())+156,abs(views[1]->viewportTransform().dy())+views[1]->size().height()-150);
    //

    //Position Equipements (Armure et épée)
        personnage.getArmure()->setPos(abs(views[1]->viewportTransform().dx())+views[1]->size().width()-100,abs(views[1]->viewportTransform().dy())+views[1]->size().height()-90);
        personnage.getEpee()->setPos(abs(views[1]->viewportTransform().dx())+views[1]->size().width()-180,abs(views[1]->viewportTransform().dy())+views[1]->size().height()-90);
    //

    //Position nbHeal et nbShield
        personnage.getHealNb()->move(abs(views[1]->viewportTransform().dx())+views[1]->size().width()-230,abs(views[1]->viewportTransform().dy())+5);
        personnage.getShieldlNb()->move(abs(views[1]->viewportTransform().dx())+views[1]->size().width()-230,abs(views[1]->viewportTransform().dy())+35);
    //

    //Inventaire
        if(pressedKeys.contains(Qt::Key_F)){
            if(!inventaireouvert){
                inventaireouvert = true;
                inventaire.getInventaire()->setPos(abs(views[1]->viewportTransform().dx())+(views[1]->size().width()/2)-348,(abs(views[1]->viewportTransform().dy())+(views[1]->size().height()/2)-281));

                inventaire.getEpeeInventaire()->setPos(inventaire.getInventaire()->pos().rx()+270,inventaire.getInventaire()->pos().ry()+100);

                inventaire.getArmureInventaire()->setPos(inventaire.getInventaire()->pos().rx()+270,inventaire.getInventaire()->pos().ry()+300);

                inventaire.getUpgradeEpee()->setPos(inventaire.getInventaire()->pos().rx()+445,inventaire.getInventaire()->pos().ry()+150);
                inventaire.getUpgradeEpee()->setFlag(QGraphicsItem::ItemIsSelectable, false);

                inventaire.getUpgradeArmure()->setPos(inventaire.getInventaire()->pos().rx()+445,inventaire.getInventaire()->pos().ry()+350);
                inventaire.getUpgradeArmure()->setFlag(QGraphicsItem::ItemIsSelectable, false);

                inventaire.getitemBois()->setPos(inventaire.getInventaire()->pos().rx()+30,inventaire.getInventaire()->pos().ry()+60);

                inventaire.getitemPierre()->setPos(inventaire.getInventaire()->pos().rx()+30,inventaire.getInventaire()->pos().ry()+180);

                inventaire.getitemFer()->setPos(inventaire.getInventaire()->pos().rx()+30,inventaire.getInventaire()->pos().ry()+300);

                inventaire.getitemDiamant()->setPos(inventaire.getInventaire()->pos().rx()+30,inventaire.getInventaire()->pos().ry()+420);

                inventaire.getnbBois()->setPos(inventaire.getInventaire()->pos().rx()+120,inventaire.getInventaire()->pos().ry()+60);

                inventaire.getnbPierre()->setPos(inventaire.getInventaire()->pos().rx()+120,inventaire.getInventaire()->pos().ry()+180);

                inventaire.getnbFer()->setPos(inventaire.getInventaire()->pos().rx()+120,inventaire.getInventaire()->pos().ry()+300);

                inventaire.getnbDiamant()->setPos(inventaire.getInventaire()->pos().rx()+120,inventaire.getInventaire()->pos().ry()+420);
                inventaire.setImage();
                inventaire.getEpeeInventaire()->setPixmap(personnage.getEpee()->pixmap());
                inventaire.getArmureInventaire()->setPixmap(personnage.getArmure()->pixmap());
            }
        }
        if(inventaireouvert){
            inventaire.getUpgradeEpee()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/noupgrade.png")));
            switch(personnage.gettypeepee()){
            case 1:
                if(inventaire.getnbnbbois() >= 1){
                    inventaire.getUpgradeEpee()->setFlag(QGraphicsItem::ItemIsSelectable, true);
                    inventaire.getUpgradeEpee()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/upgrade.png")));
                    if(inventaire.getUpgradeEpee()->isSelected()){
                        personnage.settypeepee(1);
                        personnage.setEpee(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/EpeeDiamant.jpg"));
                        inventaire.getEpeeInventaire()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/EpeeDiamant.jpg")));
                        personnage.setattaque(10);
                        inventaire.setnbbois(1);
                        inventaire.getnbBois()->setPixmap(QPixmap::fromImage(QImage(QString("C:/Users/mathe/OneDrive/Documents/Projet_jeu/")+QString::fromStdString(std::to_string(inventaire.getnbnbbois()))+QString(".png"))));
                    }
                }
                break;
            case 2:
                if(inventaire.getnbnbpierre() >= 1){
                    inventaire.getUpgradeEpee()->setFlag(QGraphicsItem::ItemIsSelectable, true);
                    inventaire.getUpgradeEpee()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/upgrade.png")));
                    if(inventaire.getUpgradeEpee()->isSelected()){
                        personnage.settypeepee(1);
                        //personnage.setEpee(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/EpeeDiamant.jpg"));
                        //inventaire.getEpeeInventaire()->setPixmap(QPixmap::fromImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/EpeeDiamant.jpg")));
                        personnage.setattaque(20);
                        inventaire.setnbpierre(1);
                    }
                }
                break;
            }
            if(inventaire.getUpgradeArmure()->isSelected()){
            }
        }
        if(pressedKeys.contains(Qt::Key_Escape)){
            if(inventaireouvert){
                inventaireouvert = false;
                inventaire.setImage(QImage("C:/Users/mathe/OneDrive/Documents/Projet_jeu/rien.png"));
            }
        }
    //

    //Timer
        chronometre->move(abs(views[1]->viewportTransform().dx())+(views[1]->size().width())-330,abs(views[1]->viewportTransform().dy())+(views[1]->size().height())-780);
        if(temps == 20){
            chrono++;
            if(chrono/60 < 10){
                chronometre->setText("0"+QString::fromStdString(std::to_string(chrono/60))+":"+QString::fromStdString(std::to_string(chrono%60)));
                if(chrono%60 < 10){
                    chronometre->setText("0"+QString::fromStdString(std::to_string(chrono/60))+":0"+QString::fromStdString(std::to_string(chrono%60)));
                }
            }
            else
                chronometre->setText(QString::fromStdString(std::to_string(chrono/60))+":"+QString::fromStdString(std::to_string(chrono%60)));
            temps = 0;
        }else{
            temps++;
        }
    //
}

void MyScene::keyPressEvent(QKeyEvent* event){
    if(event->key() == Qt::Key_D && !inventaireouvert) {
        pressedKeys.insert(Qt::Key_D);
    }
    if(event->key() == Qt::Key_Q && !inventaireouvert) {
        pressedKeys.insert(Qt::Key_Q);
    }
    if(event->key() == Qt::Key_Space && !inventaireouvert) {
        pressedKeys.insert(Qt::Key_Space);
    }
    if(event->key() == Qt::Key_B && !inventaireouvert) {
        pressedKeys.insert(Qt::Key_B);
    }
    if(event->key() == Qt::Key_F && !inventaireouvert) {
        pressedKeys.insert(Qt::Key_F);
    }
    if(event->key() == Qt::Key_Escape) {
        pressedKeys.insert(Qt::Key_Escape);
    }
    if(event->key() == Qt::Key_C && !inventaireouvert) {
        if(personnage.getnbnbPotionHeal()>0){
            personnage.setHealNb(20);
            personnage.setnbPotionHeal(-1);
        }
    }
    if(event->key() == Qt::Key_V && !inventaireouvert) {
        if(personnage.getnbnbPotionShield()>0){
            personnage.setShieldlNb(20);
            personnage.setnbPotionShield(-1);
        }
    }
}

void MyScene::keyReleaseEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_D) {
        pressedKeys.remove(Qt::Key_D);
    }
    if(event->key() == Qt::Key_Q) {
        pressedKeys.remove(Qt::Key_Q);
    }
    if(event->key() == Qt::Key_Space) {
        pressedKeys.remove(Qt::Key_Space);
    }
    if(event->key() == Qt::Key_B) {
        pressedKeys.remove(Qt::Key_B);
    }
    if(event->key() == Qt::Key_F) {
        pressedKeys.remove(Qt::Key_F);
    }
    if(event->key() == Qt::Key_Escape) {
        pressedKeys.remove(Qt::Key_Escape);
    }
}

