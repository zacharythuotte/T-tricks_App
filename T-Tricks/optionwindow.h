#ifndef	OPTIONWINDOW_H
#define OPTIONWINDOW_H

#include <QMainWindow>
#include <qlayout.h>
#include <qpushbutton.h>
#include <qlabel.h>


class OptionWindow : public QMainWindow
{
	Q_OBJECT

public:
	OptionWindow(QWidget *parent = nullptr);
	~OptionWindow();
public slots:
	

private:
	QWidget *optionWidget;
	QGridLayout *layoutOption;


};
#endif // MAINWINDOW_H
