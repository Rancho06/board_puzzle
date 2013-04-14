#include "mylayout.h"

MyLayout::MyLayout(GraphicsWindow* gw):QWidget(){
	layout=new QFormLayout;
	setLayout(layout);
	sizeEdit=new QLineEdit();
	startMovesEdit=new QLineEdit();
	randomSeedEdit=new QLineEdit();
	
	layout->addRow("Board Size:",sizeEdit);
	layout->addRow("Starting Moves:",startMovesEdit);
	layout->addRow("Random Seed Value:",randomSeedEdit);
}

void MyLayout::reset(){
	sizeEdit->clear();
	startMovesEdit->clear();
	randomSeedEdit->clear();
}


int MyLayout::getsize(){
    	bool good;
    	int result=sizeEdit->text().toInt(&good);
    	if(!good){
    
    		return -99;
    	}
    	return result;
    };
int MyLayout::getnum(){
    	bool good;
    	int num=startMovesEdit->text().toInt(&good);
    	if(!good){
    		return -99;
    	}
    	return num;
    };
int MyLayout::getseed(){
    	bool good;
    	int seed=randomSeedEdit->text().toInt(&good);
    	if(!good){
    		return -99;
    	}
    	return seed;
    };
