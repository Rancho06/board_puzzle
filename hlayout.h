#ifndef HLAYOUT_H
#define HLAYOUT_H

#include <QHBoxLayout>
#include <QRadioButton>
#include <QWidget>

class MainWindow;

/** This class creates two Radio Buttons
@author Shu Zhou
*/
class HLayout: public QWidget{
Q_OBJECT
	private:
	QHBoxLayout* horizon;
	QRadioButton* manhattan;
	QRadioButton* outofplace;
	MainWindow* mw;
	
	public:
	HLayout(MainWindow*);
	
	public slots:
	void changemanhattan();
	void changeoop();


};

#endif
