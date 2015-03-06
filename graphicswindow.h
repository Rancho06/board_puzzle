#ifndef GRAPHICSWINDOW_H
#define GRAPHICSWINDOW_H

#include "board.h"
#include "puzzle_move.h"
#include "puzzle_heur.h"
#include "puzzle_solver.h"
#include "pmminlist.h"
#include <QFormLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLineEdit>
#include "guitile.h"
#include <QGraphicsRectItem>
#include <QVector>
#include <QTextEdit>

#define WINDOW_MAX_X 250
#define WINDOW_MAX_Y 250

/**
This class creates the scene and prepares the background on which the tiles are built
@author Shu Zhou
*/
class GraphicsWindow : public QGraphicsView {
public:
    explicit GraphicsWindow(QTextEdit*);
    /** @return A pointer to the current board*/
    Board* getboard(){
    	return myboard;
    }
    void setmanhattan();
    void setoop();
    /** This function sets the size of the board.
    @param SIZE the size of the board. */
    void setsize(int SIZE){size=SIZE;};
    /** This function sets  
	@param NUM The number of initial moves*/
    void setnum(int NUM){num=NUM;};
    /** This function sets the seed number 
	@param SEED The random seed number */
    void setseed(int SEED){seed=SEED;};
    /** @return A pointer to the vector containing all the GUITiles*/
    QVector<GUITile*>* getscreentiles(){return tiles;};
    /** @return A pointer to the size of the board*/
    int getsize(){return size;};
    /** @return A pointer to the current scene*/
    QGraphicsScene* getscene(){return scene;};
    
    void setmyboard();
    /** @return A pointer to the current heuristic option*/
    PuzzleHeuristic* getheur(){return ph;};
    
    /** This function sets default heuristic to NULL*/
    void resetheur(){ph=NULL;};
    /** @return A pointer to the error box*/
    QTextEdit* getErrorBox(){return eb;};
    
private:
	/// A pointer to the error Box
	QTextEdit* eb;
	/// Three variables storing size, num and seed
	int size,num,seed;
	/// A pointer to the current board
	Board * myboard;
	/// A pointer to the PuzzleHeuristic object
	PuzzleHeuristic *ph;
	/// A pointer to the ManhattanHeuristic Object
	ManhattanHeuristic *mh;
	/// A pointer to the OutOfPlaceHeuristic Object
	OutOfPlaceHeuristic *oh;
	/// A pointer to the scene
    QGraphicsScene *scene;
    /// A pointer to the layout
    QFormLayout* layout;
    /// A pointer to the screentile vectors
    QVector<GUITile*>* tiles;
};

#endif
