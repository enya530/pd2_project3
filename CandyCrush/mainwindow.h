#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "blank.h"
#include "destroy.h"
#include "star.h"
#include <QString>
#include "gameover.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0); // parent = no one
    ~MainWindow();

    void GameStart();
    void setClickedPicture(Blank *a);
    bool Judge(int row1, int column1, int row2, int column2);
    bool JudgeStar(int R, int C);
    bool JudgeNine(int R, int C);
    bool JudgeHori(int R, int C);
    bool JudgeVerti(int R, int C);
    void RenewPicture();
    void Done();
    void FillinZero();
    bool EPossib();
    void SpawnZero();
    void SetScore();
    void SetTime();

public slots:
    void button_clicked(int R, int C);
    void quit(int star, int score);
    void Time();

private slots:
    void on_restart_clicked();

private:
    Ui::MainWindow *ui;
    Blank *b[10][10];
    int record_R;
    int record_C;
    bool isClicked;
    Destroy *destroy;
    int score_int;
    QString score_str;
    int star_int;
    QString star_str;
    QString time_str;
    GameOver *game;
    QTimer *t;
    int time;
    bool gameOpened;
};

#endif // MAINWINDOW_H
