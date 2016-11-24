/********************************************************************************
** Form generated from reading UI file 'mainpage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGE_H
#define UI_MAINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainpage
{
public:
    QDateEdit *dateEdit;
    QScrollBar *verticalScrollBar;

    void setupUi(QWidget *mainpage)
    {
        if (mainpage->objectName().isEmpty())
            mainpage->setObjectName(QStringLiteral("mainpage"));
        mainpage->resize(688, 445);
        dateEdit = new QDateEdit(mainpage);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(570, 410, 110, 22));
        verticalScrollBar = new QScrollBar(mainpage);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(650, 80, 16, 311));
        verticalScrollBar->setOrientation(Qt::Vertical);

        retranslateUi(mainpage);

        QMetaObject::connectSlotsByName(mainpage);
    } // setupUi

    void retranslateUi(QWidget *mainpage)
    {
        mainpage->setWindowTitle(QApplication::translate("mainpage", "mainpage", 0));
    } // retranslateUi

};

namespace Ui {
    class mainpage: public Ui_mainpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H
