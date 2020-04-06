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

	
	optionWidget->setLayout(layoutOption);
	setCentralWidget(optionWidget);

}

OptionWindow::~OptionWindow()
{
	
	delete layoutOption;
	delete optionWidget;
}

