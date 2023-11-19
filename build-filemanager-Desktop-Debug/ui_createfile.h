/********************************************************************************
** Form generated from reading UI file 'createfile.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEFILE_H
#define UI_CREATEFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_createfile
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label;
    QTextEdit *textEdit;

    void setupUi(QWidget *createfile)
    {
        if (createfile->objectName().isEmpty())
            createfile->setObjectName(QStringLiteral("createfile"));
        createfile->resize(400, 300);
        lineEdit = new QLineEdit(createfile);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(120, 10, 251, 32));
        pushButton = new QPushButton(createfile);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 270, 118, 30));
        label = new QLabel(createfile);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 11, 91, 31));
        textEdit = new QTextEdit(createfile);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 50, 351, 211));

        retranslateUi(createfile);

        QMetaObject::connectSlotsByName(createfile);
    } // setupUi

    void retranslateUi(QWidget *createfile)
    {
        createfile->setWindowTitle(QApplication::translate("createfile", "Form", 0));
        pushButton->setText(QApplication::translate("createfile", "create", 0));
        label->setText(QApplication::translate("createfile", "filename", 0));
        textEdit->setPlaceholderText(QString());
    } // retranslateUi

};

namespace Ui {
    class createfile: public Ui_createfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEFILE_H
