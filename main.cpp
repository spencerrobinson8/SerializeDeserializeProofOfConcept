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
#include <QVector>
#include <QDebug>


void save(simpleTimeline& t){

    QJsonObject jTimeline;
    jTimeline["height"] =(int) t.getSizeY();
    jTimeline["width"] = (int)t.getSizeX();
    jTimeline["numberOfFrames"] = (int)t.getFrames().size();
    QList<QRgb> list;
    int n = 0;
    QJsonArray arr2;
    QJsonArray arr;

    foreach(QGraphicsScene s, t.getFrames()) {
        QImage image(s.sceneRect().size().toSize(), QImage::Format_ARGB32);
        list = image.colorTable();
        foreach(QRgb color, list) {
            arr.push_back((int)color);
        }
    }
    arr2.push_back(arr);
    jTimeline["frame" + n] = arr2;
    n++;

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
    simpleTimeline* timeline = new simpleTimeline(64, 64);
//    timeline->addFrame();
//    timeline->addFrame();
    save(*timeline);
    load();
    return 0;



    return a.exec();

}

