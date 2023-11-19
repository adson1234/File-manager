#ifndef COPY_H
#define COPY_H
#include "mainwindow.h"
#include "copyworker.h"

#include <QStringList>
#include <QThread>
#include <QProgressBar>

class MainWindow;
class MYCOPY : public QObject
{
    Q_OBJECT
public:
    MYCOPY(QStringList source, QString dest, bool deleteOriginal = false, MainWindow *parent = 0);
    void runcopy();

public slots:
    void copyFinished();
private:
    QStringList source;
    QString dest;
    bool deleteOriginal;
    QThread *thread;
};

#endif // COPY_H
