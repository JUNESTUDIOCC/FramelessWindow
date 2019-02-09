/********************************************************************************
** Form generated from reading UI file 'CMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMAINWINDOW_H
#define UI_CMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMainWindowClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CMainWindowClass)
    {
        if (CMainWindowClass->objectName().isEmpty())
            CMainWindowClass->setObjectName(QStringLiteral("CMainWindowClass"));
        CMainWindowClass->resize(600, 400);
        menuBar = new QMenuBar(CMainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        CMainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CMainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CMainWindowClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(CMainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        CMainWindowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CMainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CMainWindowClass->setStatusBar(statusBar);

        retranslateUi(CMainWindowClass);

        QMetaObject::connectSlotsByName(CMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *CMainWindowClass)
    {
        CMainWindowClass->setWindowTitle(QApplication::translate("CMainWindowClass", "CMainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class CMainWindowClass: public Ui_CMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMAINWINDOW_H
