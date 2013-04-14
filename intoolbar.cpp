#include "intoolbar.h"
#include "graphicswindow.h"
#include <cmath>
#include <iostream>
#include "mylist.h"
using namespace std;


InToolBar::InToolBar(MainWindow* m_w,QApplication* q_a):QToolBar(){
	mw=m_w;qa=q_a;
	QAction *StartGameAction=new QAction("Start Game",this);
	this->addAction(StartGameAction);
	connect(StartGameAction,SIGNAL(triggered()),this,SLOT(startGame()));
	
	QAction *QuitGameAction=new QAction("Quit Game",this);
	this->addAction(QuitGameAction);
	connect(QuitGameAction,SIGNAL(triggered()),this,SLOT(quitGame()));
	
	QAction *RunA=new QAction("Get Cheat",this);
	this->addAction(RunA);
	connect(RunA,SIGNAL(triggered()),this,SLOT(run()));


}

void InToolBar::startGame(){

	GraphicsWindow* gw=mw->getgraphwindow();
	MyLayout *layout=mw->getlayout();
	gw->setsize(layout->getsize());
	gw->setnum(layout->getnum());
	gw->setseed(layout->getseed());
	int dim=sqrt(gw->getsize());
	gw->setmyboard();
	for(int i=0;i<gw->getsize();i++){
		GUITile* tile=new GUITile(gw,i%dim,i/dim,50);
    		gw->getscreentiles()->push_back(tile);
    		gw->getscene()->addItem(tile);
    		gw->getscene()->addItem(tile->gettext());
    	}
 
 
}

void InToolBar::quitGame(){
	qa->exit(0);
}

void InToolBar::run(){
	QStringList* list;
	ManhattanHeuristic* mh=new ManhattanHeuristic;
	Board b=*(mw->getgraphwindow()->getboard());
	PuzzleSolver ps(b);
	ps.run(mh);
	int size=ps.getlist()->size();
	list=ps.getqstring();
	list->push_front("Try the following sequence:");
	mw->getlist()->insertItems(0,*list);
	
	



}
