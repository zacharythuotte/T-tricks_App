#include "optionwindow.h"

OptionWindow::OptionWindow(QWidget *parent) : QMainWindow(parent)
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

	//SLIDER CHOIX VITESSE
	layoutSlider = new QGridLayout();

	labelSliderTitle = new QLabel("Vitesse de départ");
	labelSliderTitle->setFrameStyle(QFrame::StyledPanel);
	labelSliderTitle->setStyleSheet("background-color: yellow");
	labelSliderTitle->setMaximumSize(300, 50); //////////////////////////////////
	//labelSliderTitle->setPalette(QPalette::Dark)

	labelSliderSpeed = new QLabel("1"); //Mettre vitesse en memoire dans le systeme eventuellement pour garder memoire

	sliderSpeed = new QSlider(Qt::Horizontal);
	sliderSpeed->setTickPosition(QSlider::TicksBelow);
	sliderSpeed->setTickInterval(1);
	sliderSpeed->setRange(1, 10);

	//sliderSpeed->setTracking(true);

	QObject::connect(sliderSpeed, SIGNAL(valueChanged(int)), this, SLOT(changeSpeed()));

	layoutSlider->addWidget(labelSliderTitle, 0, 0, Qt::AlignHCenter);
	layoutSlider->addWidget(labelSliderSpeed, 0, 1, Qt::AlignHCenter);
	layoutSlider->addWidget(sliderSpeed, 1, 0, 1, 2, Qt::AlignHCenter);
	layoutOption->addLayout(layoutSlider, 0, 0);

	//PLACEMENT LAYOUT PRINCIPAL
	layoutOption->addWidget(acceptButton, 1, 0);

	optionWidget->setLayout(layoutOption);
	setCentralWidget(optionWidget);
}

OptionWindow::~OptionWindow()
{
	delete acceptButton;

	delete layoutOption;
	delete layoutSlider;
	delete sliderSpeed;
	delete optionWidget;
}

void OptionWindow::changeSpeed()
{
	//qInfo() << QString::number(sliderSpeed->value());
	labelSliderSpeed->setText(QString::number(sliderSpeed->value()));
}

