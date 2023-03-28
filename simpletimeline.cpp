#include "simpletimeline.h"


simpleTimeline::simpleTimeline(unsigned int sizeX, unsigned int sizeY, QObject *parent)
    : QObject(parent)
    , activeLayer(0)
    , activeFrame(0)
    , frameDuration(100)
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

void simpleTimeline::addFrame() {
    QGraphicsScene* s = new QGraphicsScene();
    frames.push_back(s);
}

QVector<QGraphicsScene*> simpleTimeline::getFrames(){
    return frames;
}

//unsigned int simpleTimeline::getActiveLayer(){
//    return activeLayer;
//}
//unsigned int simpleTimeline::getActiveFrame(){
//    return activeFrame;
//}
//unsigned int simpleTimeline::getFrameDuration(){
//    return frameDuration;
//}
unsigned int simpleTimeline::getSizeX(){
    return size.width();
}
unsigned int simpleTimeline::getSizeY(){
    return size.height();
}
//bool simpleTimeline::getOnionSkinEnabled(){
//    return onionSkinEnabled;
//}

