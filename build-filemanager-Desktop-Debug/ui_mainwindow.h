/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionUp;
    QAction *actionAbout;
    QAction *actionOpen;
    QAction *actionCopy;
    QAction *actionDelete;
    QAction *actionPaste;
    QAction *actionRename;
    QAction *actionNew_Folder;
    QAction *actionProperties;
    QAction *actionAdd_To_Bar;
    QAction *actionNew_Window;
    QAction *actionMove_to_Trash;
    QAction *actionClose_Window;
    QAction *actionExit;
    QAction *actionRestore;
    QAction *actionEmpty_Trash;
    QAction *actionShow_Hidden_Files;
    QAction *actionCreateFile;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *addr;
    QListWidget *fav;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QTableWidget *files;
    QFrame *movedToTrashFrame;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(653, 455);
        actionUp = new QAction(MainWindow);
        actionUp->setObjectName(QStringLiteral("actionUp"));
        QIcon icon;
        QString iconThemeName = QStringLiteral("go-up");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionUp->setIcon(icon);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon1;
        iconThemeName = QStringLiteral("help-about");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionAbout->setIcon(icon1);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon2;
        iconThemeName = QStringLiteral("document-open");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionOpen->setIcon(icon2);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        QIcon icon3;
        iconThemeName = QStringLiteral("edit-copy");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionCopy->setIcon(icon3);
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        QIcon icon4;
        iconThemeName = QStringLiteral("edit-delete");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionDelete->setIcon(icon4);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        QIcon icon5;
        iconThemeName = QStringLiteral("edit-paste");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon5 = QIcon::fromTheme(iconThemeName);
        } else {
            icon5.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionPaste->setIcon(icon5);
        actionRename = new QAction(MainWindow);
        actionRename->setObjectName(QStringLiteral("actionRename"));
        QIcon icon6;
        iconThemeName = QStringLiteral("edit-rename");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon6 = QIcon::fromTheme(iconThemeName);
        } else {
            icon6.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionRename->setIcon(icon6);
        actionNew_Folder = new QAction(MainWindow);
        actionNew_Folder->setObjectName(QStringLiteral("actionNew_Folder"));
        QIcon icon7;
        iconThemeName = QStringLiteral("folder-new");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon7 = QIcon::fromTheme(iconThemeName);
        } else {
            icon7.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionNew_Folder->setIcon(icon7);
        actionProperties = new QAction(MainWindow);
        actionProperties->setObjectName(QStringLiteral("actionProperties"));
        QIcon icon8;
        iconThemeName = QStringLiteral("dialog-object-properties");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon8 = QIcon::fromTheme(iconThemeName);
        } else {
            icon8.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionProperties->setIcon(icon8);
        actionAdd_To_Bar = new QAction(MainWindow);
        actionAdd_To_Bar->setObjectName(QStringLiteral("actionAdd_To_Bar"));
        QIcon icon9;
        iconThemeName = QStringLiteral("bookmark-add-folder");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon9 = QIcon::fromTheme(iconThemeName);
        } else {
            icon9.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionAdd_To_Bar->setIcon(icon9);
        actionNew_Window = new QAction(MainWindow);
        actionNew_Window->setObjectName(QStringLiteral("actionNew_Window"));
        QIcon icon10;
        iconThemeName = QStringLiteral("window-new");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon10 = QIcon::fromTheme(iconThemeName);
        } else {
            icon10.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionNew_Window->setIcon(icon10);
        actionMove_to_Trash = new QAction(MainWindow);
        actionMove_to_Trash->setObjectName(QStringLiteral("actionMove_to_Trash"));
        QIcon icon11;
        iconThemeName = QStringLiteral("user-trash");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon11 = QIcon::fromTheme(iconThemeName);
        } else {
            icon11.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionMove_to_Trash->setIcon(icon11);
        actionClose_Window = new QAction(MainWindow);
        actionClose_Window->setObjectName(QStringLiteral("actionClose_Window"));
        QIcon icon12;
        iconThemeName = QStringLiteral("window-close");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon12 = QIcon::fromTheme(iconThemeName);
        } else {
            icon12.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionClose_Window->setIcon(icon12);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon13;
        iconThemeName = QStringLiteral("application-exit");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon13 = QIcon::fromTheme(iconThemeName);
        } else {
            icon13.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionExit->setIcon(icon13);
        actionRestore = new QAction(MainWindow);
        actionRestore->setObjectName(QStringLiteral("actionRestore"));
        QIcon icon14;
        iconThemeName = QStringLiteral("edit-undo");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon14 = QIcon::fromTheme(iconThemeName);
        } else {
            icon14.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionRestore->setIcon(icon14);
        actionEmpty_Trash = new QAction(MainWindow);
        actionEmpty_Trash->setObjectName(QStringLiteral("actionEmpty_Trash"));
        actionEmpty_Trash->setIcon(icon4);
        actionShow_Hidden_Files = new QAction(MainWindow);
        actionShow_Hidden_Files->setObjectName(QStringLiteral("actionShow_Hidden_Files"));
        actionShow_Hidden_Files->setCheckable(true);
        actionCreateFile = new QAction(MainWindow);
        actionCreateFile->setObjectName(QStringLiteral("actionCreateFile"));
        QIcon icon15;
        iconThemeName = QStringLiteral("document-new");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon15 = QIcon::fromTheme(iconThemeName);
        } else {
            icon15.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionCreateFile->setIcon(icon15);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        addr = new QLineEdit(centralWidget);
        addr->setObjectName(QStringLiteral("addr"));

        verticalLayout_2->addWidget(addr);

        fav = new QListWidget(centralWidget);
        fav->setObjectName(QStringLiteral("fav"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fav->sizePolicy().hasHeightForWidth());
        fav->setSizePolicy(sizePolicy);
        fav->setMaximumSize(QSize(16777215, 16777215));
        fav->setContextMenuPolicy(Qt::CustomContextMenu);
        fav->setFrameShape(QFrame::StyledPanel);
        fav->setFrameShadow(QFrame::Raised);
        fav->setLineWidth(1);

        verticalLayout_2->addWidget(fav);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        files = new QTableWidget(centralWidget);
        files->setObjectName(QStringLiteral("files"));
        files->setMaximumSize(QSize(16777215, 16777215));
        files->setContextMenuPolicy(Qt::CustomContextMenu);
        files->setAutoFillBackground(false);
        files->setFrameShape(QFrame::StyledPanel);
        files->setEditTriggers(QAbstractItemView::NoEditTriggers);
        files->setDragDropMode(QAbstractItemView::NoDragDrop);
        files->setAlternatingRowColors(false);
        files->horizontalHeader()->setHighlightSections(false);
        files->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(files);

        movedToTrashFrame = new QFrame(centralWidget);
        movedToTrashFrame->setObjectName(QStringLiteral("movedToTrashFrame"));
        movedToTrashFrame->setFrameShape(QFrame::NoFrame);
        movedToTrashFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(movedToTrashFrame);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));

        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout->addWidget(movedToTrashFrame);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 653, 38));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setMovable(false);
        mainToolBar->setAllowedAreas(Qt::TopToolBarArea);
        mainToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        mainToolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuFile->addAction(actionNew_Window);
        menuFile->addSeparator();
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionClose_Window);
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionOpen);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addSeparator();
        menuEdit->addAction(actionRename);
        menuEdit->addAction(actionMove_to_Trash);
        menuEdit->addAction(actionDelete);
        menuView->addAction(actionShow_Hidden_Files);
        mainToolBar->addAction(actionAdd_To_Bar);
        mainToolBar->addAction(actionUp);
        mainToolBar->addAction(actionNew_Folder);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "theFile", 0));
        actionUp->setText(QApplication::translate("MainWindow", "Go Up", 0));
#ifndef QT_NO_TOOLTIP
        actionUp->setToolTip(QApplication::translate("MainWindow", "Go Up", 0));
#endif // QT_NO_TOOLTIP
        actionUp->setShortcut(QApplication::translate("MainWindow", "Backspace", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "&About", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "&Open", 0));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Return", 0));
        actionCopy->setText(QApplication::translate("MainWindow", "&Copy", 0));
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0));
        actionDelete->setText(QApplication::translate("MainWindow", "Permanantly &Delete", 0));
        actionDelete->setShortcut(QApplication::translate("MainWindow", "Shift+Del", 0));
        actionPaste->setText(QApplication::translate("MainWindow", "&Paste", 0));
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0));
        actionRename->setText(QApplication::translate("MainWindow", "&Rename", 0));
        actionRename->setShortcut(QApplication::translate("MainWindow", "F2", 0));
        actionNew_Folder->setText(QApplication::translate("MainWindow", "New Folder", 0));
        actionProperties->setText(QApplication::translate("MainWindow", "Properties", 0));
        actionAdd_To_Bar->setText(QApplication::translate("MainWindow", "Add To Bar", 0));
        actionNew_Window->setText(QApplication::translate("MainWindow", "&New Window", 0));
        actionNew_Window->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionMove_to_Trash->setText(QApplication::translate("MainWindow", "&Move to Trash", 0));
        actionMove_to_Trash->setShortcut(QApplication::translate("MainWindow", "Del", 0));
        actionClose_Window->setText(QApplication::translate("MainWindow", "&Close Window", 0));
        actionClose_Window->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", 0));
        actionExit->setText(QApplication::translate("MainWindow", "&Exit", 0));
        actionRestore->setText(QApplication::translate("MainWindow", "Restore", 0));
        actionEmpty_Trash->setText(QApplication::translate("MainWindow", "Empty Trash", 0));
        actionShow_Hidden_Files->setText(QApplication::translate("MainWindow", "&Show Hidden Files", 0));
        actionShow_Hidden_Files->setShortcut(QApplication::translate("MainWindow", "Ctrl+H", 0));
        actionCreateFile->setText(QApplication::translate("MainWindow", "createFile", 0));
#ifndef QT_NO_TOOLTIP
        actionCreateFile->setToolTip(QApplication::translate("MainWindow", "Create File", 0));
#endif // QT_NO_TOOLTIP
        menuFile->setTitle(QApplication::translate("MainWindow", "Fi&le", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "&View", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
