#ifndef TARGET_H
#define TARGET_H

#include "circle.h"

class Target : public Circle
{
    Q_OBJECT
public:
    explicit Target(QQuickItem *parent = 0);
    ~Target();

private:

signals:

public slots:
};

#endif // TARGET_H
