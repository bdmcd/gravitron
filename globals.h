#ifndef GLOBALS_H
#define GLOBALS_H

#include <QQuickItem>
#include <QSize>

class Globals : public QObject
{
    Q_OBJECT
public:
    explicit Globals();

    Q_INVOKABLE void setScreenSize(const QSize &screenSize);
    Q_INVOKABLE void setRootItem(QQuickItem *item);
    static void setPlatformName(const QString &name);

    static QSize screenSize();
    static QString platformName();
    static QQuickItem* rootItem();

    static void delay(int msecs);
};

#endif // GLOBALS_H
