#ifndef GUITILE_H
#define GUITILE_H
#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>
#include <QObject>
#include <QTimer>
class GraphicsWindow;

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
	QGraphicsSimpleTextItem* gettext(){return text;};
	void mousePressEvent(QGraphicsSceneMouseEvent*);
	int getnumber(){return number;};
	int getX(){return x;};
	int getY(){return y;};
	void setX(int X){x=X;};
	void setY(int Y){y=Y;};
	QTimer* gettimer(){return timer;};
	int getloc(){return loc;};
	void setloc(int LOC){loc=LOC;};
	
	
public slots:
	void TileAnimate();
	
};


#endif
