#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    this->mainScene = new MyScene;

    this->mainView = new QGraphicsView;
    this->mainView->setScene(mainScene);

    this->setCentralWidget(mainView);
    this->setWindowTitle("My main window");
    this->resize(1600, 800);


    QGraphicsView* mainView1 = new QGraphicsView();
    mainView1->setScene(mainScene);

    mainView1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mainView1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    mainView1->setWindowTitle("mainView");
    mainView1->resize(1600, 800);
    mainView1->show();


    helpMenu = menuBar()->addMenu(tr("&Help"));
    QAction* actionHelp = new QAction(tr("&About"), this);
    connect(actionHelp, SIGNAL(triggered()), this, SLOT(slot_aboutMenu()));
    helpMenu->addAction(actionHelp);

}

MainWindow::~MainWindow(){

}

void MainWindow::slot_aboutMenu(){
    QMessageBox msgBox;
    msgBox.setText("A small QT/C++ projet...");
    msgBox.setModal(true); // on souhaite que la fenetre soit modale i.e qu'on ne puisse plus cliquer ailleurs
    msgBox.exec();
}
