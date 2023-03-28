#include "simpletimeline.h"


simpleTimeline::simpleTimeline(unsigned int sizeX, unsigned int sizeY, QObject *parent)
    : QObject(parent)
    , frameDuration(100)
    , activeFrame(0)
    , activeLayer(0)
    , size(sizeX, sizeY)
{
            
    
}

simpleTimeline::~simpleTimeline(){
    QGraphicsScene* trash;
    while (!frames.empty()) {
        trash = frames.back();
        frames.pop_back();
        delete trash;
    }


}


QVector<QGraphicsScene*> simpleTimeline::getFrames(){
    return frames;
}

unsigned int simpleTimeline::getActiveLayer(){
    return activeLayer;
}
unsigned int simpleTimeline::getActiveFrame(){
    return activeFrame;
}
unsigned int simpleTimeline::getFrameDuration(){
    return frameDuration;
}
unsigned int simpleTimeline::getSizeX(){
    return size.width();
}
unsigned int simpleTimeline::getSizeY(){
    return size.height();
}
//bool simpleTimeline::getOnionSkinEnabled(){
//    return onionSkinEnabled;
//}

