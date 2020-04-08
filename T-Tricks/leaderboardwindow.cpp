#include "leaderboardwindow.h"
#include "MainWindow.h"

LeaderboardWindow::LeaderboardWindow(QWidget *parent) : QMainWindow(parent)
{
	leaderboardWidget = new QWidget();

	//LAYOUT PRINCIPAL
	layoutLeaderboard = new QGridLayout;

	//BACKGROUND DE LINTERFACE
	QPixmap bkgnd("./Image/Background.jpg");
	bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	this->setPalette(palette);

	//GRILLE MEILLEURS SCORES
	tableLeaderboard = new QTableWidget();
	//QLabel *a;
	//a = new QLabel("Itemtest1");
	tableLeaderboard->setItem(0, 0, new QTableWidgetItem("Hello"));
	tableLeaderboard->setShowGrid(true);

	//BOUTON DE OPTION
	acceptButton = new QPushButton("Accepter");
	QObject::connect(acceptButton, SIGNAL(clicked()), this, SLOT(goToMainWindow()));

	//PLACEMENT LAYOUT PRINCIPAL
	layoutLeaderboard->addWidget(acceptButton, 1, 0);

	leaderboardWidget->setLayout(layoutLeaderboard);
	setCentralWidget(leaderboardWidget);
}

LeaderboardWindow::~LeaderboardWindow()
{
	delete acceptButton;
	delete layoutLeaderboard;
}

void LeaderboardWindow::goToMainWindow()
{
	this->hide();
}

