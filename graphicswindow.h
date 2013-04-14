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


class GraphicsWindow : public QGraphicsView {
public:
    explicit GraphicsWindow(QTextEdit*);
    //~GraphicsWindow();
    Board* getboard(){
    	return myboard;
    }
    void setmanhattan();
    void setoop();
    void setsize(int SIZE){size=SIZE;};
    void setnum(int NUM){num=NUM;};
    void setseed(int SEED){seed=SEED;};
    QVector<GUITile*>* getscreentiles(){return tiles;};
    int getsize(){return size;};
    QGraphicsScene* getscene(){return scene;};
    void setmyboard();
    PuzzleHeuristic* getheur(){return ph;};
    void resetheur(){ph=NULL;};
    QTextEdit* getErrorBox(){return eb;};
    
private:
	QTextEdit* eb;
	int size,num,seed;
	Board * myboard;
	PuzzleHeuristic *ph;
	ManhattanHeuristic *mh;
	OutOfPlaceHeuristic *oh;
    QGraphicsScene *scene;
    QFormLayout* layout;
    QVector<GUITile*>* tiles;
};

#endif
