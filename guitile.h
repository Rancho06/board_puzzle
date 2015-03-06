#ifndef GUITILE_H
#define GUITILE_H
#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>
#include <QObject>
#include <QTimer>
class GraphicsWindow;

/** This class deals with creating a specific tile and the motion of the tile
@author Shu Zhou
*/
class GUITile: public QObject, public QGraphicsRectItem{
 Q_OBJECT
private:
	GraphicsWindow* gw;
	QGraphicsSimpleTextItem *text;
	int number;
	int dim;
	QTimer* timer;
	int x,y;
	int count;
	int loc;

public:
	GUITile(GraphicsWindow *, int,int,int);
	/** @return A pointer to the Text item*/
	QGraphicsSimpleTextItem* gettext(){return text;};
	void mousePressEvent(QGraphicsSceneMouseEvent*);
	/** @return The number displayed on this GUITile*/
	int getnumber(){return number;};
	/** @return The x-coordinate of left-top corner*/
	int getX(){return x;};
	/** @return The y-coordinate of left-top corner*/
	int getY(){return y;};
	/** This function sets the value of x-coordinate of upperleft corner 
	@param X x-coordinate of upperleft corner */
	void setX(int X){x=X;};
	/** This function sets the value of y-coordinate of upperleft corner 
	@param Y y-coordinate of upperleft corner */
	void setY(int Y){y=Y;};
	/** @return A pointer to the QTimer object*/
	QTimer* gettimer(){return timer;};
	/** @return The location of current Tile*/
	int getloc(){return loc;};
	/** This function sets the location of the tile on the board
	@param LOC the location of the tile on the board
	*/
	void setloc(int LOC){loc=LOC;};
	
	
public slots:
	void TileAnimate();
	
};


#endif
