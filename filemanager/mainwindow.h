#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QFile>
#include <QDirIterator>
#include <QList>
#include <QTableWidgetItem>
#include <QListWidgetItem>
#include <QDesktopServices>
#include <QUrl>
#include <QFileIconProvider>
#include <QException>
#include <QClipboard>
#include <QMimeData>
#include <QMessageBox>
#include <QFileSystemWatcher>
#include <QInputDialog>
#include <QPoint>
#include <QMouseEvent>
#include <QDrag>
#include <QDragEnterEvent>
#include <QDateTime>
#include <QProcess>
#include <QPainter>
#include <QPaintDevice>
#include <QDebug>
#include <QMimeDatabase>
#include <QPropertyAnimation>


#include "copy.h"
#include "properties.h"


QString calculateSize(quint64 size);

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void goTo(QString dir);

private slots:
    void on_files_itemDoubleClicked(QTableWidgetItem *item);

    void on_actionUp_triggered();

    void blockDevicesChanged();

    void on_files_customContextMenuRequested(const QPoint &pos);

    void on_actionOpen_triggered();

    void on_actionCopy_triggered();

    void on_actionDelete_triggered();

    void reloadList();

    void on_actionPaste_triggered();

    void on_actionRename_triggered();

    void on_files_itemChanged(QTableWidgetItem *item);

    void on_actionNew_Folder_triggered();

    void on_actionAdd_To_Bar_triggered();

    void on_addr_returnPressed();

    void on_fav_itemClicked(QListWidgetItem *item);

    void on_fav_customContextMenuRequested(const QPoint &pos);

    void on_actionProperties_triggered();

    void on_actionMove_to_Trash_triggered();

    void on_actionNew_Window_triggered();

    void on_actionClose_Window_triggered();

    void on_actionExit_triggered();

    void restoreFilesFromTrash(QStringList filenames);

    void on_actionRestore_triggered();

    void on_actionEmpty_Trash_triggered();

    void on_actionShow_Hidden_Files_toggled(bool arg1);

    void on_actionCreateFile_triggered();

    void on_lineEdit_editingFinished();

private:
    Ui::MainWindow *ui;

    QDir currentDir;
    QStringList favDirs;
    QFileSystemWatcher *watcher;
    QString oldFileName;
    QPoint startPos;
    QMimeDatabase *mimes;
    QStringList filesMovedToTrash;

    bool searchMode;
    bool eventFilter(QObject *obj, QEvent *event);
};


#endif // MAINWINDOW_H
