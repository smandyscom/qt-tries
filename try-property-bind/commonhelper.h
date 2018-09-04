#ifndef COMMONHELPER_H
#define COMMONHELPER_H

#include <QObject>
#include <QFile>
#include <QDir>
#include <QApplication>

#include <QDebug>

class CommonHelper : public QObject
{
    Q_OBJECT
public:
    explicit CommonHelper(QObject *parent = nullptr);

    static void setStyle(const QString &style) {
            QFile qss(style);
            qDebug() << QDir::currentPath();
            qss.open(QFile::ReadOnly);
            qApp->setStyleSheet(qss.readAll());
            qss.close();
        }
signals:

public slots:
};

#endif // COMMONHELPER_H
