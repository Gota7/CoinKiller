#ifndef MGame_H
#define MGame_H

#include "filesystem.h"
#include "tileset.h"
#include "levelmanager.h"
#include "settingsmanager.h"

#include <QStandardItemModel>
#include <QtXml>

class MGame
{
public:
    MGame(FilesystemBase* fs, SettingsManager* settingsMgr);


    Tileset* getTileset(QString name);
    LevelManager* getLevelManager(QWidget* parent, QString path);
    LevelManager* getFile(QWidget* parent, QString path);

    QStandardItemModel* getCourseModel();
    QStandardItemModel* getTilesetModel();
    QStandardItemModel* getTilesetModel(int id, bool includeNoneItem = false);

    FilesystemBase* fs;
    SettingsManager* settingsMgr;

private:
    void loadLevelNamesCat(QStandardItem* item, QDomElement node);

};

#endif // MGame_H
