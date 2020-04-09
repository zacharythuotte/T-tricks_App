#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	centralWidget = new QWidget();
	pagesStack = new QStackedWidget();
	optionPage = new OptionWindow(this);
	pagesStack->addWidget(optionPage);
	leaderboardPage = new LeaderboardWindow(this);
	pagesStack->addWidget(leaderboardPage);
	
	//MUSIQUE
	musique = new QSoundEffect();
	musique->setSource(QUrl::fromLocalFile("./Image/TetrisMetal.wav"));
	musique->play();
	musique->setLoopCount(QSoundEffect::Infinite);
	//musique->setVolume(0.5);

	//LAYOUT
	layoutPrincipal = new QVBoxLayout();

	//BARRE OUTILS (VOLUME)
	sliderVolume = new QSlider(Qt::Horizontal);
	QObject::connect(sliderVolume, SIGNAL(valueChanged(int)), this, SLOT(changeVolume()));
	sliderVolume->setValue(5); //Mettre la valeur en memoire//////////////////////////////////////////
	sliderVolume->setRange(0, 100);

	toolBar = new QToolBar("Volume");
	this->setContextMenuPolicy(Qt::NoContextMenu); //Empeche denlever la toolbar
	//toolBar->addWidget()
	toolBar->addWidget(new QLabel("Volume"));
	toolBar->addSeparator();
	toolBar->addWidget(sliderVolume);
	toolBar->setMaximumWidth(300);
	toolBar->setMovable(false);
	//toolBar->setStyle(QStyle::) //Rendre plus visible...

	this->addToolBar(Qt::BottomToolBarArea, toolBar);

	//BACKGROUND DE LINTERFACE
	QPixmap bkgnd("./Image/Background.jpg");
	bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	this->setPalette(palette);
	
	//IMAGE TITRE
	screenTitle = new QLabel();
	screenTitle->setPixmap(QPixmap("./Image/Screentitle.png"));
	screenTitle->setAlignment(Qt::AlignCenter);

	//BOUTONs MENU PRINCIPAL
	startButton = new QPushButton("Jouer!");
	QObject::connect(startButton, SIGNAL(clicked()), this, SLOT(showGame()));

	optionButton = new QPushButton("Options");
	QObject::connect(optionButton, SIGNAL(clicked()), this, SLOT(showOption()));

	leaderboardButton = new QPushButton("Voir meilleurs scores");
	QObject::connect(leaderboardButton, SIGNAL(clicked()), this, SLOT(showLeaderboard()));
	//QObject::connect(volumeButton, SIGNAL(clicked()), musique, SLOT(stop()));

	exitButton = new QPushButton("Quitter");
	QObject::connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));

	//PLACEMENT LAYOUT PRINCIPAL
	layoutPrincipal->addWidget(screenTitle);
	layoutPrincipal->addWidget(startButton);
	layoutPrincipal->addWidget(optionButton);
	layoutPrincipal->addWidget(leaderboardButton);
	layoutPrincipal->addWidget(exitButton);
	
	centralWidget->setLayout(layoutPrincipal);
	pagesStack->addWidget(centralWidget);
	//setCentralWidget(centralWidget);


	setCentralWidget(pagesStack);
	pagesStack->setCurrentWidget(centralWidget);
}

MainWindow::~MainWindow()
{
	delete startButton;
	delete optionButton;
	delete leaderboardButton;
	delete sliderVolume;
	delete toolBar;

	delete exitButton;
	delete musique;

	delete screenTitle;
	delete layoutPrincipal;
	delete centralWidget;
}

//CETTE FONCTION MONTRE LA FENETRE D OPTIONS
void MainWindow::showOption()
{
	pagesStack->setCurrentWidget(optionPage);
	//setCentralWidget(optionPage);
	//optionPage->show();
}

//CETTE FONCTION MONTRE LA FENETRE DE JEU
void MainWindow::showGame()
{
	gamePage = new GameWindow();
	setCentralWidget(gamePage);
	//gamePage->show();
}

void MainWindow::showLeaderboard()
{
	pagesStack->setCurrentWidget(leaderboardPage);
}

//CETTE FONCTION MONTRE LA FENETRE DE FIN DE JEU POUR LES TESTS ///////////////////////////
void MainWindow::showGameOver()
{
	gameOverPage = new GameOverWindow(centralWidget);
	setCentralWidget(gameOverPage);
	QObject::connect(gameOverPage, SIGNAL(closed()), this, SLOT(showMainWindow()));
	//gamePage->show();
}

void MainWindow::changeVolume()
{
	musique->setVolume((sliderVolume->value())/100.0);
}

void MainWindow::showMainWindow()
{
	pagesStack->setCurrentWidget(centralWidget);
	//setCentralWidget(centralWidget);
}
