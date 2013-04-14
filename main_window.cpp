#include "main_window.h"
#include <QMenuBar>
#include "intoolbar.h"
#include <QAction>


MainWindow::MainWindow(QApplication* app):QMainWindow(){
	errorBox=new QTextEdit;
	gw=new GraphicsWindow(errorBox);
	this->setCentralWidget(gw);
	QMenuBar* mb=menuBar();
	QMenu* fileMenu=new QMenu("File");
	QAction* q=new QAction("Exit",this);
	
	fileMenu->addAction(q);
	mb->addMenu(fileMenu);
	
	InToolBar *toolbar=new InToolBar(this,app);
	connect(q,SIGNAL(triggered()),toolbar,SLOT(quitGame()));
	this->addToolBar(toolbar);
	
	
	QDockWidget* qdwtop=new QDockWidget("Error Box");
	qdwtop->setWidget(errorBox);
	errorBox->setReadOnly(true);
	addDockWidget(Qt::TopDockWidgetArea,qdwtop);
	qdwtop->setFeatures(QDockWidget::NoDockWidgetFeatures);
	
	
	layout=new MyLayout(gw);
	QDockWidget* qdwleft=new QDockWidget("Board Settings");
	qdwleft->setWidget(layout);
	addDockWidget(Qt::LeftDockWidgetArea,qdwleft);
	qdwleft->setFeatures(QDockWidget::NoDockWidgetFeatures);
	
	horizontal=new HLayout(this);
	QDockWidget* radiobutton=new QDockWidget("Heuristic Option");
	radiobutton->setWidget(horizontal);
	addDockWidget(Qt::LeftDockWidgetArea,radiobutton);
	radiobutton->setFeatures(QDockWidget::NoDockWidgetFeatures);
	
	
	
	QDockWidget* qdwbottom=new QDockWidget("Cheat Box");
	list=new QListWidget();
	
	qdwbottom->setWidget(list);
	addDockWidget(Qt::LeftDockWidgetArea,qdwbottom);
	qdwbottom->setFeatures(QDockWidget::NoDockWidgetFeatures);
	
	
	
}

