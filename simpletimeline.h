#ifndef SIMPLETIMELINE_H
#define SIMPLETIMELINE_H

#include "simpleframe.h"
#include <QObject>


class simpleTimeline : public QObject
{
    Q_OBJECT

public:
    explicit simpleTimeline(QObject *parent = nullptr);
    explicit simpleTimeline(const simpleTimeline&, QObject *parent = nullptr);
    ~simpleTimeline();
    QVector<QImage>* getFrames();
    QImage* getActiveImage();
    simpleFrame* getActiveFrame();
    unsigned int getFrameRate();
    unsigned int getSizeX();
    unsigned int getSizeY();
    bool getOnionSkinEnabled();
private:
    QVector<QImage>* frames;
    QImage* activeImage;
    simpleFrame* activeFrame;
    unsigned int frameRate;
    unsigned int sizeX;
    unsigned int sizeY;
    bool onionSkinEnabled;
};

#endif // SIMPLETIMELINE_H
