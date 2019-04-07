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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMainWindowClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;

    void setupUi(QMainWindow *CMainWindowClass)
    {
        if (CMainWindowClass->objectName().isEmpty())
            CMainWindowClass->setObjectName(QStringLiteral("CMainWindowClass"));
        CMainWindowClass->resize(869, 455);
        centralWidget = new QWidget(CMainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(330, 200, 75, 23));
        CMainWindowClass->setCentralWidget(centralWidget);

        retranslateUi(CMainWindowClass);

        QMetaObject::connectSlotsByName(CMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *CMainWindowClass)
    {
        CMainWindowClass->setWindowTitle(QApplication::translate("CMainWindowClass", "CMainWindow", 0));
        pushButton->setText(QApplication::translate("CMainWindowClass", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class CMainWindowClass: public Ui_CMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMAINWINDOW_H
