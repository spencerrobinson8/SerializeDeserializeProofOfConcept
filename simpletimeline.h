#ifndef SIMPLETIMELINE_H
#define SIMPLETIMELINE_H

#include "simpleframe.h"
#include <QWidget>
#include <QTimer>
#include <QPixmap>
#include <QGraphicsScene>


class simpleTimeline : public QObject
{
    Q_OBJECT

public:
    simpleTimeline(unsigned int sizeX, unsigned int sizeY, QObject* parent = nullptr);
    ~simpleTimeline();
      QList<QGraphicsScene*> getFrames();
      unsigned int getActiveLayer();
      unsigned int getActiveFrame();
      unsigned int getFrameDuration();
      unsigned int getSizeX();
      unsigned int getSizeY();
      void addFrame();
//    bool getOnionSkinEnabled();
private:
    QList<QGraphicsScene*> frames;
    unsigned int activeLayer;
    unsigned int activeFrame;
    unsigned int frameDuration;
    QSize size;
    //bool onionSkinEnabled;
};

#endif // SIMPLETIMELINE_H
