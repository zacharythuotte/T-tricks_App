#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlayout.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <QSoundEffect.h>
#include <qtoolbar.h>

#include "optionwindow.h"
#include "gamewindow.h"
#include "gameoverwindow.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
	void showOption();
	void showGame();
	void showGameOver();

	void changeVolume();

private:
	QWidget *centralWidget;
	QVBoxLayout *layoutPrincipal;
	QSoundEffect *musique;
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
	GameOverWindow *gameOverPage;
	QToolBar *toolBar;
	QSlider *sliderVolume;
};
#endif // MAINWINDOW_H
