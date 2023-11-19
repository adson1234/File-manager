#include "copy.h"

MYCOPY::MYCOPY(QStringList source, QString dest, bool deleteOriginal, MainWindow *parent) : QObject(parent)
{
    this->source = source;
    this->dest = dest;
    this->deleteOriginal=deleteOriginal;
}

void MYCOPY::runcopy()
{
    //http://wiki.qt.io/QThreads_general_usage
    thread = new QThread;
    copyWorker *worker = new copyWorker(source, dest, deleteOriginal);
    worker->moveToThread(thread);
    connect(thread, SIGNAL (started()), worker, SLOT (process()));
    connect(thread, SIGNAL (finished()), thread, SLOT (deleteLater()));
    connect(worker, SIGNAL (finished()), thread, SLOT (quit()));
    connect(worker, SIGNAL (finished()), this, SLOT (copyFinished()));
    connect(worker, SIGNAL (finished()), worker, SLOT (deleteLater()));
    thread->start();
}

void MYCOPY::copyFinished() {
    QMessageBox msgBox;
    msgBox.setText("Files copied");
    msgBox.exec();
}
