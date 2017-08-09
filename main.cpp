#include <QCoreApplication>
#include <QStringList>
#include <QDebug>
#include <QDate>
#include <QCryptographicHash>
#include <QFile>
#include <QDir>
#include "ziphelper.h"
#include <QTime>
#include <QProcess>

int main(int argc, char *argv[])
{
    QString basicDir = "D:/Projects/untitled";

    QString appDir = basicDir + "/zmmzcs";

    QDateTime  time = QDateTime ::currentDateTime();
    QString txtDateTime = time.toString("yyyy-MM-dd");

    QDir dir(appDir);

    ZipHelper zh;

    QStringList apps = dir.entryList(QDir::Files);

    QTime times;
    times.start();

    for (int i = 0; i< apps.size(); i++) {

        QString file = appDir + "/" + QString("%1").arg(i);

        qDebug() << file;
        QFile f(file);
        if (!f.open(QIODevice::ReadOnly)) {
            qDebug() << "open failed!\n";
            continue;
        }

        ZipEntry *entry = new ZipEntry();
        entry->name = file;
        entry->data = f.readAll();
        f.close();
        zh.entries.append(entry);
    }

    QString zipFile = appDir + "/" + QString("%1.zip").arg(txtDateTime);

    qDebug() << "the zipFile name is "<< zipFile;

    if (zh.writeZipFile(zipFile)) {

        qDebug() << "this is niubi\n";
    }

    qDebug() << "the time costs " << times.elapsed() / 1000.0 << "s" << endl;




    QString tool  = basicDir + "/zxlycon.exe";

    times.restart();


    QString cmd = QString("%1 push %2 /mnt/sdcard/Xiaomi/").arg(tool).arg(zipFile);

    qDebug("push zipfile Test cmd = %s\n", qPrintable(cmd));

    QProcess process;

    process.start(cmd);
    process.waitForFinished();


    qDebug() << "the time push apk files costs " << times.elapsed() / 1000.0 << "s" << endl;

    return 0;
}
