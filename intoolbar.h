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

class InToolBar: public QToolBar{
Q_OBJECT
private:
	MainWindow* mw;
	QApplication* qa;
public:
	InToolBar(MainWindow*,QApplication*);
public slots:
	void startGame();
	void quitGame();
	void run();

};

#endif
