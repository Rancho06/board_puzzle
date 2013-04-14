#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "graphicswindow.h"
#include <QDockWidget>
#include "mylayout.h"
#include <QListWidget>
#include <QTextEdit>
#include "hlayout.h"

class MainWindow: public QMainWindow{
	Q_OBJECT
	public:
		MainWindow(QApplication*);
		GraphicsWindow* getgraphwindow(){return gw;};
		MyLayout* getlayout(){return layout;};
		QListWidget* getlist(){return list;};
		QTextEdit* getErrorBox(){return errorBox;};
		HLayout* gethorizon(){return horizontal;};
		
	private:
		GraphicsWindow* gw;
		MyLayout* layout;
		QListWidget* list;
		QTextEdit* errorBox;
		HLayout* horizontal;
		
};


#endif
