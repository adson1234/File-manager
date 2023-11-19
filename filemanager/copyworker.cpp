#include "copyworker.h"
#include "qdebug.h"

copyWorker::copyWorker(QStringList files, QString dest, bool deleteOriginal) { // Constructor
    this->files = files;
    this->dest = dest;
    this->deleteOriginal = deleteOriginal;
}

copyWorker::~copyWorker() { // Destructor

}

void copyWorker::process()
{
    foreach(QString tmp,files)
    {
        // for folder, recursive copy using following function
        if(QDir(tmp).exists())
        {
            QDir(dest).mkdir(QDir(tmp).dirName());
            process2(tmp,dest+QDir::separator()+QDir(tmp).dirName(),deleteOriginal);
        }
        else
        {
            QString to = dest+QDir::separator()+QFileInfo(tmp).fileName();
            if (QFile::exists(to))
            {
                /*
                 * QMessageBox only allowed in main GUI thread, other thread
                 * may cause crash.
                 */
                /*QMessageBox msgBox;
                msgBox.setWindowTitle("File already exists");
                msgBox.setText("Override?");
                msgBox.setStandardButtons(QMessageBox::Yes);
                msgBox.addButton(QMessageBox::No);
                msgBox.setDefaultButton(QMessageBox::No);
                if(msgBox.exec() == QMessageBox::Yes){
                    QFile::remove(to);
                }else {
                    continue;
                }*/
                if(deleteOriginal)
                {
                    QFile::remove(to);
                }
            }
            QFile::copy(tmp,to);
        }
    }
    emit finished();
}

/*
 * this function we can copy files from one directory to another
 * and if conflict occur we can skip or replace them
 */
bool copyWorker:: process2(QString from_dir, QString to_dir, bool replace_on_conflit)
{
    QDir dir(from_dir);
    from_dir += QDir::separator();
    to_dir += QDir::separator();
    foreach (QString copy_file, dir.entryList(QDir::Files))
    {
        QString from = from_dir + copy_file;
        QString to = to_dir + copy_file;
        if (QFile::exists(to))
        {
            if (replace_on_conflit)
            {
                if (QFile::remove(to) == false)
                {
                    return false;
                }
            }
            else
            {
                continue;
            }
        }
        if (QFile::copy(from, to) == false)
        {
            return false;
        }
    }

    foreach (QString copy_dir, dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot))
    {
        QString from = from_dir + copy_dir;
        QString to = to_dir + copy_dir;

        if (dir.mkpath(to) == false)
        {
            return false;
        }
        if (process2(from, to, replace_on_conflit) == false)
        {
            return false;
        }
    }
    return true;
}
