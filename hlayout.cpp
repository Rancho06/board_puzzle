#include "hlayout.h"
#include "main_window.h"

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


void HLayout::changemanhattan(){
	mw->getgraphwindow()->setmanhattan();
}

void HLayout::changeoop(){
	mw->getgraphwindow()->setoop();

}

void HLayout::resetbutton(){
	manhattan->setChecked(true);
	outofplace->setChecked(true);

}
