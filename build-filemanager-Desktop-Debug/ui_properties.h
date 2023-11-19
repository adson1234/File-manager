/********************************************************************************
** Form generated from reading UI file 'properties.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROPERTIES_H
#define UI_PROPERTIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Properties
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *filename;
    QFormLayout *formLayout;
    QLabel *label_4;
    QLabel *size;
    QLabel *label_5;
    QLabel *created;
    QLabel *label_6;
    QLabel *modified;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QCheckBox *checkBox;
    QFrame *line;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *Properties)
    {
        if (Properties->objectName().isEmpty())
            Properties->setObjectName(QStringLiteral("Properties"));
        Properties->resize(309, 387);
        verticalLayout = new QVBoxLayout(Properties);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        filename = new QLabel(Properties);
        filename->setObjectName(QStringLiteral("filename"));
        QFont font;
        font.setPointSize(20);
        filename->setFont(font);

        verticalLayout->addWidget(filename);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetMaximumSize);
        label_4 = new QLabel(Properties);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setWordWrap(false);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        size = new QLabel(Properties);
        size->setObjectName(QStringLiteral("size"));

        formLayout->setWidget(0, QFormLayout::FieldRole, size);

        label_5 = new QLabel(Properties);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        created = new QLabel(Properties);
        created->setObjectName(QStringLiteral("created"));

        formLayout->setWidget(1, QFormLayout::FieldRole, created);

        label_6 = new QLabel(Properties);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_6);

        modified = new QLabel(Properties);
        modified->setObjectName(QStringLiteral("modified"));

        formLayout->setWidget(2, QFormLayout::FieldRole, modified);

        label = new QLabel(Properties);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label);

        comboBox = new QComboBox(Properties);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBox);

        label_2 = new QLabel(Properties);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_2);

        comboBox_2 = new QComboBox(Properties);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        formLayout->setWidget(5, QFormLayout::FieldRole, comboBox_2);

        label_3 = new QLabel(Properties);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_3);

        comboBox_3 = new QComboBox(Properties);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        formLayout->setWidget(6, QFormLayout::FieldRole, comboBox_3);

        checkBox = new QCheckBox(Properties);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        formLayout->setWidget(7, QFormLayout::FieldRole, checkBox);

        line = new QFrame(Properties);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(3, QFormLayout::SpanningRole, line);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(8, QFormLayout::SpanningRole, verticalSpacer);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(Properties);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QIcon icon;
        QString iconThemeName = QStringLiteral("dialog-ok");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        pushButton->setIcon(icon);

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Properties);

        QMetaObject::connectSlotsByName(Properties);
    } // setupUi

    void retranslateUi(QDialog *Properties)
    {
        Properties->setWindowTitle(QApplication::translate("Properties", "Properties", 0));
        filename->setText(QApplication::translate("Properties", "File Name", 0));
        label_4->setText(QApplication::translate("Properties", "Size:", 0));
        size->setText(QString());
        label_5->setText(QApplication::translate("Properties", "Created:", 0));
        created->setText(QString());
        label_6->setText(QApplication::translate("Properties", "Modified:", 0));
        modified->setText(QString());
        label->setText(QApplication::translate("Properties", "The owner", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Properties", "isn't allowed to do anything", 0)
         << QApplication::translate("Properties", "is allowed to Read", 0)
         << QApplication::translate("Properties", "is allowed to Read and Write", 0)
        );
        comboBox->setCurrentText(QApplication::translate("Properties", "isn't allowed to do anything", 0));
        label_2->setText(QApplication::translate("Properties", "The group", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Properties", "isn't allowed to do anything", 0)
         << QApplication::translate("Properties", "is allowed to Read", 0)
         << QApplication::translate("Properties", "is allowed to Read and Write", 0)
        );
        comboBox_2->setCurrentText(QApplication::translate("Properties", "isn't allowed to do anything", 0));
        label_3->setText(QApplication::translate("Properties", "Everyone else ", 0));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("Properties", "isn't allowed to do anything", 0)
         << QApplication::translate("Properties", "is allowed to Read", 0)
         << QApplication::translate("Properties", "is allowed to Read and Write", 0)
        );
        comboBox_3->setCurrentText(QApplication::translate("Properties", "isn't allowed to do anything", 0));
        checkBox->setText(QApplication::translate("Properties", "Executable", 0));
        pushButton->setText(QApplication::translate("Properties", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class Properties: public Ui_Properties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPERTIES_H
