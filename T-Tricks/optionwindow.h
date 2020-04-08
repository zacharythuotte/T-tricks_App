#ifndef	OPTIONWINDOW_H
#define OPTIONWINDOW_H

#include <QMainWindow>
#include <qlayout.h>
#include <Qpushbutton.h>
#include <Qlabel.h>
#include <QSound.h>
#include <QSlider>
//#include <Qdebug.h>

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
	QGridLayout *layoutOption;
	QGridLayout *layoutSlider;
	QPushButton *acceptButton;
	QSlider *sliderSpeed;
	QLabel *labelSliderTitle;
	QLabel *labelSliderSpeed;
};
#endif // MAINWINDOW_H
