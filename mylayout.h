#ifndef MYLAYOUT_H
#define MYLAYOUT_H
#include <QWidget>
#include "graphicswindow.h"

/**
  This class creates three QLineEdit objects for users to input 
  @author Shu Zhou
*/
class MyLayout : public QWidget{
	Q_OBJECT
	public:
	MyLayout();
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
