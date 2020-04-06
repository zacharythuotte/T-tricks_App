#include "optionwindow.h"

OptionWindow::OptionWindow(QWidget *parent)
	: QMainWindow(parent)
{
	optionWidget = new QWidget();

	//LAYOUT PRINCIPAL
	layoutOption = new QGridLayout;

	//BACKGROUND DE LINTERFACE
	QPixmap bkgnd("./Image/Background.jpg");
	bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, bkgnd);
	this->setPalette(palette);

	//BOUTON DE OPTION
	acceptButton = new QPushButton("Accepter");
	QObject::connect(acceptButton, SIGNAL(clicked()), this, SLOT(close()));

	//PLACEMENT LAYOUT PRINCIPAL
	layoutOption->addWidget(acceptButton);

	optionWidget->setLayout(layoutOption);
	setCentralWidget(optionWidget);

}

OptionWindow::~OptionWindow()
{
	delete acceptButton;

	delete layoutOption;
	delete optionWidget;
}

