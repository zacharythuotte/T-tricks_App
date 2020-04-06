#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	centralWidget = new QWidget();

	//LAYOUT PRINCIPAL
	layoutPrincipal = new QGridLayout();

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


	optionButton = new QPushButton("Option");
	QObject::connect(optionButton, SIGNAL(clicked()), this, SLOT(showOption()));

	exitButton = new QPushButton("Quitter");
	QObject::connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));

	//PLACEMENT LAYOUT PRINCIPAL
	layoutPrincipal->addWidget(screenTitle, 1, 4, 6, 6);
	layoutPrincipal->addWidget(startButton, 7, 6, 2, 2);
	layoutPrincipal->addWidget(optionButton, 9, 6, 2, 2);
	layoutPrincipal->addWidget(exitButton, 11, 6, 2, 2);
	
	centralWidget->setLayout(layoutPrincipal);
	setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
	delete startButton;
	delete optionButton;
	delete exitButton;
	
	delete screenTitle;
	delete layoutPrincipal;
	delete centralWidget;
	
}

void MainWindow::showOption()
{
	optionPage = new OptionWindow();
	optionPage->show();
}


