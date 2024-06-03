/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *bAddAppToList;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lConnectionState;
    QPushButton *bStart;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *bConnect;
    QSpacerItem *verticalSpacer_2;
    QPushButton *bUpdBox;
    QPushButton *bClear;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QTableView *tList;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        bAddAppToList = new QPushButton(centralwidget);
        bAddAppToList->setObjectName(QString::fromUtf8("bAddAppToList"));

        gridLayout->addWidget(bAddAppToList, 5, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 6, 2, 1, 1);

        lConnectionState = new QLabel(centralwidget);
        lConnectionState->setObjectName(QString::fromUtf8("lConnectionState"));
        lConnectionState->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));

        gridLayout->addWidget(lConnectionState, 0, 1, 1, 1);

        bStart = new QPushButton(centralwidget);
        bStart->setObjectName(QString::fromUtf8("bStart"));

        gridLayout->addWidget(bStart, 7, 2, 1, 1);

        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 3, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        bConnect = new QPushButton(centralwidget);
        bConnect->setObjectName(QString::fromUtf8("bConnect"));

        gridLayout->addWidget(bConnect, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 6, 1, 1, 1);

        bUpdBox = new QPushButton(centralwidget);
        bUpdBox->setObjectName(QString::fromUtf8("bUpdBox"));

        gridLayout->addWidget(bUpdBox, 3, 1, 1, 1);

        bClear = new QPushButton(centralwidget);
        bClear->setObjectName(QString::fromUtf8("bClear"));

        gridLayout->addWidget(bClear, 7, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));

        gridLayout_2->addLayout(gridLayout_4, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tList = new QTableView(centralwidget);
        tList->setObjectName(QString::fromUtf8("tList"));

        gridLayout_3->addWidget(tList, 1, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_3, 0, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        bAddAppToList->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\320\270 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\321\203 \320\262 \321\201\320\277\320\270\321\201\320\276\320\272", nullptr));
        lConnectionState->setText(QString());
        bStart->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\320\270 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\270", nullptr));
        bConnect->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\272\320\276\320\275\320\265\320\272\321\202\320\270\321\202\320\270\321\201\321\214", nullptr));
        bUpdBox->setText(QApplication::translate("MainWindow", "\320\236\320\275\320\276\320\262\320\270\321\202\320\270 \321\201\320\277\320\270\321\201\320\276\320\272", nullptr));
        bClear->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\320\270 \321\201\320\277\320\270\321\201\320\276\320\272", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\277\321\200\320\276\320\263\321\200\320\260\320\274 \320\264\320\273\321\217 \320\267\320\260\320\277\321\203\321\201\320\272\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
