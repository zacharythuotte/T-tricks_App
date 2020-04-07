#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent)
	: QMainWindow(parent)
{
	gameWidget = new QWidget;

	//LAYOUT PRINCIPAL
	gameLayout = new QGridLayout;

	//BACKGROUND DE LINTERFACE
	QPixmap bkgnd("./Image/Background.jpg");
	bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	this->setPalette(palette);

	//LCD SCORE ET LIGNES
	scoreLCD = new QLCDNumber(5);
	scoreLCD->setSegmentStyle(QLCDNumber::Filled);


	//BOUTON DE GAME
	quitButton = new QPushButton("Quitter");
	QObject::connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

	pauseButton = new QPushButton("Pause");
	//QObject::connect(pauseButton,SIGNAL(clicked(), this, ));

	//PLACEMENT LAYOUT PRINCIPAL

	gameWidget->setLayout(gameLayout);
	setCentralWidget(gameWidget);
}

GameWindow::~GameWindow()
{

	
	delete gameLayout;
	delete gameWidget;

}

