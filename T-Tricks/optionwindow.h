#ifndef	OPTIONWINDOW_H
#define OPTIONWINDOW_H

#include <QMainWindow.h>
#include <qlayout.h>
#include <Qpushbutton.h>
#include <Qlabel.h>
#include <QSound.h>
#include <QSlider.h>
#include <qpalette.h>

class OptionWindow : public QMainWindow
{
	Q_OBJECT

public:
	OptionWindow(QWidget *parent = nullptr);
	~OptionWindow();
public slots:
	void changeSpeed();

private:
	QWidget *optionWidget;
	QWidget *sliderWidget; //Slider pour le groupe de widgets relies au slider
	QVBoxLayout *layoutOption;
	QGridLayout *layoutSlider;
	QPushButton *acceptButton;
	QSlider *sliderSpeed;
	QLabel *labelSliderTitle;
	QLabel *labelSliderSpeed;
};
#endif // MAINWINDOW_H
