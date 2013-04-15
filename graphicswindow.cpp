#include "graphicswindow.h"
#include <cmath>

/** 
Constructor sets up the scene
@param e_b A pointer tothe error Box
*/
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

/** set the board with provided inputs*/
void GraphicsWindow::setmyboard(){
	myboard=new Board(size,num,seed);

}

/** choosing manhattan as heuristic*/
void GraphicsWindow::setmanhattan(){
	ph=mh;
}

/** choosing outofplace as heuristic*/
void GraphicsWindow::setoop(){
	ph=oh; 
}
