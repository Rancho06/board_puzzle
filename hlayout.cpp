#include "hlayout.h"
#include "main_window.h"

/** Constructor creates two QRadioButtons
@param m_w A pointer to the main window object
*/
HLayout::HLayout(MainWindow* m_w){
	mw=m_w;
	horizon=new QHBoxLayout();
	manhattan=new QRadioButton("Manhattan");
	outofplace=new QRadioButton("OutOfPlace");
	this->setLayout(horizon);
	horizon->addWidget(manhattan);
	horizon->addWidget(outofplace);
	
	connect(manhattan,SIGNAL(clicked()),this, SLOT(changemanhattan()));
	connect(outofplace,SIGNAL(clicked()),this, SLOT(changeoop()));
}

/** This function sets the heuristic to manhattan*/
void HLayout::changemanhattan(){
	mw->getgraphwindow()->setmanhattan();
}

/** This function sets the heuristic to outofplace*/
void HLayout::changeoop(){
	mw->getgraphwindow()->setoop();

}
