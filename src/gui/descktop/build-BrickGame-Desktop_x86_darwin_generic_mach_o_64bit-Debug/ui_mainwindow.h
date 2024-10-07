/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Tetris_Button;
    QPushButton *Snake_Button;
    QPushButton *Exit_Button;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(336, 617);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Tetris_Button = new QPushButton(centralwidget);
        Tetris_Button->setObjectName("Tetris_Button");
        Tetris_Button->setGeometry(QRect(110, 240, 100, 32));
        Snake_Button = new QPushButton(centralwidget);
        Snake_Button->setObjectName("Snake_Button");
        Snake_Button->setGeometry(QRect(110, 290, 100, 32));
        Exit_Button = new QPushButton(centralwidget);
        Exit_Button->setObjectName("Exit_Button");
        Exit_Button->setGeometry(QRect(110, 340, 100, 32));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 140, 131, 81));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 336, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Tetris_Button->setText(QCoreApplication::translate("MainWindow", "Tetris", nullptr));
        Snake_Button->setText(QCoreApplication::translate("MainWindow", "Snake", nullptr));
        Exit_Button->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:700; font-style:italic;\">Brick Game</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
