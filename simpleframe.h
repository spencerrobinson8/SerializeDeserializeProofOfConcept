#ifndef SIMPLEFRAME_H
#define SIMPLEFRAME_H

#include <QObject>
#include <QVector>
#include <QImage>


class simpleFrame
{

public:
    explicit simpleFrame();

private:
    QVector<QImage> layers;
};

#endif // SIMPLEFRAME_H
