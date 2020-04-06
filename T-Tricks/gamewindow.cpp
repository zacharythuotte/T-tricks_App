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

	//BOUTON DE OPTION
	

	//PLACEMENT LAYOUT PRINCIPAL

	gameWidget->setLayout(gameLayout);
	setCentralWidget(gameWidget);
}

GameWindow::~GameWindow()
{

	
	delete gameLayout;
	delete gameWidget;

}

