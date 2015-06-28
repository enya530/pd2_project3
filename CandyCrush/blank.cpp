#include "blank.h"

Blank::Blank(QWidget *parent, int R, int C):QObject(parent), row(R), column(C)
{
    button = new QPushButton(parent);
    button -> setGeometry(column*50, row*50, 50, 50);
    connect(button, SIGNAL(clicked()), this, SLOT(click()));
}

Blank::~Blank()
{

}

void Blank::setButtonPicture()
{
    switch(number){
        case 1:
            button->setIcon(QIcon(QPixmap(":/p/red.png")));
        break;
        case 11:
            button->setIcon(QIcon(QPixmap(":/p/red_vertical_bomb.png")));
        break;
        case 12:
            button->setIcon(QIcon(QPixmap(":/p/red_horizontal_bomb.png")));
        break;
        case 13:
            button->setIcon(QIcon(QPixmap(":/p/red_bomb.png")));
        break;
        case 2:
            button->setIcon(QIcon(QPixmap(":/p/yellow.png")));
        break;
        case 21:
            button->setIcon(QIcon(QPixmap(":/p/yellow_vertical_bomb.png")));
        break;
        case 22:
            button->setIcon(QIcon(QPixmap(":/p/yellow_horizontal_bomb.png")));
        break;
        case 23:
            button->setIcon(QIcon(QPixmap(":/p/yellow_bomb.png")));
        break;
        case 3:
            button->setIcon(QIcon(QPixmap(":/pic/green.png")));
        break;
        case 31:
            button->setIcon(QIcon(QPixmap(":/pic/green_vertical_bomb.png")));
        break;
        case 32:
            button->setIcon(QIcon(QPixmap(":/pic/green_horizontal_bomb.png")));
        break;
        case 33:
            button->setIcon(QIcon(QPixmap(":/pic/green_bomb.png")));
        break;
        case 4:
            button->setIcon(QIcon(QPixmap(":/pic/blue.png")));
        break;
        case 41:
            button->setIcon(QIcon(QPixmap(":/pic/blue_vertical_bomb.png")));
        break;
        case 42:
            button->setIcon(QIcon(QPixmap(":/pic/blue_horizontal_bomb.png")));
        break;
        case 43:
            button->setIcon(QIcon(QPixmap(":/pic/blue_bomb.png")));
        break;
        case 5:
            button->setIcon(QIcon(QPixmap(":/pic/power_bomb.png")));
        break;
    default:
        button->setIcon(QIcon(QPixmap("No pic")));

    }// end switch
}

void Blank::setRandomNumber()
{
    number = rand()%4+1;
    return;
}

void Blank::operator -(Blank *a)
{
    int tmp_num = a->number;
    a->number = number;
    number = tmp_num;
    setButtonPicture();
    a->setButtonPicture();
}

void Blank::operator |(Blank *a)
{
    int tmp_num = a->number;
    a->number = number;
    number = tmp_num;
    setButtonPicture();
    a->setButtonPicture();
}

void Blank::click()
{
    emit Click(row,column);
}
