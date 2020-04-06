#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlayout.h>
#include <qpushbutton.h>
#include <qlabel.h>

#include "optionwindow.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
	void showOption();

private:
	QWidget *centralWidget;
	QGridLayout *layoutPrincipal;
	QPushButton *startButton;
	QPushButton *optionButton;
	QPushButton *exitButton;
	QAction *startAct;
	QAction *optionAct;
	QAction *exitAct;
	QLabel *screenTitle;
	OptionWindow *optionPage;
	

};
#endif // MAINWINDOW_H
