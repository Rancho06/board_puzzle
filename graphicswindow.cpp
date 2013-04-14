#include "graphicswindow.h"
#include <cmath>


GraphicsWindow::GraphicsWindow(QTextEdit* e_b){
	eb=e_b;
	scene = new QGraphicsScene();
	tiles=new QVector<GUITile*>;
	ph=NULL;
	mh=new ManhattanHeuristic;
	oh=new OutOfPlaceHeuristic;
    
    //This sets the size of the window and gives it a title.
    this->setFixedSize( WINDOW_MAX_X*2, WINDOW_MAX_Y*2 );
    this->setWindowTitle( "Graphical 8-Tile Puzzle");
   	this->setScene(scene);
}

void GraphicsWindow::setmyboard(){
	myboard=new Board(size,num,seed);

}


void GraphicsWindow::setmanhattan(){
	ph=mh;
}

void GraphicsWindow::setoop(){
	ph=oh; 
}


/*GraphicsWindow::~GraphicsWindow()
{
    timer->stop();
    delete timer;
   	for(unsigned int i=0;i<itemlist.size();i++){
   		delete itemlist[i];
   	}
    delete scene;
    delete view;
}*/
