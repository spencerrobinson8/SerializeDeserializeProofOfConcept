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


void save(simpleTimeline& t){

    QJsonObject jTimeline;
    jTimeline["activeImage"] = t.getActiveImage();
    jTimeline["activeFrame"] = t.getActiveFrame();
    jTimeline["frames"] = t.getFrames();
    jTimeline["onionSkinEnabled"] = t.getOnionSkinEnabled();
    jTimeline["sizeX"] = (int)t.getSizeX();
    jTimeline["sizeY"] =(int) t.getSizeY();
    jTimeline["frameRate"] = (int)t.getFrameRate();
    QJsonDocument doc( jTimeline );
    QFile file(":/JsonFile");
    file.open(QFile::WriteOnly);
    file.write(doc.toJson());
    file.close();
}

void load(){

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    simpleTimeline timeline{};
    save(timeline);
    load();
    return a.exec();

}

