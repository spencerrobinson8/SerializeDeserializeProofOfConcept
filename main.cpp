#include <QCoreApplication>
#include "simpletimeline.h"
#include <iostream>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QString>
#include <QFile>
#include <QDir>
using std::cout;


void save(simpleTimeline& t){

    QJsonObject jTimeline;
    jTimeline["activeLayer"] = (int) t.getActiveLayer();
    jTimeline["activeFrame"] = (int) t.getActiveFrame();
//    QJsonArray frames;
//    foreach (QGraphicsScene s, t.getFrames()){
//        frames.push_back(s);
//    }
//    jTimeline["frames"] = frames;
//    jTimeline["onionSkinEnabled"] = t.getOnionSkinEnabled();
    jTimeline["width"] = (int)t.getSizeX();
    jTimeline["height"] =(int) t.getSizeY();
    jTimeline["frameDuration"] = (int)t.getFrameDuration();
    QJsonDocument doc( jTimeline );
    QFile file("JsonFile.ssp");
    if(file.open(QFile::WriteOnly)){
        file.write(doc.toJson());
    }
    file.close();
}

void load(){

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    simpleTimeline timeline(64,64);
    save(timeline);
    load();
    return a.exec();

}

