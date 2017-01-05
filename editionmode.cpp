#include "editionmode.h"
#include "unitsconvert.h"
#include "is.h"

#include <QApplication>
#include <QClipboard>
#include <QDebug>

ObjectsEditonMode::ObjectsEditonMode(Level *level)
{
    this->level = level;
    selectionMode = false;
}

void ObjectsEditonMode::mouseDown(int x, int y, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers)
{
    dx = x;
    dy = y;
    lx = x;
    ly = y;

    if (buttons == Qt::RightButton)
    {
        selectedObjects.clear();

        if (drawType == 0)
        {
            if (selTileset == -1 || selObject == -1) return;
            int id = selTileset << 12;
            id = (id & 0xF000) | selObject;
            BgdatObject* bgdatobj = new BgdatObject(toNext20(x-10), toNext20(y-10), 20, 20, id, selLayer);
            level->objects[selLayer].append(bgdatobj);
            newObject = bgdatobj;
            creatNewObject = true;
            selectedObjects.append(bgdatobj);
        }
        else if (drawType == 1)
        {
            if (selSprite == -1) return;
            Sprite* spr = new Sprite(0, 0, selSprite);
            spr->setRect();
            int xpos = toNext10(dx-spr->getwidth()/2-spr->getOffsetX());
            int ypos = toNext10(dy-spr->getheight()/2-spr->getOffsetY());
            if (xpos < 0) xpos = 0;
            if (ypos < 0) ypos = 0;
            spr->setPosition(xpos, ypos);
            level->sprites.append(spr);
            selectedObjects.append(spr);
        }
        else if (drawType == 2)
        {
            Entrance* entr = level->newEntrance(x-10, y-10);
            level->entrances.append(entr);
            selectedObjects.append(entr);
        }
        else if (drawType == 3)
        {
            Zone* zone = level->newZone(x-200, y-120);
            level->zones.append(zone);
            selectedObjects.append(zone);
        }
        else if (drawType == 4)
        {
            Location* loc = level->newLocation(x, y);
            level->locations.append(loc);
            newObject = loc;
            creatNewObject = true;
            selectedObjects.append(loc);
        }
        else if (drawType == 5)
        {
            Path* path = level->newPath();
            level->paths.append(path);
            PathNode* node = new PathNode(qMax(toNext10(x-10), 0), qMax(toNext10(y-10), 0), 0, 0, 0, path);
            path->insertNode(node);
            selectedObjects.append(node);
        }
        else if (drawType == 6)
        {
            ProgressPath* path = level->newProgressPath();
            level->progressPaths.append(path);
            ProgressPathNode* node = new ProgressPathNode(qMax(toNext10(x-10), 0), qMax(toNext10(y-10), 0), path);
            path->insertNode(node);
            selectedObjects.append(node);
        }

        checkEmits();
        emit updateEditors();
        if (selectedObjects.size() == 1) emit selectdObjectChanged(selectedObjects[0]);
    }

    if (buttons == Qt::LeftButton)
    {
        mouseAct = getActionAtPos(x, y);

        if (mouseAct.pAdd != AddNone)
        {
            Object* oldNode = selectedObjects[0];
            selectedObjects.clear();

            if (is<PathNode*>(oldNode))
            {
                PathNode* oldPNode = dynamic_cast<PathNode*>(oldNode);
                Path* parentPath = oldPNode->getParentPath();
                PathNode* newNode = new PathNode(toNext10(x-10), toNext10(y-10), 0, 0, 0, parentPath);
                if (mouseAct.pAdd == AddBefore)
                    parentPath->insertNode(newNode, parentPath->getIndexOfNode(oldPNode));
                else
                    parentPath->insertNode(newNode, parentPath->getIndexOfNode(oldPNode)+1);
                selectedObjects.append(newNode);
            }
            else
            {
                ProgressPathNode* oldPNode = dynamic_cast<ProgressPathNode*>(oldNode);
                ProgressPath* parentPath = oldPNode->getParentPath();

                ProgressPathNode* newNode = new ProgressPathNode(toNext10(x-10), toNext10(y-10), parentPath);
                if (mouseAct.pAdd == AddBefore)
                    parentPath->insertNode(newNode, parentPath->getIndexOfNode(oldPNode));
                else
                    parentPath->insertNode(newNode, parentPath->getIndexOfNode(oldPNode)+1);
                selectedObjects.append(newNode);
            }
        }

        else if (!mouseAct.drag || (mouseAct.hor == ResizeNone && mouseAct.vert == ResizeNone))
        {
            QList<Object*> tempSelObjects = selectedObjects;
            bool shift = false;

            if (modifiers != Qt::ShiftModifier)
                selectedObjects = getObjectsAtPos(dx, dy, dx, dy, true);
            else if (modifiers != Qt::ControlModifier)
            {
                shift = true;
                QList<Object*> newObjList = getObjectsAtPos(dx, dy, dx, dy, true);
                if (newObjList.size() == 1)
                {
                    if(!selectedObjects.contains(newObjList[0]))
                        selectedObjects.append(newObjList[0]);
                    else
                        selectedObjects.removeOne(newObjList[0]);
                }
            }

            if (!shift && selectedObjects.size() != 0 && tempSelObjects.contains(selectedObjects[0]))
            {
                selectedObjects = tempSelObjects;
            }

            if (selectedObjects.size() == 0)
            {
                selectionMode = true;
            }
            else if (modifiers == Qt::ControlModifier)
            {
                sortSelection();
                selectedObjects = cloneObjects(selectedObjects);
                level->add(selectedObjects);
                emit updateEditors();
                clone = true;
            }

            checkEmits();
        }

        mouseAct = getActionAtPos(x, y);
        if (!clone) actualCursor = getCursorAtPos(x, y);
        else actualCursor = Qt::SizeAllCursor;
        updateSelectionBounds();
    }
}

void ObjectsEditonMode::mouseDrag(int x, int y, Qt::KeyboardModifiers modifieres)
{
    if (creatNewObject)
    {
        lx = x;
        ly = y;

        int xpos = typeRound(dx, newObject->getType());
        int ypos = typeRound(dy, newObject->getType());

        int mX = typeRound(qMax(0, lx), newObject->getType());
        int mY = typeRound(qMax(0, ly), newObject->getType());

        int w = qAbs(mX-xpos);
        int h = qAbs(mY-ypos);

        if (newObject->getType() == 0)
        {
            if (mX < 0) mX = 0;
            else w += 20;
            if (mY < 0) mY = 0;
            else h += 20;
        }

        newObject->setPosition(qMin(xpos, mX), qMin(ypos, mY));
        newObject->resize(w, h);

        emit updateEditors();

        return;
    }

    if (selectionMode)
    {
        lx = x;
        ly = y;
        selectedObjects.clear();
        selectedObjects = getObjectsAtPos(lx, ly, dx, dy, false);
    }
    else
    {
        updateSelectionBounds();

        // Drag
        if ((mouseAct.hor == ResizeNone && mouseAct.vert == ResizeNone) || clone)
        {
            int xDelta = x-lx;
            int yDelta = y-ly;

            // Quick and dirty fix to prevent the dragging objects from wiggling sometimes
            if (xDelta == -xDeltaL) xDelta = 0;
            else xDeltaL = xDelta;
            if (yDelta == -yDeltaL) yDelta = 0;
            else yDeltaL = yDelta;

            if (xDelta < -minBoundX) xDelta = -minBoundX;
            if (yDelta < -minBoundY) yDelta = -minBoundY;
            if (xDelta == 0 && yDelta == 0) return;

            int snap = 0;
            if (selectionHasBGDats)
            {
                xDelta = toNext20(xDelta);
                yDelta = toNext20(yDelta);
                snap = 20;
            }
            else if (modifieres == Qt::AltModifier)
            {
                xDelta = toNext16Compatible(xDelta);
                xDelta = toNext16Compatible(xDelta);
            }
            else
            {
                xDelta = toNext10(xDelta);
                yDelta = toNext10(yDelta);
                snap = 10;
            }

            foreach (Object* obj, selectedObjects)
            {
                obj->increasePosition(xDelta, yDelta, snap);
            }

            minBoundX += xDelta;
            minBoundY += yDelta;
            lx += xDelta;
            ly += yDelta;

            emit updateEditors();
        }
        // Resize
        else
        {
            int xDelta = x-lx;
            int yDelta = y-ly;
            int minSize = 0;

            int snap = 0;
            if (selectionHasBGDats)
            {
                xDelta = toNext20(xDelta);
                yDelta = toNext20(yDelta);
                minSize = 20;
                snap = 0;
            }
            else if (modifieres == Qt::AltModifier)
            {
                xDelta = toNext16Compatible(xDelta);
                xDelta = toNext16Compatible(xDelta);
            }
            else
            {
                xDelta = toNext10(xDelta);
                yDelta = toNext10(yDelta);
                snap = 10;
            }

            int xMoveDelta = 0;
            int xResizeDelta = 0;
            int yMoveDelta = 0;
            int yResizeDelta = 0;

            if (xDelta == 0 && yDelta == 0) return;

            if (mouseAct.hor == ResizeBegin)
            {
                if (-xDelta <= -minSizeX) xDelta = -(-minSizeX) - minSize;
                if (xDelta < -minBoundX) xDelta = -minBoundX;
                xMoveDelta = xDelta;
                xResizeDelta = -xDelta;
            }
            if (mouseAct.vert == ResizeBegin)
            {
                if (-yDelta <= -minSizeY) yDelta = -(-minSizeY) - minSize;
                if (yDelta < -minBoundY) yDelta = -minBoundY;
                yMoveDelta = yDelta;
                yResizeDelta = -yDelta;
            }
            if (mouseAct.hor == ResizeEnd)
            {
                if (xDelta <= -minSizeX) xDelta = -minSizeX + minSize;
                xResizeDelta = xDelta;
            }
            if (mouseAct.vert == ResizeEnd)
            {
                if (yDelta <= -minSizeY) yDelta = -minSizeY + minSize;
                yResizeDelta = yDelta;
            }

            if (xMoveDelta == 0 && yMoveDelta == 0 && xResizeDelta == 0 && yResizeDelta == 0) return;

            minBoundX += xMoveDelta;
            minBoundY += yMoveDelta;
            minSizeX += xResizeDelta;
            minSizeY += yResizeDelta;

            foreach (Object* obj, selectedObjects)
            {
                obj->increasePosition(xMoveDelta, yMoveDelta);
                if (obj->isResizable()) obj->increaseSize(xResizeDelta, yResizeDelta, snap);
            }

            lx += xDelta;
            ly += yDelta;

            emit updateEditors();
        }
    }
}

void ObjectsEditonMode::mouseMove(int x, int y)
{
    actualCursor = getCursorAtPos(x, y);
}

void ObjectsEditonMode::mouseUp(int x, int y)
{
    mouseAct = getActionAtPos(x, y);
    actualCursor = getCursorAtPos(x, y);
    if (selectionMode) checkEmits();
    selectionMode = false;
    creatNewObject = false;
    clone = false;
}

void ObjectsEditonMode::render(QPainter *painter)
{
    foreach (Object* obj, selectedObjects)
    {
        QRect objrect(obj->getx()+obj->getOffsetX(), obj->gety()+obj->getOffsetY(), obj->getwidth(), obj->getheight());

        painter->setPen(QPen(QColor(255,255,255,200), 1, Qt::DotLine));
        painter->drawRect(objrect);
        painter->fillRect(objrect, QColor(255,255,255,75));

        if (obj->isResizable())
        {
            drawResizeKnob(obj->getx(), obj->gety(), painter);
            drawResizeKnob(obj->getx() + obj->getwidth(), obj->gety(), painter);
            drawResizeKnob(obj->getx(), obj->gety() + obj->getheight(), painter);
            drawResizeKnob(obj->getx() + obj->getwidth(), obj->gety() + obj->getheight(), painter);
            drawResizeKnob(obj->getx() + obj->getwidth()/2, obj->gety(), painter);
            drawResizeKnob(obj->getx(), obj->gety() + obj->getheight()/2, painter);
            drawResizeKnob(obj->getx() + obj->getwidth()/2, obj->gety() + obj->getheight(), painter);
            drawResizeKnob(obj->getx() + obj->getwidth(), obj->gety() + obj->getheight()/2, painter);
        }
    }

    if (selectedObjects.count() == 1)
    {
        Object* node = selectedObjects[0];

        if (is<PathNode*>(node) || is<ProgressPathNode*>(node))
        {
            painter->setPen(QPen(Qt::black));

            QPainterPath path1;
            path1.moveTo(node->getx(), node->gety());
            path1.quadTo(QPoint(node->getx()-14, node->gety()), QPoint(node->getx()-20, node->gety()+10));
            path1.quadTo(QPoint(node->getx()-14, node->gety()+20), QPoint(node->getx(), node->gety()+20));
            painter->fillPath(path1, QBrush(QColor(100, 100, 100, 175)));
            painter->drawPath(path1);

            QPainterPath path2;
            path2.moveTo(node->getx()+20, node->gety());
            path2.quadTo(QPoint(node->getx()+34, node->gety()), QPoint(node->getx()+40, node->gety()+10));
            path2.quadTo(QPoint(node->getx()+34, node->gety()+20), QPoint(node->getx()+20, node->gety()+20));
            painter->fillPath(path2, QBrush(QColor(100, 100, 100, 175)));
            painter->drawPath(path2);

            drawPlus(painter, node->getx()-18, node->gety());
            drawPlus(painter, node->getx()+18, node->gety());
        }
    }

    if (selectionMode)
    {
        QRect selArea(qMin(dx, lx), qMin(dy, ly), qAbs(lx-dx), qAbs(ly-dy));
        painter->setPen(QPen(QColor(0,80,180), 0.5));
        painter->fillRect(selArea, QColor(160,222,255,50));
        painter->drawRect(selArea);
    }
}

void ObjectsEditonMode::drawPlus(QPainter *painter, int x, int y)
{
    QPainterPath path1;
    path1.addRoundedRect(x+9, y+4, 2, 12 , 2.0, 2.0);
    painter->fillPath(path1, Qt::white);
    QPainterPath path2;
    path2.addRoundedRect(x+4, y+9, 12, 2 , 2.0, 2.0);
    painter->fillPath(path2, Qt::white);
}

void ObjectsEditonMode::drawResizeKnob(int x, int y, QPainter *painter)
{
    painter->fillRect(x-2, y-2, 4, 4, QBrush(Qt::white));
}

QList<Object*> ObjectsEditonMode::getObjectsAtPos(int x1, int y1, int x2, int y2, bool firstOnly)
{
    QList<Object*> objects;

    if (x1>x2)
    {
        int tmp = x1;
        x1 = x2;
        x2 = tmp;
    }

    if (y1>y2)
    {
        int tmp = y1;
        y1 = y2;
        y2 = tmp;
    }

    QRect area = QRect(QPoint(x1, y1), QPoint(x2, y2));

    for (int l = 1; l >= 0; l--) foreach (BgdatObject* bgdat, level->objects[l]) if (bgdat->clickDetection(area)) objects.append(bgdat);
    foreach (Location* loc, level->locations) if (loc->clickDetection(area)) objects.append(loc);
    foreach (Sprite* spr, level->sprites) if (spr->clickDetection(area)) objects.append(spr);
    foreach (Entrance* entr, level->entrances) if (entr->clickDetection(area)) objects.append(entr);
    foreach (Path* path, level->paths) foreach (PathNode* node, path->getNodes()) if (node->clickDetection(area)) objects.append(node);
    foreach (ProgressPath* path, level->progressPaths) foreach (ProgressPathNode* node, path->getNodes()) if (node->clickDetection(area)) objects.append(node);
    foreach (Zone* zone, level->zones) if (zone->clickDetection(area)) objects.append(zone);

    if (firstOnly && objects.size() > 1)
    {
        Object* object = objects[objects.size()-1];
        objects.clear();
        objects.append(object);
    }


    return objects;
}

QList<Object*> ObjectsEditonMode::cloneObjects(QList<Object *> objects)
{
    QList<Object*> newObjects;
    foreach (Object* o, objects)
    {
        if (is<BgdatObject*>(o)) newObjects.append(new BgdatObject(dynamic_cast<BgdatObject*>(o)));
        if (is<Sprite*>(o)) newObjects.append(new Sprite(dynamic_cast<Sprite*>(o)));
        if (is<Entrance*>(o)) newObjects.append(new Entrance(dynamic_cast<Entrance*>(o)));
        if (is<Location*>(o)) newObjects.append(new Location(dynamic_cast<Location*>(o)));
        if (is<Zone*>(o)) newObjects.append(new Zone(dynamic_cast<Zone*>(o)));
    }
    return newObjects;
}

ObjectsEditonMode::mouseAction ObjectsEditonMode::getActionAtPos(int x, int y)
{
    mouseAction act;

    if (selectedObjects.size() == 1)
    {
        Object* node = selectedObjects[0];

        if (is<PathNode*>(node) || is<ProgressPathNode*>(node))
        {
            if (QRect(node->getx()-20, node->gety(), 20, 20).contains(x, y))
                act.pAdd = AddBefore;
            else if (QRect(node->getx()+20, node->gety(), 20, 20).contains(x, y))
                act.pAdd = AddAfter;

            if (act.pAdd != AddNone)
                return act;
        }
    }

    for (int i = selectedObjects.size()-1; i >= 0; i--)
    {
        Object* o = selectedObjects[i];

        if (o->isResizable())
        {
            act.drag = true;

            if (x >= o->getx() - 8 && x <= o->getx() + 4)
                act.hor = ResizeBegin;
            else if (x >= o->getx() + o->getwidth() - 4 && x <= o->getx() + o->getwidth() + 8)
                act.hor = ResizeEnd;
            else if (x >= o->getx() && x <= o->getx() + o->getwidth())
                act.hor = ResizeNone;
            else act.drag = false;

            if (y >= o->gety() - 8 && y <= o->gety() + 4)
                act.vert = ResizeBegin;
            else if (y >= o->gety() + o->getheight() - 4 && y <= o->gety() + o->getheight() + 8)
                act.vert = ResizeEnd;
            else if (y >= o->gety() && y <= o->gety() + o->getheight())
                act.vert = ResizeNone;
            else act.drag = false;

            if (act.hor == ResizeNone && act.vert == ResizeNone && is<Zone*>(o) && !dynamic_cast<Zone*>(o)->clickDetection(x, y))
                act.drag = false;
        }
        else
        {
            act.hor = ResizeNone;
            act.vert = ResizeNone;

            act.drag = false;
            if (x >= o->getx() + o->getOffsetX() && x < o->getx() + o->getOffsetX() + o->getwidth() && y >= o->gety() + o->getOffsetY() && y < o->gety() + o->getOffsetY() + o->getheight())
                act.drag = true;
        }

        if (act.drag) return act;
    }

    return act;
}

Qt::CursorShape ObjectsEditonMode::getCursorAtPos(int x, int y)
{
    mouseAction act = getActionAtPos(x, y);

    if (!act.drag) return Qt::ArrowCursor;

    if (act.vert == ResizeBegin && act.hor == ResizeBegin) return Qt::SizeFDiagCursor;
    if (act.vert == ResizeEnd && act.hor == ResizeEnd) return Qt::SizeFDiagCursor;
    if (act.vert == ResizeBegin && act.hor == ResizeEnd) return Qt::SizeBDiagCursor;
    if (act.vert == ResizeEnd && act.hor == ResizeBegin) return Qt::SizeBDiagCursor;
    if (act.vert == ResizeNone && act.hor == ResizeNone) return Qt::SizeAllCursor;
    if (act.vert == ResizeNone) return Qt::SizeHorCursor;
    if (act.hor == ResizeNone) return Qt::SizeVerCursor;

    return Qt::ArrowCursor;
}

void ObjectsEditonMode::updateSelectionBounds()
{
    minBoundX = 2147483647;
    minBoundY = 2147483647;
    maxBoundX = 0;
    maxBoundY = 0;
    minSizeX = 2147483647;
    minSizeY = 2147483647;
    selectionHasBGDats = false;

    foreach (Object* o, selectedObjects)
    {
        if (o->getx() < minBoundX) minBoundX = o->getx();
        if (o->gety() < minBoundY) minBoundY = o->gety();
        if (o->getx() + o->getwidth() > maxBoundX) maxBoundX = o->getx() + o->getwidth();
        if (o->gety() + o->getheight() > maxBoundY) maxBoundY = o->gety() + o->getheight();

        if (o->isResizable())
        {
            if (is<Zone*>(o))
            {
                if (o->getwidth() - 400 < minSizeX) minSizeX = o->getwidth() - 400;
                if (o->getheight() - 240 < minSizeY) minSizeY = o->getheight() - 240;
            }
            else
            {
                if (o->getwidth() < minSizeX) minSizeX = o->getwidth();
                if (o->getheight() < minSizeY) minSizeY = o->getheight();
            }
        }

        if (is<BgdatObject*>(o))
            selectionHasBGDats = true;
    }
}

void ObjectsEditonMode::sortSelection()
{
    QList<Object*> sortedObjects;

    for (int i=0; i<2; i++) foreach (BgdatObject* bgdat, level->objects[i]) if (selectedObjects.contains(bgdat)) sortedObjects.append(bgdat);
    foreach (Sprite* spr, level->sprites) if (selectedObjects.contains(spr)) sortedObjects.append(spr);
    foreach (Entrance* entr, level->entrances) if (selectedObjects.contains(entr)) sortedObjects.append(entr);
    foreach (Location* loc, level->locations) if (selectedObjects.contains(loc)) sortedObjects.append(loc);
    foreach (Zone* zone, level->zones) if (selectedObjects.contains(zone)) sortedObjects.append(zone);

    selectedObjects = sortedObjects;
}

void ObjectsEditonMode::select(Object *obj)
{
    selectedObjects.clear();
    selectedObjects.append(obj);
}

void ObjectsEditonMode::deleteSelection()
{
    level->remove(selectedObjects);
    selectedObjects.clear();
    actualCursor = Qt::ArrowCursor;
    mouseAction act;
    mouseAct = act;
    checkEmits();
    updateEditors();
}

void ObjectsEditonMode::copy()
{
    if (selectedObjects.size() == 0)
        return;

    int minX = 0x7FFFFFFF;
    int maxX = 0;
    int minY = 0x7FFFFFFF;
    int maxY = 0;

    foreach (Object* obj, selectedObjects)
    {
        if (obj->toString(0,0) == "")
            continue;

        if (obj->getx()+obj->getOffsetX() < minX) minX = obj->getx()+obj->getOffsetX();
        if (obj->gety()+obj->getOffsetY() < minY) minY = obj->gety()+obj->getOffsetY();
        if (obj->getx()+obj->getOffsetX()+obj->getwidth() > maxX) maxX = obj->getx()+obj->getOffsetX()+obj->getwidth();
        if (obj->gety()+obj->getOffsetY()+obj->getheight() > maxY) maxY = obj->gety()+obj->getOffsetY()+obj->getheight();
    }

    QString clipboardText = QString("CoinKillerClip|%1:%2").arg(maxX-minX).arg(maxY-minY);

    foreach (Object* obj, selectedObjects)
    {
        QString nextText = obj->toString(-minX, -minY);
        if (nextText != "") clipboardText.append("|" + nextText);
    }

    QApplication::clipboard()->setText(clipboardText);
}

void ObjectsEditonMode::cut()
{
    copy();
    deleteSelection();
}

void ObjectsEditonMode::paste(int currX, int currY, int currW, int currH)
{
    QStringList sections = QApplication::clipboard()->text().split('|');

    if (sections.size() < 2)
        return;

    if (sections[0] != "CoinKillerClip")
        return;

    QStringList pasteSizes = sections[1].split(':');
    int pOffsetX = qMax(toNext20(currX + currW/2 - pasteSizes[0].toInt()/2), 0);
    int pOffsetY = qMax(toNext20(currY + currH/2 - pasteSizes[1].toInt()/2), 0);

    selectedObjects.clear();

    for (int i = 2; i < sections.size(); i++)
    {
        QStringList params = sections[i].split(':');

        switch (params[0].toInt())
        {
            case 0: // BG dat
            {
                BgdatObject* newObj = new BgdatObject(params[3].toInt()+pOffsetX, params[4].toInt()+pOffsetY, params[5].toInt(), params[6].toInt(), params[1].toInt(), params[2].toInt());
                level->objects[newObj->getLayer()].append(newObj);
                selectedObjects.append(newObj);
                break;
            }
            case 1: // Sprite
            {
                Sprite* newSpr = new Sprite(params[2].toInt()+pOffsetX, params[3].toInt()+pOffsetY, params[1].toInt());
                for (int i=0; i<12; i++) newSpr->setByte(i, params[i+4].toUInt());
                newSpr->setRect();
                level->sprites.append(newSpr);
                selectedObjects.append(newSpr);
                break;
            }
            case 2: // Entrance
            {
                Entrance* newEntr = new Entrance(params[3].toInt()+pOffsetX, params[4].toInt()+pOffsetY, params[7].toInt(), params[8].toInt(), params[1].toInt(), params[5].toInt(), params[6].toInt(), params[2].toInt(), params[9].toInt(), 0, 0);
                level->entrances.append(newEntr);
                selectedObjects.append(newEntr);
                break;
            }
            case 4: // Location
            {
                Location* newLoc = new Location(params[2].toInt()+pOffsetX, params[3].toInt()+pOffsetY, params[4].toInt(), params[5].toInt(), params[1].toInt());
                level->locations.append(newLoc);
                selectedObjects.append(newLoc);
                break;
            }
            default: { break; }
        }
    }

    emit updateEditors();
    checkEmits();
}

void ObjectsEditonMode::raise()
{
    sortSelection();
    foreach (Object* obj, selectedObjects)
    {
        level->raise(obj);
    }
}

void ObjectsEditonMode::lower()
{
    sortSelection();
    foreach (Object* obj, selectedObjects)
    {
        level->lower(obj);
    }
}

void ObjectsEditonMode::raiseLayer()
{
    sortSelection();
    foreach (Object* obj, selectedObjects)
    {
        if (is<BgdatObject*>(obj)) level->raiseLayer(dynamic_cast<BgdatObject*>(obj));
    }
}

void ObjectsEditonMode::lowerLayer()
{
    sortSelection();
    foreach (Object* obj, selectedObjects)
    {
        if (is<BgdatObject*>(obj)) level->lowerLayer(dynamic_cast<BgdatObject*>(obj));
    }
}

void ObjectsEditonMode::checkEmits()
{
    if (selectedObjects.size() != 1)
        emit deselected();
    else
        emit selectdObjectChanged(selectedObjects[0]);
}
