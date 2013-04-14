#include "guitile.h"
#include <cmath>
#include <QString>
#include "graphicswindow.h"
#include <iostream>

GUITile::GUITile(GraphicsWindow* g_w, int column, int row, int side):
QGraphicsRectItem(column*side,row*side,side,side){
	count=0;
	gw=g_w;
	x=column*side;y=row*side;
	dim=sqrt(gw->getboard()->getSize());
	loc=row*dim+column;
	number=gw->getboard()->getTiles()[loc];
	QBrush redBrush(Qt::red);
	QBrush greenBrush(Qt::green);
	QBrush blueBrush(Qt::blue);
	
	this->setZValue(0);
	
	QString str;
	str.setNum(number);
	if(number==0){
		text=new QGraphicsSimpleTextItem();
		text->setBrush(redBrush);
		this->setBrush(blueBrush);
		text->setZValue(1);
	}
	else{
		text=new QGraphicsSimpleTextItem();
		text->setBrush(redBrush);
		this->setBrush(greenBrush);
		text->setText(str);
		text->setZValue(1);
	}
	text->setPos(x+15,y+15);
	timer=new QTimer;
	timer->setInterval(5);
	connect(timer,SIGNAL(timeout()),this,SLOT(TileAnimate()));
}

void GUITile::mousePressEvent(QGraphicsSceneMouseEvent* event){
	event=event;
	int blankloc=gw->getboard()->getblankloc();
	if((loc!=blankloc)&&(((loc%dim==blankloc%dim)&&((loc/dim-blankloc/dim==1)||(loc/dim-blankloc/dim==-1)))||((loc/dim==blankloc/dim)&&((loc%dim-blankloc%dim==1)||(loc%dim-blankloc%dim==-1)))))
		timer->start();
}



void GUITile::TileAnimate(){
	int blankloc=gw->getboard()->getblankloc();
	GUITile* blanktile=(*(gw->getscreentiles()))[blankloc];
	if(count==50){
		timer->stop();
		(*(gw->getscreentiles()))[blankloc]=this;
		(*(gw->getscreentiles()))[loc]=blanktile;
		blanktile->setloc(loc);
		loc=blankloc;
		gw->getboard()->move(number);
		count=0;
		if(gw->getboard()->solved())
			gw->getErrorBox()->append("Genius!! You Won the Game!!!!");
		return;
	}
	
	x+=((blankloc%dim)*50-x)/(50-count);
	blanktile->setX(blanktile->getX()+((loc%dim)*50-blanktile->getX())/(50-count));
	y+=((blankloc/dim)*50-y)/(50-count);
	blanktile->setY(blanktile->getY()+((loc/dim)*50-blanktile->getY())/(50-count));
	QPointF p1(x,y);QPointF p2(blanktile->getX(),blanktile->getY());
	QRectF r1(rect());QRectF r2(blanktile->rect());
	r1.moveTo(p1); r2.moveTo(p2);
	setRect(r1); blanktile->setRect(r2);
	this->gettext()->setPos(x+15,y+15);
	blanktile->gettext()->setPos(blanktile->getX()+15,blanktile->getY()+15);
	count++;
}





