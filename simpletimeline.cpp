#include "simpletimeline.h"


simpleTimeline::simpleTimeline(QObject *parent) : QObject(parent)
{

    //the other variables should be initialized in h file
    //activeImage = nullptr;
    frameRate = 60;
    sizeX = 64;
    sizeY=64;
    onionSkinEnabled = false;
            
    
}

simpleTimeline::~simpleTimeline(){
    delete activeImage;
    delete frames;
    delete activeFrame;


}

simpleTimeline::simpleTimeline(const simpleTimeline& other, QObject *parent): QObject(parent){
    frameRate = other.frameRate;
    sizeX = other.sizeX;
    this->sizeY = other.sizeY;
    this->onionSkinEnabled = other.onionSkinEnabled;
    activeImage=other.activeImage;
    activeFrame = other.activeFrame;
    frames=other.frames;
}
QVector<QImage>* simpleTimeline::getFrames(){
    return frames;
}

QImage* simpleTimeline::getActiveImage(){
    return activeImage;
}
simpleFrame* simpleTimeline::getActiveFrame(){
    return activeFrame;
}
unsigned int simpleTimeline::getFrameRate(){
    return frameRate;
}
unsigned int simpleTimeline::getSizeX(){
    return sizeX;
}
unsigned int simpleTimeline::getSizeY(){
    return sizeY;
}
bool simpleTimeline::getOnionSkinEnabled(){
    return onionSkinEnabled;
}

