#ifndef BLANK_H
#define BLANK_H

#include <QObject>
#include <QPushButton>

class Blank:public QObject
{
    Q_OBJECT
public:
    explicit Blank(QWidget *parent, int R, int C); // parent = mainwindow
    ~Blank();

    QPushButton *button;
    const int row;
    const int column;
    int number;

    void setButtonPicture();
    void setRandomNumber();
    void operator -(Blank *a);
    void operator |(Blank *a);
public slots:
    void click();
signals:
    /**note:
     *    signal slots sent out signal only
     *    no definition
     */
    void Click(int R, int C);
};

#endif // BLANK_H
