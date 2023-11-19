#ifndef COPYWORKER_H
#define COPYWORKER_H
#include <QObject>
#include <QString>
#include <QStringList>
#include <QFileInfo>
#include <QDir>
#include <QApplication>
#include <QMessageBox>

class copyWorker : public QObject
{
    Q_OBJECT
public:
    copyWorker(QStringList files, QString dest, bool deleteOriginal = false);
    ~copyWorker();
signals:
    void finished();
public slots:
    void process();
    bool process2(QString from_dir, QString to_dir, bool replace_on_conflit);
private:
    QStringList files;
    QString dest;
    bool deleteOriginal;
};

#endif // COPYWORKER_H
