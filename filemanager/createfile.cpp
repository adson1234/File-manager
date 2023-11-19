#include "createfile.h"
#include "ui_createfile.h"
#include <QTextStream>
#include <QDebug>

createfile::createfile(QDir *currentDir, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createfile)
{
    this->currentDir = currentDir;
    ui->setupUi(this);
}

createfile::~createfile()
{
    delete ui;
}

void createfile::on_pushButton_clicked()
{
    QString filename(currentDir->path()+ QDir::separator()+ ui->lineEdit->text());
    QFile f(filename);
    if ( f.open(QIODevice::ReadWrite) )
    {
        QTextStream stream(&f);
        stream << ui->textEdit->toPlainText();
        f.flush();
        f.close();
    }

    this->close();
}
