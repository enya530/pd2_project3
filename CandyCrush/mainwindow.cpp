#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            b[i][j] = new Blank(this, i, j);
            connect(b[i][j], SIGNAL(Click(int,int)), this, SLOT(button_clicked(int,int)));
        }// end inner for
    }// end for

    t = new QTimer();
    connect(t, SIGNAL(timeout()), this,SLOT(Time()));
    t->start(1000);


    //ui->background->setPixmap(QPixmap(":/pic/background.png"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GameStart()
{
    /**note:
     *     if there are three same color in a row/column   ( if(...) )
     *     reset the color of that square you are setting  ( j-- )
     */
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            b[i][j]->setRandomNumber();
            b[i][j]->setButtonPicture();
            // row
            if(j >= 2 && b[i][j]->number == b[i][j-1]->number && b[i][j]->number == b[i][j-2]->number){
                j--;
            }// end if

            // column
            if(i >= 2 && b[i][j]->number == b[i-1][j]->number && b[i][j]->number == b[i-2][j]->number){
                j--;
            }// end if
        }// end inner for
    }// end outer for

    gameOpened = false;
    time = 60;


    score_int = 0;
    star_int = 0;
    SetScore();
    isClicked = false;
}

void MainWindow::setClickedPicture(Blank *a)
{
    if(!isClicked){
        switch(a->number){
        case 1:
            a->button->setIcon(QIcon(QPixmap(":/p/red_clicked.png")));
        break;
        case 11:
            a->button->setIcon(QIcon(QPixmap(":/p/red_vertical_bomb_clicked.png")));
        break;
        case 12:
            a->button->setIcon(QIcon(QPixmap(":/p/red_horizontal_bomb_clicked.png")));
        break;
        case 13:
            a->button->setIcon(QIcon(QPixmap(":/p/red_bomb_clicked.png")));
        break;
        case 2:
            a->button->setIcon(QIcon(QPixmap(":/p/yellow_clicked.png")));
        break;
        case 21:
            a->button->setIcon(QIcon(QPixmap(":/p/yellow_vertical_bomb_clicked.png")));
        break;
        case 22:
            a->button->setIcon(QIcon(QPixmap(":/p/yellow_horizontal_bomb_clicked.png")));
        break;
        case 23:
            a->button->setIcon(QIcon(QPixmap(":/p/yellow_bomb_clicked.png")));
        break;
        case 3:
            a->button->setIcon(QIcon(QPixmap(":/pic/green_clicked.png")));
        break;
        case 31:
            a->button->setIcon(QIcon(QPixmap(":/pic/green_vertical_bomb_clicked.png")));
        break;
        case 32:
            a->button->setIcon(QIcon(QPixmap(":/pic/green_horizontal_bomb_clicked.png")));
        break;
        case 33:
            a->button->setIcon(QIcon(QPixmap(":/pic/green_bomb_clicked.png")));
        break;
        case 4:
            a->button->setIcon(QIcon(QPixmap(":/pic/blue_clicked.png")));
        break;
        case 41:
            a->button->setIcon(QIcon(QPixmap(":/pic/blue_vertical_bomb_clicked.png")));
        break;
        case 42:
            a->button->setIcon(QIcon(QPixmap(":/pic/blue_horizontal_bomb_clicked.png")));
        break;
        case 43:
            a->button->setIcon(QIcon(QPixmap(":/pic/blue_bomb_clicked.png")));
        break;
        case 5:
            a->button->setIcon(QIcon(QPixmap(":/pic/power_bomb_clicked.png")));
        break;
    default:
        a->button->setIcon(QIcon(QPixmap("No pic")));

        }// end switch
    }else{
        a->setButtonPicture();
    }
}

bool MainWindow::Judge(int row1, int column1, int row2, int column2)
{
    bool JudgeTable[9];
    Destroy *d;
    if((b[row1][column1]->number == 5 && b[row2][column2]->number != 5 && b[row2][column2]->number != 0)){
        d = new Star;
        d->eliminate(b, b[row2][column2]);
        b[row1][column1]->number = 0;
        JudgeTable[8] = 1;
    }else if(b[row2][column2]->number == 5 && b[row1][column1]->number != 5 && b[row2][column2]->number != 0){
        d = new Star;
        d->eliminate(b, b[row1][column1]);
        b[row2][column2]->number = 0;
        JudgeTable[8] = 1;
    }// end if
    JudgeTable[0] = JudgeStar(row1, column1);
    JudgeTable[1] = JudgeStar(row2, column2);
    JudgeTable[2] = JudgeNine(row1, column1);
    JudgeTable[3] = JudgeNine(row2, column2);
    JudgeTable[4] = JudgeHori(row1, column1);
    JudgeTable[5] = JudgeHori(row2, column2);
    JudgeTable[6] = JudgeVerti(row1, column1);
    JudgeTable[7] = JudgeVerti(row2, column2);


    RenewPicture();

    for(int i = 0; i < 9; i++){
        //qDebug()<<JudgeTable[i];
        if(JudgeTable[i] == 1){
            return 1;
        }// end if
    }// end for

    return 0;
}

bool MainWindow::JudgeStar(int R, int C)
{
    int return_value;
    bool AnySpawn = false;
    destroy = new Star;
    return_value = destroy->condition(b,b[R][C]);
    if(return_value){
        switch(return_value){
        case 1:
            destroy->spawn(b, b[R][C], 1);
            AnySpawn = true;
            star_int++;
            break;
        case 2:
            destroy->spawn(b, b[R][C], 2);
            AnySpawn = true;
            star_int++;
            break;
        case 3:
            destroy->spawn(b, b[R][C], 3);
            AnySpawn = true;
            star_int++;
            break;
        case 4:
            destroy->spawn(b, b[R][C], 4);
            AnySpawn = true;
            star_int++;
            break;
        }// end switch
    }// end if
    delete destroy;
    return AnySpawn;
}

bool MainWindow::JudgeNine(int R, int C)
{
    int return_value;
    bool AnySpawn = false;
    destroy = new NineBlock;
    return_value = destroy->condition(b,b[R][C]);
    if(return_value){
        switch(return_value){
        case 1:
            destroy->spawn(b, b[R][C], 1);
            AnySpawn = true;
            break;
        case 2:
            destroy->spawn(b, b[R][C], 2);
            AnySpawn = true;
            break;
        case 3:
            destroy->spawn(b, b[R][C], 3);
            AnySpawn = true;
            break;
        case 4:
            destroy->spawn(b, b[R][C], 4);
            AnySpawn = true;
            break;
        case 5:
            destroy->spawn(b, b[R][C], 5);
            AnySpawn = true;
            break;
        case 6:
            destroy->spawn(b, b[R][C], 6);
            AnySpawn = true;
            break;
        case 7:
            destroy->spawn(b, b[R][C], 7);
            AnySpawn = true;
            break;
        case 8:
            destroy->spawn(b, b[R][C], 8);
            AnySpawn = true;
            break;
        case 9:
            destroy->spawn(b, b[R][C], 9);
            AnySpawn = true;
            break;
        case 10:
            destroy->spawn(b, b[R][C], 10);
            AnySpawn = true;
            break;
        case 11:
            destroy->spawn(b, b[R][C], 11);
            AnySpawn = true;
            break;
        case 12:
            destroy->spawn(b, b[R][C], 12);
            AnySpawn = true;
            break;
        case 13:
            destroy->spawn(b, b[R][C], 13);
            AnySpawn = true;
            break;
        case 14:
            destroy->spawn(b, b[R][C], 14);
            AnySpawn = true;
            break;
        case 15:
            destroy->spawn(b, b[R][C], 15);
            AnySpawn = true;
            break;
        case 16:
            destroy->spawn(b, b[R][C], 16);
            AnySpawn = true;
            break;
        }// end switch
    }// end if
    delete destroy;
    return AnySpawn;
}

bool MainWindow::JudgeHori(int R, int C)
{
    int return_value;
    bool AnySpawn = false;
    destroy = new Horizontal;
    return_value = destroy->condition(b,b[R][C]);
    if(return_value){
        switch(return_value){
        case 1:
            destroy->spawn(b, b[R][C], 1);
            AnySpawn = true;
            break;
        case 2:
            destroy->spawn(b, b[R][C], 2);
            AnySpawn = true;
            break;
        case 3:
            destroy->spawn(b, b[R][C], 3);
            AnySpawn = true;
            break;
        case 4:
            destroy->spawn(b, b[R][C], 4);
            AnySpawn = true;
            break;
        }// end switch
    }// end if
    delete destroy;
    return AnySpawn;
}

bool MainWindow::JudgeVerti(int R, int C)
{
    int return_value;
    bool AnySpawn = false;
    destroy = new Vertical;
    return_value = destroy->condition(b,b[R][C]);
    if(return_value){
        switch(return_value){
        case 1:
            destroy->spawn(b, b[R][C], 1);
            AnySpawn = true;
            break;
        case 2:
            destroy->spawn(b, b[R][C], 2);
            AnySpawn = true;
            break;
        case 3:
            destroy->spawn(b, b[R][C], 3);
            AnySpawn = true;
            break;
        case 4:
            destroy->spawn(b, b[R][C], 4);
            AnySpawn = true;
            break;
        }// end switch
    }// end if
    delete destroy;
    return AnySpawn;
}

void MainWindow::RenewPicture()
{
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            b[i][j] -> setButtonPicture();
        }// end for
    }// end for
}

void MainWindow::Done()
{
    while(1){
        FillinZero();
        bool eDone = EPossib();
        if(eDone == 0){
            break;
        }// end if
    }// end while

    SpawnZero();
    if(score_int == 50){
        t->stop();
        game = new GameOver(this, score_int, score_int);
        //this->close();
        game->show();
        gameOpened = true;
    }// end if
}

void MainWindow::FillinZero()
{
    for(int j = 0; j <= 9; j++){
        for(int i = 9; i > 0; i--){
            if(b[i][j]->number == 0){
                *b[i][j] - b[i-1][j];
            }// end for
        }// end for
    }// end for
}

bool MainWindow::EPossib()
{
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(JudgeStar(i, j)){
                return 1;
            }// end if
        }// end for
    }// end for

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(JudgeNine(i, j)){
                return 1;
            }// end if
        }// end for
    }// end for

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(JudgeHori(i, j)){
                return 1;
            }// end if
        }// end for
    }// end for

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(JudgeVerti(i, j)){
                return 1;
            }// end if
        }// end for
    }// end for

    return 0;

}

void MainWindow::SpawnZero()
{
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(b[i][j]->number == 0){
                b[i][j]->number = rand()%4+1;
                // row
                if(j >= 2 && b[i][j]->number == b[i][j-1]->number && b[i][j]->number == b[i][j-2]->number){
                    j--;
                }// end if

                // column
                if(i >= 2 && b[i][j]->number == b[i-1][j]->number && b[i][j]->number == b[i-2][j]->number){
                    j--;
                }// end if
            }// end if
        }// end for
    }// end for

    RenewPicture();
}

void MainWindow::SetScore()
{
    score_str = QString::number(score_int,10);
    ui->score->setText(QString(score_str));
    star_str = QString::number(star_int,10);
    ui->star->setText(QString(star_str));
}

void MainWindow::SetTime()
{
    time_str = QString::number(time,10);
    ui->time->setText(QString(time_str));
}

void MainWindow::Time()
{
    if(time == 0){
        t->stop();
        game = new GameOver(this, score_int, score_int);
        //this->close();
        game->show();
        gameOpened = true;
    }else{
        --time;
        SetTime();
    }// end else
}

void MainWindow::button_clicked(int R, int C)
{
    if(!isClicked){
        // first click
        setClickedPicture(b[R][C]);
        record_R = R;
        record_C = C;
        isClicked = true;
    }else{
        // second click
        if(record_R == R && record_C == C-1){
            *b[record_R][record_C] - b[R][C];// '-' operator overloading
            if(!Judge(record_R, record_C, R, C)){// if no items in a row after changing
                //change back
                *b[R][C] - b[record_R][record_C];
            }else{
                Done();
                score_int+=10;
                SetScore();
            }// end else
        }else if(record_R == R && record_C == C+1){
            *b[R][C] - b[record_R][record_C];
            if(!Judge(record_R, record_C, R, C)){
                *b[record_R][record_C] - b[R][C];
            }else{
                Done();
                score_int+=10;
                SetScore();
            }// end else
        }else if(record_R == R-1 && record_C == C){
            *b[record_R][record_C] | b[R][C];// '|' operator overloading
            if(!Judge(record_R, record_C, R, C)){
                *b[R][C] | b[record_R][record_C];
            }else{
                Done();
                score_int+=10;
                SetScore();
            }// end else
        }else if(record_R == R+1 && record_C == C){
            *b[R][C] | b[record_R][record_C];
            if(!Judge(record_R, record_C, R, C)){
                *b[record_R][record_C] | b[R][C];
            }else{
                Done();
                score_int+=10;
                SetScore();
            }// end else
        }else{
            setClickedPicture(b[record_R][record_C]);
        }// end else

        isClicked = false;
    }// end else
}

void MainWindow::quit(int star, int score)
{
    emit quit(star, score);
}

void MainWindow::on_restart_clicked()
{
    if(gameOpened == true){
        game->close();
    }// end if
    GameStart();
}
