#include "gameover.h"
#include "ui_gameover.h"

GameOver::GameOver(QWidget *parent, int score, int star) :
    QWidget(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);
    score_str = QString::number(score, 10);
    star_str = QString::number(star, 10);
    ui->score->setText(QString(score_str));
    ui->star->setText(QString(star_str));
}

GameOver::~GameOver()
{
    delete ui;
}
