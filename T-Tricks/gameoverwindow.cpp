#include "GameOverWindow.h"
#include "MainWindow.h"

GameOverWindow::GameOverWindow(QWidget *parent) : QMainWindow(parent)
{
	parentWindow = parent;

	gameOverWidget = new QWidget();

	//LAYOUT PRINCIPAL
	layoutGameOver = new QGridLayout;

	//BACKGROUND DE LINTERFACE
	QPixmap bkgnd("./Image/Background.jpg");
	bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	this->setPalette(palette);

	//BOUTON DE OPTION
	acceptButton = new QPushButton("Accepter");
	QObject::connect(acceptButton, SIGNAL(clicked()), this, SLOT(goToMainWindow()));

	//PLACEMENT LAYOUT PRINCIPAL
	layoutGameOver->addWidget(acceptButton, 1, 0);

	gameOverWidget->setLayout(layoutGameOver);
	setCentralWidget(gameOverWidget);
}

GameOverWindow::~GameOverWindow()
{
	delete acceptButton;
	delete layoutGameOver;
}

void GameOverWindow::goToMainWindow()
{
	//qInfo() << "passe ici";
	//setCentralWidget(parentWindow);
	//this->close();
}

