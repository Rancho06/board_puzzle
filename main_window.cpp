#include "main_window.h"
#include <QMenuBar>
#include "intoolbar.h"
#include <QAction>

/**
Constructor:
 To create the child widgets
@param app a pointer to the QApplication Object in the qtpuzzle.cpp
*/
MainWindow::MainWindow(QApplication* app):QMainWindow(){
	//creating the error box
	errorBox=new QTextEdit;
	
	//creating the central graphics window
	gw=new GraphicsWindow(errorBox);
	this->setCentralWidget(gw);
	
	//creating the menu bar with a sub action called exit, which stops the game
	QMenuBar* mb=menuBar();
	QMenu* fileMenu=new QMenu("File");
	QAction* q=new QAction("Exit",this);
	fileMenu->addAction(q);
	mb->addMenu(fileMenu);
	
	//creating the tool bar
	InToolBar *toolbar=new InToolBar(this,app);
	connect(q,SIGNAL(triggered()),toolbar,SLOT(quitGame()));
	this->addToolBar(toolbar);
	
	//creating the Top Dock Widget for putting error box
	QDockWidget* qdwtop=new QDockWidget("Message Box");
	qdwtop->setWidget(errorBox);
	errorBox->setReadOnly(true);
	addDockWidget(Qt::TopDockWidgetArea,qdwtop);
	qdwtop->setFeatures(QDockWidget::NoDockWidgetFeatures);
	
	//creating the left dock widget for putting board settings(size, num, seed)
	layout=new MyLayout();
	QDockWidget* qdwleft=new QDockWidget("Board Settings");
	qdwleft->setWidget(layout);
	addDockWidget(Qt::LeftDockWidgetArea,qdwleft);
	qdwleft->setFeatures(QDockWidget::NoDockWidgetFeatures);
	
	//creating the left dock widget for putting heuristic radio buttons
	horizontal=new HLayout(this);
	QDockWidget* radiobutton=new QDockWidget("Heuristic Option");
	radiobutton->setWidget(horizontal);
	addDockWidget(Qt::LeftDockWidgetArea,radiobutton);
	radiobutton->setFeatures(QDockWidget::NoDockWidgetFeatures);
	
	
	//creating the left dock widget for displaying results from A* algorithm
	QDockWidget* qdwbottom=new QDockWidget("Cheat Box");
	list=new QListWidget();
	qdwbottom->setWidget(list);
	addDockWidget(Qt::LeftDockWidgetArea,qdwbottom);
	qdwbottom->setFeatures(QDockWidget::NoDockWidgetFeatures);
	
	
	
}

