#ifndef MYLAYOUT_H
#define MYLAYOUT_H
#include <QWidget>
#include "graphicswindow.h"

class MyLayout : public QWidget{
	Q_OBJECT
	public:
	MyLayout(GraphicsWindow*);
	int getsize();
	int getnum();
	int getseed();
	void reset();
	private:
	QFormLayout* layout;
	QLineEdit* sizeEdit;
	QLineEdit* startMovesEdit;
	QLineEdit* randomSeedEdit;

};

#endif
