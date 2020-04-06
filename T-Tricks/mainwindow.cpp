#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	centralWidget = new QWidget();
	
	//MUSIQUE
	musique = new QSound("./Image/TetrisMetal.wav");
	musique->play();
	musique->setLoops(-1);

	//LAYOUT
	layoutPrincipal = new QVBoxLayout();

	//BACKGROUND DE LINTERFACE
	QPixmap bkgnd("./Image/Background.jpg");
	bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	this->setPalette(palette);
	
	//IMAGE TITRE
	screenTitle = new QLabel();
	screenTitle->setPixmap(QPixmap("./Image/Screentitle.png"));

	//BOUTON MENU PRINCIPAL
	startButton = new QPushButton("Commencer!");
	QObject::connect(startButton, SIGNAL(clicked()), this, SLOT(showGame()));

	optionButton = new QPushButton("Option");
	QObject::connect(optionButton, SIGNAL(clicked()), this, SLOT(showOption()));

	volumeButton = new QPushButton("Musique");
	QObject::connect(volumeButton, SIGNAL(clicked()), musique, SLOT(stop()));

	exitButton = new QPushButton("Quitter");
	QObject::connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));

	//PLACEMENT LAYOUT PRINCIPAL
	layoutPrincipal->addWidget(screenTitle);
	layoutPrincipal->addWidget(startButton);
	layoutPrincipal->addWidget(optionButton);
	layoutPrincipal->addWidget(volumeButton);
	layoutPrincipal->addWidget(exitButton);
	
	centralWidget->setLayout(layoutPrincipal);
	setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
	delete startButton;
	delete optionButton;
	delete volumeButton;
	delete exitButton;
	delete musique;

	delete screenTitle;
	delete layoutPrincipal;
	delete centralWidget;
	
}

//CETTE FONCTION MONTRE LA FENETRE DOPTION
void MainWindow::showOption()
{
	optionPage = new OptionWindow();
	optionPage->show();
}

//CETTE FONCTION MONTRE LA FENETRE DE JEU
void MainWindow::showGame()
{
	gamePage = new GameWindow;
	gamePage->show();
}


