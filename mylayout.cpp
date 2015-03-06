#include "mylayout.h"

/**
Constructor sets three QLineEdit objects
*/
MyLayout::MyLayout():QWidget(){
	layout=new QFormLayout;
	setLayout(layout);
	sizeEdit=new QLineEdit();
	startMovesEdit=new QLineEdit();
	randomSeedEdit=new QLineEdit();
	
	layout->addRow("Board Size:",sizeEdit);
	layout->addRow("Starting Moves:",startMovesEdit);
	layout->addRow("Random Seed Value:",randomSeedEdit);
}

/** Delete the contents in the three QLineEdit objects*/
void MyLayout::reset(){
	sizeEdit->clear();
	startMovesEdit->clear();
	randomSeedEdit->clear();
}

/** @return The size of the board*/
int MyLayout::getsize(){
    	bool good;
    	int result=sizeEdit->text().toInt(&good);
    	if(!good){
    
    		return -99;
    	}
    	return result;
    };
    
/** @return Initial moves of the board*/
int MyLayout::getnum(){
    	bool good;
    	int num=startMovesEdit->text().toInt(&good);
    	if(!good){
    		return -99;
    	}
    	return num;
    };
    
/** @return Random Seed Number*/
int MyLayout::getseed(){
    	bool good;
    	int seed=randomSeedEdit->text().toInt(&good);
    	if(!good){
    		return -99;
    	}
    	return seed;
    };
