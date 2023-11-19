#ifndef CREATEFILE_H
#define CREATEFILE_H

#include <QWidget>
#include <QDir>

namespace Ui {
class createfile;
}

class createfile : public QWidget
{
    Q_OBJECT

public:
    explicit createfile(QDir *currentDir, QWidget *parent = 0);
    ~createfile();

private slots:
    void on_pushButton_clicked();

private:
    Ui::createfile *ui;
    QDir *currentDir;
};

#endif // CREATEFILE_H
