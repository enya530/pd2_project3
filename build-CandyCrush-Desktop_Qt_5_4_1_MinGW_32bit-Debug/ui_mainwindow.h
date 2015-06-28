/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *restart;
    QLabel *score;
    QLabel *Score_title;
    QLabel *Star_title_2;
    QLabel *star;
    QLabel *label;
    QLabel *Time_title;
    QLabel *time;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(674, 610);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        restart = new QPushButton(centralWidget);
        restart->setObjectName(QStringLiteral("restart"));
        restart->setGeometry(QRect(520, 40, 131, 41));
        QFont font;
        font.setFamily(QStringLiteral("Broadway"));
        font.setPointSize(14);
        restart->setFont(font);
        restart->setFocusPolicy(Qt::NoFocus);
        score = new QLabel(centralWidget);
        score->setObjectName(QStringLiteral("score"));
        score->setGeometry(QRect(550, 130, 70, 18));
        QFont font1;
        font1.setFamily(QStringLiteral("Bradley Hand ITC"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        score->setFont(font1);
        score->setLayoutDirection(Qt::LeftToRight);
        score->setAlignment(Qt::AlignCenter);
        Score_title = new QLabel(centralWidget);
        Score_title->setObjectName(QStringLiteral("Score_title"));
        Score_title->setGeometry(QRect(549, 100, 81, 21));
        QFont font2;
        font2.setFamily(QStringLiteral("Bradley Hand ITC"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        Score_title->setFont(font2);
        Star_title_2 = new QLabel(centralWidget);
        Star_title_2->setObjectName(QStringLiteral("Star_title_2"));
        Star_title_2->setGeometry(QRect(550, 210, 81, 21));
        Star_title_2->setFont(font2);
        star = new QLabel(centralWidget);
        star->setObjectName(QStringLiteral("star"));
        star->setGeometry(QRect(550, 240, 70, 18));
        star->setFont(font1);
        star->setLayoutDirection(Qt::LeftToRight);
        star->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 500, 451, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Algerian"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);
        label->setAlignment(Qt::AlignCenter);
        Time_title = new QLabel(centralWidget);
        Time_title->setObjectName(QStringLiteral("Time_title"));
        Time_title->setGeometry(QRect(550, 300, 81, 21));
        Time_title->setFont(font2);
        time = new QLabel(centralWidget);
        time->setObjectName(QStringLiteral("time"));
        time->setGeometry(QRect(550, 330, 70, 18));
        time->setFont(font1);
        time->setLayoutDirection(Qt::LeftToRight);
        time->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 674, 29));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        restart->setText(QApplication::translate("MainWindow", "restart", 0));
        score->setText(QApplication::translate("MainWindow", "score", 0));
        Score_title->setText(QApplication::translate("MainWindow", "Score", 0));
        Star_title_2->setText(QApplication::translate("MainWindow", "Star", 0));
        star->setText(QApplication::translate("MainWindow", "star", 0));
        label->setText(QApplication::translate("MainWindow", "goal : score = 50 in 60 secs", 0));
        Time_title->setText(QApplication::translate("MainWindow", "Time", 0));
        time->setText(QApplication::translate("MainWindow", "time", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
