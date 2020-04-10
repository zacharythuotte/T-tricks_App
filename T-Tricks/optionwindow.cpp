#include "optionwindow.h"

OptionWindow::OptionWindow(QWidget *parent) : QMainWindow(parent)
{
	optionWidget = new QWidget();

	//LAYOUT PRINCIPAL
	layoutOption = new QVBoxLayout();

	//BACKGROUND DE LINTERFACE
	//QPixmap bkgnd("./Image/Background.jpg");
	//bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
	//QPalette palette;
	//palette.setBrush(QPalette::Background, bkgnd);
	//this->setPalette(palette);

	//BOUTON DE OPTION
	acceptButton = new QPushButton("Accepter");
	acceptButton->setFixedWidth(300);
	QObject::connect(acceptButton, SIGNAL(clicked()), parent, SLOT(showMainWindow()));

	//SLIDER CHOIX VITESSE
	layoutSlider = new QGridLayout();

	labelSliderTitle = new QLabel("Vitesse de jeu");
	labelSliderTitle->setFrameStyle(QFrame::StyledPanel);
	labelSliderTitle->setStyleSheet("background-color: yellow");
	labelSliderTitle->setMaximumSize(300, 100); //////////////////////////////////
	//labelSliderTitle->setPalette(QPalette::Dark)

	labelSliderSpeed = new QLabel("1"); //Mettre vitesse en memoire dans le systeme eventuellement pour garder memoire'
	labelSliderSpeed->setFrameStyle(QFrame::StyledPanel);
	labelSliderSpeed->setStyleSheet("background-color: yellow");
	labelSliderTitle->setMaximumSize(50, 50);

	sliderSpeed = new QSlider(Qt::Horizontal);
	sliderSpeed->setTickPosition(QSlider::TicksBelow);
	sliderSpeed->setTickInterval(1);
	sliderSpeed->setRange(1, 10);
	sliderSpeed->setStyleSheet("background-color: gray");
	sliderSpeed->setFixedSize(400, 50);
	//sliderSpeed->setMaximumSize(400, 50);

	//sliderSpeed->setTracking(true);

	QObject::connect(sliderSpeed, SIGNAL(valueChanged(int)), this, SLOT(changeSpeed()));

	layoutSlider->addWidget(labelSliderTitle, 0, 0, Qt::AlignHCenter);
	layoutSlider->addWidget(labelSliderSpeed, 0, 1, Qt::AlignHCenter);
	layoutSlider->addWidget(sliderSpeed, 1, 0, 1, 2, Qt::AlignHCenter);
	
	sliderWidget = new QWidget();
	sliderWidget->setLayout(layoutSlider);
	//QPalette palette;
	//palette.setColor(QPalette::Background, Qt::gray);
	//sliderWidget->setPalette(palette);
	//sliderWidget->setAutoFillBackground(true);

	sliderWidget->setStyleSheet("border: 1px solid black; background-color: gray");
	layoutOption->addWidget(sliderWidget);

	//PLACEMENT LAYOUT PRINCIPAL
	layoutOption->addWidget(acceptButton, 300, Qt::AlignHCenter);

	optionWidget->setLayout(layoutOption);
	//optionWidget->setStyleSheet("border: 2px solid blue");
	setCentralWidget(optionWidget);
}

OptionWindow::~OptionWindow()
{
	//qInfo() << "Window doptions se fait deleter";

	/*delete acceptButton;
	delete sliderSpeed;
	delete layoutSlider;
	delete layoutOption;
	delete optionWidget;*/
}

void OptionWindow::changeSpeed()
{
	//qInfo() << QString::number(sliderSpeed->value());
	labelSliderSpeed->setText(QString::number(sliderSpeed->value()));
}

