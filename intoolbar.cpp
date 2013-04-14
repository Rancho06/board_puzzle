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
	gw->resetheur();
	//mw->gethorizon()->resetbutton();
	gw->getscene()->clear();
	gw->getscreentiles()->clear();
	mw->getlist()->clear();
	mw->getErrorBox()->clear();
	
	MyLayout *layout=mw->getlayout();
	int size=layout->getsize();
	
	if(size==-99){
		layout->reset();
		mw->getErrorBox()->append("You must enter an integer as the size. \nPlease enter again.");
		return;
	}
	else if(size<=0){
		layout->reset();
		mw->getErrorBox()->append("You must enter a positive number as the size.\nPlease enter again.");
		return;
	}
	else if (size!=4&&size!=9&&size!=16&&size!=25&&size!=36){
		layout->reset();
		mw->getErrorBox()->append("You must enter a square number as the size.\nPlease enter again.");
		return;
	}
	else{
		gw->setsize(size);
	}
	
	int num=layout->getnum();
	if(num==-99){
		layout->reset();
		mw->getErrorBox()->append("You must enter an integer as the initial moves of the board.\n Please enter again.");
		return;
	}
	else if(num<=0){
		layout->reset();
		mw->getErrorBox()->append("You must enter a positive number as the initial moves of the board.\n Please enter again.");
		return;
	}
	else{
		gw->setnum(num);
	}
	
	int seed=layout->getseed();
	if(seed==-99){
		layout->reset();
		mw->getErrorBox()->append("You must enter an integer as the random seed.\n Please enter again.");
		return;
	}
	else if(seed<=0){
		layout->reset();
		mw->getErrorBox()->append("You must enter a positive number as the random seed.\n Please enter again.");
		return;
	}
	else{
		gw->setseed(seed);
	}
	layout->reset();
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
	if(mw->getgraphwindow()->getscreentiles()->size()==0){
		mw->getErrorBox()->append("Please start a game first!");
		return;
	}
	if(mw->getgraphwindow()->getheur()==NULL){
		mw->getErrorBox()->append("You must select a heuristic option before running the Cheat! ");
		return;
	}
	mw->getlist()->clear();
	mw->getErrorBox()->clear();
	QStringList* list;
	Board b=*(mw->getgraphwindow()->getboard());
	PuzzleSolver ps(b);
	ps.run(mw->getgraphwindow()->getheur());
	int size=ps.getlist()->size();
	list=ps.getqstring();
	list->push_front("Try the following sequence:");
	mw->getlist()->insertItems(0,*list);
}
