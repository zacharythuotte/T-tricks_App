#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlayout.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QSound.h>
#include <qtoolbar.h>

#include "optionwindow.h"
#include "gamewindow.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
	void showOption();
	void showGame();

private:
	QWidget *centralWidget;
	QVBoxLayout *layoutPrincipal;
	QSound *musique;
	QPushButton *startButton;
	QPushButton *optionButton;
	QPushButton *volumeButton;
	QPushButton *exitButton;
	QAction *startAct;
	QAction *optionAct;
	QAction *exitAct;
	QLabel *screenTitle;
	OptionWindow *optionPage;
	GameWindow *gamePage;
	QToolBar *toolBar;
	QSlider *sliderVolume;
};
#endif // MAINWINDOW_H
