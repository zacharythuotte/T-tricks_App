#include "gamewindow.h"

#include <chrono>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <conio.h>
#define LARGEUR 10
#define HAUTEUR 24 

class GameBoard : public QFrame
{
	Q_OBJECT

public:
	GameBoard(QWidget *parent = nullptr);
	~GameBoard();

	QSize sizeHint() const override;
	QSize minimumSizeHint() const override;

	void afficher();
	bool collision(GameForme *forme);
	void ligneComplete();
	void shiftBoard(int index);
	void input();
	void mort();
	void bougerForme(GameForme *forme, int x, int y);
	void changerForme();
	void tournerForme(GameForme *forme);
	void tournerForme(GameForme *forme, int direction);
	void formeVersBoard(GameForme *forme);
	void loop();

protected:
	void paintEvent(QPaintEvent *event) override;
	void keyPressEvent(QKeyEvent *event) override;
	void timerEvent(QTimerEvent *event) override;

private:
	
	int squareWidth() { return contentsRect().width() / LARGEUR; }
	int squareHeight() { return contentsRect().height() / HAUTEUR; }

	GameForme *curForme;
	GameForme *preview;
	GameForme *prochaineForme;
	GameLevel level;
	int board[HAUTEUR][LARGEUR] = { 0 };
	int score;
	int linesCleared;
	bool alive;
	std::chrono::time_point<std::chrono::high_resolution_clock> lastAction, curTime;


};
