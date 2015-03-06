#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "graphicswindow.h"
#include <QDockWidget>
#include "mylayout.h"
#include <QListWidget>
#include <QTextEdit>
#include "hlayout.h"

/**
	This class creates all the widgets displayed in the window
	@author Shu Zhou
*/
class MainWindow: public QMainWindow{
	Q_OBJECT
	public:
		MainWindow(QApplication*);
		
		/**  Get a pointer to the graphics window
		@return A pointer to the graphics window
		*/
		GraphicsWindow* getgraphwindow(){return gw;};
		
		/** Get a pinter to the Layout with three QLineEdit objects
		@return A pointer to the three QLineEdit objects
		*/
		MyLayout* getlayout(){return layout;};
		
		/** Get a pointer to the cheat box
		@return A pointer to the cheat box
		*/
		QListWidget* getlist(){return list;};
		
		/** Get a pointer to the error box
		@return A pointer to the error box
		*/
		QTextEdit* getErrorBox(){return errorBox;};
		
		/** Get a pointer to the RadioButtons
		@return A pointer to the RadioButtons
		*/
		HLayout* gethorizon(){return horizontal;};
		
	private:/// A pointer to the graphics window
		GraphicsWindow* gw;
		/// A pointer to the layout
		MyLayout* layout;
		/// A pointer to the list box
		QListWidget* list;
		///A pointer to the error box
		QTextEdit* errorBox;
		///A pointer to the RadioButtons
		HLayout* horizontal;
		
};


#endif
