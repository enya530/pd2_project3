/********************************************************************************
** Form generated from reading UI file 'gameover.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVER_H
#define UI_GAMEOVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameOver
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *score;
    QLabel *label_2;
    QLabel *star;

    void setupUi(QWidget *GameOver)
    {
        if (GameOver->objectName().isEmpty())
            GameOver->setObjectName(QStringLiteral("GameOver"));
        GameOver->resize(400, 300);
        layoutWidget = new QWidget(GameOver);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 80, 211, 131));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setFrameShape(QFrame::NoFrame);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        score = new QLabel(layoutWidget);
        score->setObjectName(QStringLiteral("score"));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial Rounded MT Bold"));
        font1.setPointSize(11);
        score->setFont(font1);

        gridLayout->addWidget(score, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        star = new QLabel(layoutWidget);
        star->setObjectName(QStringLiteral("star"));
        star->setFont(font1);

        gridLayout->addWidget(star, 1, 1, 1, 1);


        retranslateUi(GameOver);

        QMetaObject::connectSlotsByName(GameOver);
    } // setupUi

    void retranslateUi(QWidget *GameOver)
    {
        GameOver->setWindowTitle(QApplication::translate("GameOver", "Form", 0));
        label->setText(QApplication::translate("GameOver", "Score:", 0));
        score->setText(QApplication::translate("GameOver", "score", 0));
        label_2->setText(QApplication::translate("GameOver", "Star:", 0));
        star->setText(QApplication::translate("GameOver", "star", 0));
    } // retranslateUi

};

namespace Ui {
    class GameOver: public Ui_GameOver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
