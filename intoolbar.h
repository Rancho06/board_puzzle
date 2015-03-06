#ifndef INTOOLBAR_H
#define INTOOLBAR_H
#include <QtGui/QApplication>
#include <QToolBar>
#include <QAction>
#include "main_window.h"
#include "guitile.h"
#include "puzzle_solver.h"
#include "puzzle_heur.h"
#include "board.h"

/**
This class creates three actions in the tool bar to start, quit and run A*
@author Shu Zhou
*/
class InToolBar: public QToolBar{
Q_OBJECT
private:/// A pointer to the main window
	MainWindow* mw;
	/// A pointer to the QApplication object
	QApplication* qa;
public:
	InToolBar(MainWindow*,QApplication*);
public slots:
	void startGame();
	void quitGame();
	void run();

};

#endif
