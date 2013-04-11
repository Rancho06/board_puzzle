#include "intoolbar.h"
#include "graphicswindow.h"
#include <cmath>

InToolBar::InToolBar(MainWindow* m_w,QApplication* q_a):QToolBar(){
	mw=m_w;qa=q_a;
	QAction *StartGameAction=new QAction("Start Game",this);
	this->addAction(StartGameAction);
	connect(StartGameAction,SIGNAL(triggered()),this,SLOT(startGame()));
	
	QAction *QuitGameAction=new QAction("Quit Game",this);
	this->addAction(QuitGameAction);
	connect(QuitGameAction,SIGNAL(triggered()),this,SLOT(quitGame()));
	
	QAction *RunA=new QAction("Run A* Algorithm",this);
	this->addAction(RunA);
	connect(RunA,SIGNAL(triggered()),this,SLOT(run()));


}

void InToolBar::startGame(){
	GraphicsWindow* gw=mw->getgraphwindow();
	int dim=sqrt(gw->getsize());
	gw->setmyboard();
	gw->getscreentiles()=new GUITile*[gw->getsize()];
	for(int i=0;i<gw->getsize();i++){
    	gw->getscreentiles()[i]=new GUITile(gw,i%dim,i/dim,50);
    }
    
    for(int i=0;i<gw->getsize();i++){
    	gw->getscene()->addItem(gw->getscreentiles()[i]);
    	gw->getscene()->addItem(gw->getscreentiles()[i]->gettext());
    }
}

void InToolBar::quitGame(){
	qa->exit(0);
}

void InToolBar::run(){
}
