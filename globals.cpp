#include "globals.h"
#include <QDebug>
#include <QTimer>
#include <QEventLoop>

QString s_platformName;
QSize s_screenSize;
QQuickItem *s_rootItem;

Globals::Globals() : QObject()
{
}

void Globals::setScreenSize(const QSize &screenSize) { s_screenSize = screenSize; }
void Globals::setRootItem(QQuickItem *item) { s_rootItem = item; }
void Globals::setPlatformName(const QString &name) { s_platformName = name; }

QString Globals::platformName() { return s_platformName; }
QSize Globals::screenSize() { return s_screenSize; }
QQuickItem* Globals::rootItem() { return s_rootItem; }

void Globals::delay(int msecs)
{
    QTimer timer;
    QEventLoop loop;
    QObject::connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    timer.start(msecs);

    loop.exec();
}
