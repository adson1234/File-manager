#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createfile.h"

QString calculateSize(quint64 size) {
    QString ret;
    if (size > 1073741824) {
        ret = QString::number(((float) size / 1024 / 1024 / 1024), 'f', 2).append(" GiB");
    } else if (size > 1048576) {
        ret = QString::number(((float) size / 1024 / 1024), 'f', 2).append(" MiB");
    } else if (size > 1024) {
        ret = QString::number(((float) size / 1024), 'f', 2).append(" KiB");
    } else {
        ret = QString::number((float) size, 'f', 2).append(" B");
    }

    return ret;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->mainToolBar->addWidget(ui->addr);
    ui->movedToTrashFrame->setVisible(false);

    watcher = new QFileSystemWatcher(this);
    connect(watcher, SIGNAL(directoryChanged(QString)), this, SLOT(reloadList()));

    mimes = new QMimeDatabase();

    searchMode = false;

    ui->files->setColumnCount(4);
    ui->files->setHorizontalHeaderLabels(QStringList() << "Name" << "Type" << "Size" << "Date");
    ui->files->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->files->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->files->setMouseTracking(true);
    ui->files->viewport()->setMouseTracking(true);
    ui->files->installEventFilter(this);
    ui->files->viewport()->installEventFilter(this);

    QDir::home().mkdir(".myfilemanager");
    QFile fav(QDir::homePath() + "/.myfilemanager/fav");
    if (!fav.exists()) {
        fav.open(QFile::WriteOnly);
        fav.write(QString(QDir::homePath() + ",Home\n/,Root\n").toUtf8());
        fav.close();
    }

    blockDevicesChanged();

    currentDir = QDir::home();
    reloadList();

}

void MainWindow::blockDevicesChanged() {
    ui->fav->clear();
    favDirs.clear();

    //Add user's favourites
    QFile fav(QDir::homePath() + "/.myfilemanager/fav");
    fav.open(QFile::ReadOnly);
    QString favData(fav.readAll());
    fav.close();
    for (QString line : favData.split("\n")) {
        if (line == "") {
            continue;
        }
        QStringList dat = line.split(",");
        QListWidgetItem *item = new QListWidgetItem(dat.at(1));
        if (QDir::homePath() == dat.at(0)) {
            item->setIcon(QIcon::fromTheme("user-home"));
        } else if (dat.at(0) == QDir::separator()) {
            item->setIcon(QIcon::fromTheme("computer"));
        } else {
            item->setIcon(QIcon::fromTheme("folder"));
        }
        ui->fav->addItem(item);
        favDirs.append(dat.at(0));
    }

    //Add important directories
    QListWidgetItem *trash = new QListWidgetItem("Trash");
    trash->setIcon(QIcon::fromTheme("user-trash"));
    ui->fav->addItem(trash);
}


MainWindow::~MainWindow()
{
    delete ui;
}

static void findRecursion(const QString path, const QString pattern, QStringList &result)
{
    QDirIterator it(path,QStringList(pattern),QDir::Files,QDirIterator::Subdirectories);
    while(it.hasNext())
    {
        result.append(it.next().replace(it.path()+QDir::separator(),""));
        //qDebug() << it.next().replace(it.path()+QDir::separator(),"") << "\n";
    }
}

void MainWindow::reloadList() {
    if (ui->files->isEnabled()) {
        ui->files->setEnabled(false);
        if(watcher->directories().isEmpty()==false)
        {
            watcher->removePaths(watcher->directories());
        }
        watcher->addPath(currentDir.path());
        currentDir.refresh();

        ui->files->clearContents();
        if (!currentDir.exists())
        {
            ui->files->setRowCount(0);
        }
        else if (!currentDir.isReadable())
        {
            ui->files->setRowCount(0);
        }
        else
        {
            int i = 0;
            ui->files->setRowCount(0);

            QStringList dirs,files;
            if(this->searchMode)
            {
                dirs = QStringList();
                files = QStringList();
                QString filter = ui->lineEdit->text();
                if(!filter.contains("*"))
                {
                    filter.insert(0,"*");
                    filter.append("*");
                }
                findRecursion(currentDir.path(),filter,files);
            }
            else
            {
                dirs = currentDir.entryList(QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot);
                files = currentDir.entryList(QDir::Files | QDir::NoSymLinks | QDir::NoDotAndDotDot);
            }

            //Get Directories
            for (QString dir : dirs )
            {
                if (!QDir(currentDir.path() + QDir::separator() + dir).exists())
                {
                    continue;
                }

                ui->files->setRowCount(ui->files->rowCount() + 1);
                QTableWidgetItem *name = new QTableWidgetItem(dir);

                //Give special directories special icons
                if (currentDir.path() + QDir::separator() + dir == QDir::homePath()) { //Home Folder
                    name->setIcon(QIcon::fromTheme("user-home"));
                } else if (currentDir.path() + QDir::separator() + dir == QDir::homePath() + "/Documents") { //Documents Folder
                    name->setIcon(QIcon::fromTheme("folder-documents"));
                } else if (currentDir.path() + QDir::separator() + dir == QDir::homePath() + "/Downloads") { //Downloads Folder
                    name->setIcon(QIcon::fromTheme("folder-downloads"));
                } else if (currentDir.path() + QDir::separator() + dir == QDir::homePath() + "/Music") { //Music Folder
                    name->setIcon(QIcon::fromTheme("folder-music"));
                } else if (currentDir.path() + QDir::separator() + dir == QDir::homePath() + "/Pictures") { //Pictures Folder
                    name->setIcon(QIcon::fromTheme("folder-pictures"));
                } else if (currentDir.path() + QDir::separator() + dir == QDir::homePath() + "/Videos") { //Videos Folder
                    name->setIcon(QIcon::fromTheme("folder-videos"));
                } else {
                    name->setIcon(QIcon::fromTheme("folder"));
                }
                ui->files->setItem(i, 0, name);

                QTableWidgetItem *type = new QTableWidgetItem("Folder");
                ui->files->setItem(i, 1, type);

                // hidden file
                if (dir.startsWith(".")) {
                    QBrush disabledColor = ui->files->palette().brush(QPalette::Disabled, QPalette::Foreground);
                    name->setForeground(disabledColor);
                    type->setForeground(disabledColor);
                }
                i++;
                QApplication::processEvents();
            }

            //Get Files
            for (QString file : files)
            {
                if (!QFile(currentDir.path() + QDir::separator() + file).exists())
                {
                    continue;
                }

                ui->files->setRowCount(ui->files->rowCount() + 1);
                QFile f(currentDir.path() + QDir::separator() + file);
                QFileInfo info(f);
                QTableWidgetItem *name = new QTableWidgetItem(file);
                QMimeType mime = mimes->mimeTypeForFile(info);
                name->setIcon(QIcon::fromTheme(mime.iconName(), QIcon::fromTheme("application-octet-stream")));

                ui->files->setItem(i, 0, name);

                QTableWidgetItem *type = new QTableWidgetItem(info.completeSuffix() + " file");
                ui->files->setItem(i, 1, type);

                QTableWidgetItem *size = new QTableWidgetItem(calculateSize(info.size()));
                ui->files->setItem(i, 2, size);

                QTableWidgetItem *date = new QTableWidgetItem(info.lastModified().toString("dd/MM/yy hh:mm"));
                ui->files->setItem(i, 3, date);

                if (file.startsWith(".")) {
                    QBrush disabledColor = ui->files->palette().brush(QPalette::Disabled, QPalette::Foreground);
                    name->setForeground(disabledColor);
                    type->setForeground(disabledColor);
                    size->setForeground(disabledColor);
                    date->setForeground(disabledColor);
                }

                i++;

                QApplication::processEvents();
            }
        }

        if (currentDir.path() == QDir::homePath() + "/.local/share/Trash/files") { //This is the trash.
            ui->addr->setText("Trash");
            this->setWindowTitle("Trash - osProjectGroup8");
        } else { //This is not an interesting folder, show path in address bar
            ui->addr->setText(currentDir.path());
            this->setWindowTitle(currentDir.path() + " - osProjectGroup8");
        }
        blockDevicesChanged();
        ui->files->setEnabled(true);
    }
}

void MainWindow::on_files_itemDoubleClicked(QTableWidgetItem *item)
{
    if (currentDir.path() == QDir::homePath() + "/.local/share/Trash/files") { //File is in trash. Don't allow opening.
        QMessageBox::critical(this, "File in trash", "This file/folder is in the trash. Restore the file to open it.", QMessageBox::Ok, QMessageBox::Ok);
    } else {
        if (currentDir.cd(ui->files->item(item->row(), 0)->text())) {
            reloadList();
        } else {
            QFile file(currentDir.path() + QDir::separator() + ui->files->item(item->row(), 0)->text());

            if (file.permissions() & QFile::ExeUser) {
                if (!QProcess::startDetached("\"" + currentDir.path() + QDir::separator() + ui->files->item(item->row(), 0)->text() + "\"")) {
                    QProcess::startDetached("xdg-open", QStringList() << currentDir.path() + QDir::separator() + ui->files->item(item->row(), 0)->text());
                }
            } else {
                //QDesktopServices::openUrl(QUrl::fromLocalFile(currentDir.path() + QDir::separator() + item->text()));
                QProcess::startDetached("xdg-open", QStringList() << currentDir.path() + QDir::separator() + ui->files->item(item->row(), 0)->text());
            }
        }
    }
}

void MainWindow::on_actionUp_triggered()
{
    if (currentDir.path() == QDir::homePath() + "/.local/share/Trash/files")
    { //This is trash
        currentDir.cd(QDir::homePath());
        reloadList();
    } else { //Go up a folder
        currentDir.cdUp();
        reloadList();
    }
}

void MainWindow::on_files_customContextMenuRequested(const QPoint &pos)
{
    QMenu *cx = new QMenu(this);

    //Detect whether this is the Trash folder because menus are different
    if (currentDir.path() == QDir::homePath() + "/.local/share/Trash/files") { //This is the Trash folder
        if (ui->files->selectedItems().count() != 0) {
            cx->addSection("For all selected objects");
            cx->addAction(ui->actionRestore);
            cx->addAction(ui->actionDelete);
        }
        cx->addSection("For all items in Trash");
        cx->addAction(ui->actionEmpty_Trash);
    } else {
        if (ui->files->selectedItems().count() != 0) {
            cx->addSection("For \"" + ui->files->selectedItems().at(0)->text() + "\"");
            cx->addAction(ui->actionOpen);
            cx->addAction(ui->actionRename);
            cx->addAction(ui->actionProperties);
            if (ui->files->selectedItems().count() > 1) {
                cx->addSection("For all selected objects");
            }
            cx->addAction(ui->actionCopy);
            cx->addAction(ui->actionMove_to_Trash);
            cx->addAction(ui->actionDelete);
        }

        cx->addSection("For folder \"" + currentDir.dirName() + "\"");
        cx->addAction(ui->actionPaste);
        cx->addAction(ui->actionNew_Folder);
        cx->addAction(ui->actionCreateFile);
    }

    cx->exec(ui->files->mapToGlobal(pos));
}

void MainWindow::on_actionOpen_triggered()
{
    if (ui->addr->hasFocus()) {
        on_addr_returnPressed();
    } else if (ui->files->selectedItems().count() > 0) {
        on_files_itemDoubleClicked(ui->files->selectedItems().at(0));
    }
}

void MainWindow::on_actionCopy_triggered()
{
    QMimeData *d = new QMimeData();
    QList<QUrl> allFiles;

    for (QTableWidgetItem *item : ui->files->selectedItems()) {
        if (item->column() == 0) {
            allFiles.append(QUrl::fromLocalFile(currentDir.path() + QDir::separator() + item->text()));
        }
    }

    d->setUrls(allFiles);

    QApplication::clipboard()->setMimeData(d);
}

void MainWindow::on_actionDelete_triggered()
{
    if (QMessageBox::question(this, "Delete File", "You're about to permanantly delete files. These files can't be recovered.", QMessageBox::Ok | QMessageBox::Cancel) == QMessageBox::Ok) {
        for (QTableWidgetItem *item : ui->files->selectedItems()) {
            if (item->column() == 0) {
                if (!QFile(currentDir.path() + QDir::separator() + item->text()).remove()) {
                    //currentDir.rmdir(item->text());
                    QDir dirToRemove(currentDir);
                    dirToRemove.cd(item->text());
                    dirToRemove.removeRecursively();
                }

                if (currentDir.path() == QDir::homePath() + "/.local/share/Trash/files") { //This file is in trash, also remove metadata
                    QDir trash = QDir::home();
                    trash.cd(".local/share/Trash");
                    QFile info(trash.path() + "/info/" + item->text() + ".trashinfo");
                    info.remove();
                }
            }
        }
    }

    reloadList();
}

void MainWindow::on_actionPaste_triggered()
{
    if (QApplication::clipboard()->mimeData()->hasUrls()) {
        QStringList files;
        for (QUrl urlFile : QApplication::clipboard()->mimeData()->urls()) {
            files.append(urlFile.path());
        }
        MYCOPY mycopy(files, currentDir.path() + QDir::separator(),true);
        mycopy.runcopy();
    }
}

void MainWindow::on_actionRename_triggered()
{
    ui->files->editItem(ui->files->selectedItems().at(0));
    oldFileName = ui->files->selectedItems().at(0)->text();
}

void MainWindow::on_files_itemChanged(QTableWidgetItem *item)
{
    /*
     * use oldFileName to check is in rename action because
     * refresh file list will also trigger this event.
     */
    if (oldFileName != "")
    {
        //qDebug() << item->text();
        QString newName = currentDir.path() + QDir::separator() + item->text();
        if (QFile(newName).exists() || QDir(newName).exists())
        {
            item->setText(oldFileName);
            /*QMessageBox box;
            box.setText("same filename already exist");
            box.exec();*/
        }
        else
        {
            QFile file(currentDir.path() + QDir::separator() + oldFileName);
            file.rename(newName);
            oldFileName = "";
        }
    }
    //reloadList();
}

void MainWindow::on_actionNew_Folder_triggered()
{
    ui->files->setRowCount(ui->files->rowCount() + 1);

    QTableWidgetItem *newItem = new QTableWidgetItem();
    newItem->setText("New Folder");
    newItem->setIcon(QIcon::fromTheme("folder"));
    ui->files->setItem(ui->files->rowCount() - 1, 0, newItem);
    oldFileName = "mkdir";
    ui->files->editItem(newItem);
}

void MainWindow::on_actionAdd_To_Bar_triggered()
{
    bool ok;
    QString text = QInputDialog::getText(this, "Add to Bar", "What do you want to name this folder?", QLineEdit::Normal, currentDir.dirName(), &ok);
    if (ok) {
        QFile fav(QDir::homePath() + "/.myfilemanager/fav");
        fav.open(QFile::Append);
        fav.write(QString(currentDir.path() + "," + text + "\n").toUtf8());
        fav.close();
        blockDevicesChanged();
    }
}

void MainWindow::on_addr_returnPressed()
{
    currentDir.setPath(ui->addr->text());
    reloadList();
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
    if (obj == ui->files->viewport()) {
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *mouseEvent = (QMouseEvent*) event;
            if (mouseEvent->button() == Qt::LeftButton) {
                startPos = mouseEvent->pos();
            }
            if (ui->files->selectedItems().count() > 1) {
                mouseEvent->ignore();
                return false;
            }
        } else if (event->type() == QEvent::MouseMove) {
            QMouseEvent *mouseEvent = (QMouseEvent*) event;
            if (mouseEvent->buttons() & Qt::LeftButton) {
                if ((mouseEvent->pos() - startPos).manhattanLength() > QApplication::startDragDistance()) {
                    if (ui->files->selectedItems().count() > 0) {
                        QDrag *drag = new QDrag(this);
                        QMimeData *mime = new QMimeData;
                        QList<QUrl> allFiles;

                        for (QTableWidgetItem *item : ui->files->selectedItems()) {
                            if (item->column() == 0) {
                                allFiles.append(QUrl::fromLocalFile(currentDir.path() + QDir::separator() + item->text()));
                            }
                        }

                        mime->setUrls(allFiles);
                        drag->setMimeData(mime);
                        drag->exec(Qt::CopyAction);
                    }
                }
            }
            return false;
        }
    } else if (obj == ui->files) {
        if (event->type() == QEvent::DragEnter) {
            QDragEnterEvent *mouseEvent = (QDragEnterEvent*) event;
            if (mouseEvent->mimeData() != NULL) {
                mouseEvent->acceptProposedAction();
            }
        } else if (event->type() == QEvent::Drop) {
            QDropEvent *mouseEvent = (QDropEvent*) event;
            if (mouseEvent->mimeData()->hasUrls()) {
                QStringList files;
                for (QUrl urlFile : mouseEvent->mimeData()->urls()) {
                    if (urlFile.scheme() == "file") {
                        files.append(urlFile.path());
                    }
                }

                new MYCOPY(files, currentDir.path() + QDir::separator());
            }
        }
    }
    return false;
}

void MainWindow::on_fav_itemClicked(QListWidgetItem *item)
{
    //Decide if clicked item is a favourite or not
    if (favDirs.count() - 1 < ui->fav->selectionModel()->selectedIndexes().at(0).row()) { //The item is not a favourite
        //Determine whether this is an interesting folder or a device
        if (item->text() == "Trash") { //This is the trash folder; navigate to the trash folder
            currentDir.setPath(QDir::homePath() + "/.local/share/Trash/files");
            reloadList();
        }
    } else { //The item is a favourite; navigate to that location
        currentDir.setPath(favDirs.at(ui->fav->selectionModel()->selectedIndexes().at(0).row()));
        reloadList();
    }
}

void MainWindow::on_fav_customContextMenuRequested(const QPoint &pos)
{
    if (ui->fav->selectedItems().count() != 0) {
        QMenu *cx = new QMenu(this);
        if (favDirs.count() - 1 < ui->fav->selectionModel()->selectedIndexes().at(0).row()) {
            cx->addSection("For \"" + ui->fav->selectedItems().at(0)->text() + "\"");
        }
        cx->exec(ui->fav->mapToGlobal(pos));
    }
}

void MainWindow::goTo(QString dir) {
    currentDir.setPath(dir);
    reloadList();
}

void MainWindow::on_actionProperties_triggered()
{
    if (ui->files->selectedItems().count() > 0) {
        QFile *f = new QFile(currentDir.path() + QDir::separator() + ui->files->selectedItems().at(0)->text());
        Properties* p = new Properties(f, this);
        p->show();
    }
}

void MainWindow::on_actionMove_to_Trash_triggered()
{
    filesMovedToTrash.clear();

    QDir trash = QDir::home();
    trash.cd(".local/share/");
    trash.mkdir("Trash");
    trash.cd("Trash");
    trash.mkdir("files");
    trash.mkdir("info");

    QFile directorySizes(trash.path() + "/directorysizes");
    directorySizes.open(QFile::Append);

    for (QTableWidgetItem *item : ui->files->selectedItems()) {
        if (item->column() == 0) {
            QString fileLocation = currentDir.path() + QDir::separator() + item->text();
            if (QFile(fileLocation).exists()) {
                QFile(fileLocation).rename(trash.path() + "/files/" + item->text());
            } else {
                //QDir dirToRemove(currentDir);
                //dirToRemove.cd(item->text());
                currentDir.rename(item->text(), trash.path() + "/files/ " + item->text());
            }

            QFile trashinfo(trash.path() + "/info/" + item->text() + ".trashinfo");
            trashinfo.open(QFile::WriteOnly);
            trashinfo.write(QString("[Trash Info]\n").toUtf8());
            trashinfo.write(QString("Path=" + fileLocation + "\n").toUtf8());
            trashinfo.write(QString("DeletionDate=" + QDateTime::currentDateTime().toString("yyyy-MM-ddThh:mm:ss") + "\n").toUtf8());
            trashinfo.close();

            ui->movedToTrashFrame->setVisible(true);
            filesMovedToTrash.append(item->text());
        }
    }

    reloadList();
}

void MainWindow::restoreFilesFromTrash(QStringList filenames) {
    QDir trash = QDir::home();
    trash.cd(".local/share/Trash");

    for (QString fileToRestore : filenames) {
        //Read Restore Info
        QFile info(trash.path() + "/info/" + fileToRestore + ".trashinfo");
        if (info.exists()) { //Sanity Check
            info.open(QFile::ReadWrite);
            QString moveTo;

            for (QString line : QString(info.readAll()).split("\n")) {
                if (line.startsWith("Path=")) {
                    moveTo = line.split("=").at(1); //Read original file path
                }
            }

            if (moveTo == "") { //Malformed info file

            } else {
                if (QFile(trash.path() + "/files/" + fileToRestore).exists()) { //Restore file
                    QFile(trash.path() + "/files/" + fileToRestore).rename(moveTo);
                } else if (QDir(trash.path() + "/files/" + fileToRestore).exists()) { //Restore Directory
                    QDir(trash.path() + "/files").rename(fileToRestore, moveTo);

                }
            }
            info.close();
            info.remove();
        }
    }
}

void MainWindow::on_actionNew_Window_triggered()
{
    //Create a new window and show it
    MainWindow* w = new MainWindow();
    w->show();
}

void MainWindow::on_actionClose_Window_triggered()
{
    this->close();
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::exit(0);
}

void MainWindow::on_actionRestore_triggered()
{
    QStringList filesToRestore;
    for (QTableWidgetItem *item : ui->files->selectedItems()) {
        if (item->column() == 0) {
            filesToRestore.append(item->text());
        }
    }

    restoreFilesFromTrash(filesToRestore);

    reloadList();
}

void MainWindow::on_actionEmpty_Trash_triggered()
{
    ui->files->selectAll();
    on_actionDelete_triggered();
}

void MainWindow::on_actionShow_Hidden_Files_toggled(bool arg1)
{
    if (arg1) {
        currentDir.setFilter(QDir::Files | QDir::Dirs | QDir::Hidden);
    } else {
        currentDir.setFilter(QDir::Files | QDir::Dirs);
    }
    reloadList();
}

void MainWindow::on_actionCreateFile_triggered()
{
    createfile *cr = new createfile(&currentDir);
    cr->show();
}

void MainWindow::on_lineEdit_editingFinished()
{
    if(ui->lineEdit->text()!="")
    {
        this->searchMode = true;
    }
    else
    {
        this->searchMode = false;
    }
    reloadList();
}
