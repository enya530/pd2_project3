#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QWidget>
#include <QString>

namespace Ui {
class GameOver;
}

class GameOver : public QWidget
{
    Q_OBJECT

public:
    explicit GameOver(QWidget *parent, int score, int star);
    ~GameOver();

private:
    Ui::GameOver *ui;
    QString score_str;
    QString star_str;

};

#endif // GAMEOVER_H
