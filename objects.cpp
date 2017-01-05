/*
    Copyright 2015 StapleButter

    This file is part of CoinKiller.

    CoinKiller is free software: you can redistribute it and/or modify it under
    the terms of the GNU General Public License as published by the Free
    Software Foundation, either version 3 of the License, or (at your option)
    any later version.

    CoinKiller is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
    You should have received a copy of the GNU General Public License along
    with CoinKiller. If not, see http://www.gnu.org/licenses/.
*/

#include "objects.h"
#include "unitsconvert.h"

#include <QPainter>

Object::Object()
{
    x = 0;
    y = 0;
    width = 20;
    height = 20;
    offsetx = 0;
    offsety = 0;
}

void Object::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Object::increasePosition(int deltax, int deltay, int snap)
{
    this->x += deltax;
    this->y += deltay;

    if (snap == 10)
    {
        x = toNext10(x);
        y = toNext10(y);
    }
}

void Object::resize(int width, int height)
{
    this->width = width;
    this->height = height;
}

void Object::increaseSize(int deltax, int deltay, int snap)
{
    this->width += deltax;
    this->height += deltay;

    if (snap == 10)
    {
        width = toNext10(width + x) - x;
        height = toNext10(height + y) - y;
    }
}

bool Object::clickDetection(int xcheck, int ycheck)
{
    return QRect(x+offsetx,y+offsety,width,height).contains(xcheck, ycheck);
}

bool Object::clickDetection(QRect rect)
{
    return rect.intersects(QRect(x+offsetx,y+offsety,width,height));
}

QString Object::toString(int, int) const { return QString(""); }


// BgdatObject
BgdatObject::BgdatObject(int x, int y, int width, int height, int id, int layer)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->id = id;
    this->layer = layer;
}

BgdatObject::BgdatObject(BgdatObject *obj)
{
    x = obj->getx();
    y = obj->gety();
    width = obj->getwidth();
    height = obj->getheight();
    id = obj->getid();
    layer = obj->getLayer();

}

int BgdatObject::getType() const { return 0; }
int BgdatObject::getid() const { return id; }
int BgdatObject::getLayer() const { return layer; }

void BgdatObject::setTsID(int tsID)
{
    id = (id & 0xFFF) | (tsID << 12);
}

void BgdatObject::setObjID(int objID)
{
    id = (id & 0xF000) | objID;
}

// Format: 0:ID:Layer:X:Y:Width:Height
QString BgdatObject::toString(int xOffset, int yOffset) const { return QString("0:%1:%2:%3:%4:%5:%6").arg(id).arg(layer).arg(x+xOffset).arg(y+yOffset).arg(width).arg(height); }


// Sprite
Sprite::Sprite(int x, int y, int id)
{
    this->x = x;
    this->y = y;
    this->id = id;
}

Sprite::Sprite(Sprite *spr)
{
    x = spr->getx();
    y = spr->gety();
    id = spr->getid();
    for (int i = 0; i < 12; i++) spriteData[i] = spr->getByte(i);
    setRect();
}

void Sprite::setRect()
{
    width = 20;
    height = 20;
    offsetx = 0;
    offsety = 0;
    switch (id) {
    case 0: // Autoscroll
        width = 20;
        height = 20;
        break;
        case 1: // Pipe Boobles
            width = 48;
            height = 79;
            offsetx = -4;
            offsety = -79;
            break;
    case 2: // Booble
        width = 20;
        height = 20;
        break;
    case 3: // Cheep Chomp
        width = 79;
        height = 67;
        offsetx = -31;
        offsety = -26;
        break;
    case 4: // Burner Right
        width = 135;
        height = 20;
        break;
    case 5: // Burner Down
        width = 20;
        height = 140;
        break;
    case 6: // Burner Left
        width = 135;
        height = 20;
        offsetx = -115;
        break;
    case 7: // Burner Up
        width = 20;
        height = 140;
        offsety = -120;
        break;
    case 8: // Swoop
        width = 13;
        height = 22;
        offsetx = 3;
        break;
    case 9: // Whomp
        width = 75;
        height = 57;
        offsetx = -18;
        offsety = 3;
        break;
    case 10: // Lemmy Conveyor
        width = 280;
        height = 20;
        break;
    case 18: // Tile God
        width = qMax(getNybble(15) * 20, 20);
        height = qMax(getNybble(13) * 20, 20);
        break;
    case 19: // Desert Crater
        width = 65;
        height = 18;
        offsetx = -22;
        offsety = 19;
        break;
    case 22: // Special Exit Controller
        width = qMax(getNybble(7) * 20, 20);
        height = qMax(getNybble(4) * 20, 20);
        break;
    case 23: // Hidden Block Reggiesaurus
        width = 20;
        height = 20;
        break;
    case 29: // Bob-omb
        width = 29;
        height = 29;
        offsetx = -5;
        offsety = -8;
        break;
    case 31: case 32: case 33: // Boomerang/Fire/Hammer Bro.
        width = 27;
        height = 47;
        offsetx = -5;
        offsety = -13;
        break;
    case 34: // Sledge Bro
        width = 39;
        height = 54;
        offsety = 5;
        break;
    case 35: // Lava Bubble
        width = 20;
        height = 21;
        offsety = 10;
        break;
    case 38: // Reznor Wheel
        width = 190;
        height = 199;
        offsetx = -85;
        offsety = -99.5;
        break;
    case 39: // Reznor Platform
        width = /*getNybble(4) * */20;
        height = 20;
        break;
    case 49: // Chain
        width = 8;
        height = 114;
        offsetx = 6;
        offsety = 80;
        break;
    case 50: // Chain Controller
        width = 20;
        height = 20;
        break;
    case 52: // Checkpoint Flag
        width = 37;
        height = 65;
        offsetx = 1;
        offsety = -25;
        break;
    case 56: // Bubble Coin
        width = 30;
        height = 32;
        offsetx = -5;
        offsety = -6;
        break;
    case 57: // Coin Eruption
        width = 60;
        height = 60;
        offsetx = -20;
        offsety = -40;
        break;
    case 59: // Rotation Controlled Coin
        width = 20;
        height = 20;
        break;
    case 60: // Movement Controlled Coin
        width = 20;
        height = 20;
        break;
    case 61: // Red Coin
        width = 18;
        height = 20;
        break;
    case 62: // Rotating Red Coin
        width = 18;
        height = 20;
        break;
    case 63: // Left Skewer
        width = 557;
        height = 82;
        offsetx = -278;
        break;
    case 64: // Right Skewer
        width = 557;
        height = 82;
        offsetx = -260;
        break;
        case 65: // Respawn Pipe
            width = 80;
            height = 20;
            offsetx = -40;
            offsety = 10;
            break;
    case 66: case 67: // Pipe Cannons
        width = 40;
        height = 80;
        break;
    case 69: // Door
        width = 43;
        height = 60;
        break;
    case 70: // Castle Boss Door
        width = 66;
        height = 75;
        offsetx = -3;
        offsety = 5;
        break;
    case 71: // Closed Door
        width = 40;
        height = 60;
        break;
    case 72: // Final Boss Door
        width = 144;
        height = 144;
        offsety = -45;
        break;
    case 73: // Ghost House Door
        width = 41;
        height = 60;
        offsety = -1;
        break;
    case 74: // Flag Door
        width = 43;
        height = 60;
        break;
    case 75: // Tower Boss Door
        width = 65;
        height = 75;
        offsetx = -2;
        offsety = 5;
        break;
    case 76: // Big Thwomp
        width = 102;
        height = 114;
        offsetx = -11;
        offsety = -3;
        break;
    case 77: // Thwomp
        width = 54;
        height = 59;
        offsetx = -7;
        offsety = -2;
        break;
    case 81: // Fireball Pipe - ! Junction
        width = 40;
        height = 40;
        break;
    case 83: // Fish Bone
        width = 33;
        height = 21;
        offsetx = -4;
        break;
    case 91: // Coin Coffer
        width = 33;
        height = 32;
        offsety = -10;
        break;
    case 92: // Grinder
        width = 49;
        height = 49;
        offsetx = -6;
        offsety = -6;
        break;
    case 93: // Scuttlebug
        width = 52;
        height = 49;
        offsetx = -18;
        offsety = -21;
        break;
    case 94: // Flipper (One way gate)
       if (getNybble(5) == 1 || getNybble(5) == 0) //Left Down + Right Down
       {
            width = 20;
            height = 66;
            offsety = -45;
       }
       else if (getNybble(5) == 2 || getNybble(5) == 3) //Right Up + Left Up
       {
            width = 20;
            height = 66;
       }
       else if (getNybble(5) == 4 || getNybble(5) == 5) //Up Left + Down Left
       {
            width = 62;
            height = 20;
       }
       else //Up Right + Down Right
       {
            width = 62;
            height = 20;
            offsetx = -42;
       }
        break;
    case 95: // Blooper
        width = 28;
        height = 36;
        offsetx = -4;
        offsety = -9;
        break;
    case 97: // End of Level Flag
        width = 62;
        height = 200;
        offsetx = -22;
        break;
    case 99: // Wiggler
        width = 89;
        height = 41;
        offsety = -20;
        break;
    case 102: // Iggy
        width = 71;
        height = 71;
        offsety = 90;
        break;
    case 108: // Spider Web
        width = 80;
        height = 80;
        break;
    case 109: // Signboard
        width = 40;
        height = 40;
        break;
    case 110: // Dry Bones
        width = 28;
        height = 36;
        offsetx = -6;
        offsety = -15;
        break;
    case 111: // Giant Dry Bones
        width = 41;
        height = 55;
        offsetx = -8;
        offsety = 7;
        break;
    case 114: // Floating Box
        if (getNybble(5) == 1) // Big
        {
            width = 122;
            height = 121;
            offsetx = -31;
            offsety = 2;
        }
        else
        {
            width = 62;
            height = 61;
            offsetx = -1;
            offsety = 3;
        }
        break;
    case 115: // Bullet Bill Launcher
        width = 20;
        height = (2 + getNybble(4)) * 20;
        if (getNybble(10) == 0)
            offsety = -height+20;
        break;
    case 117: // Banzai Bill Launcher
        width = 80;
        height = 103;
        offsety = -3;
        break;
    case 124: // Mushroom Platform
        width = getNybble(6)*20 + 68;
        height = 20;
        offsetx = -(width / 2);
        break;
    case 125: // Bowser
        width = 138;
        height = 108;
        offsetx = -58;
        offsety = -87;
        break;
    case 128: // Bowser
        width = 136;
        height = 103;
        offsetx = -58;
        offsety = -87;
        break;
    case 129: // Big Dry Bowser
        width = 360;
        height = 203;
        offsetx = -160;
        //Offset Y makes it make sense.
        offsety = -320;
        break;
    case 130: // Big Bowser
        width = 340;
        height = 200;
        offsetx = -150;
        //Offset Y makes it make sense.
        offsety = -320;
        break;
    case 135: // Goomba
        width = 21;
        height = 24;
        offsetx = -1;
        offsety = -4;
        break;
    case 136: // Bone Goomba
        if (getNybble(14) != 1)
        {
            width = 22;
            height = 24;
            offsetx = -2;
            offsety = -4;
        }
        else
        {
            width = 24;
            height = 28;
            offsetx = -2;
            offsety = -8;
        }
        break;
    case 137: // Micro Goomba
        width = 11;
        height = 13;
        offsetx = 4;
        offsety = 8;
        break;
    case 138: // Paragoomba
        width = 25;
        height = 33;
        offsetx = -1;
        offsety = -12;
        break;
    case 139: // Goomba Tower
        width = 21;
        height = getNybble(5) * 21 + 4;
        offsety = - height + 21 + 1;
        break;
    case 140: // Crowber
        width = 31;
        height = 21;
        offsetx = -5;
        offsety = -6;
        break;
    case 141: // Larry
        width = 38;
        height = 67;
        offsety = 63;
        break;
    case 142: // LEMMAYYY!!!
        width = 63;
        height = 81;
        offsety = -63;
        offsetx = -20;
        break;
    case 143: // 	Conveyor Belt Switch
        width = 28;
        height = 42;
        offsetx = -4;
        offsety = -21;
        break;
    case 147: // 3 plat rickshaw
        if (getNybble(5) != 1)
        {
            width = 128;
            height = 89;
            offsetx = -60;
            offsety = -60;
        }
        else
        {
            width = 182;
            height = 121;
            offsetx = -90;
            offsety = -80;
        }
        break;
    case 148: //move While On Lift
        width = 249;
        height = 34;
        offsetx = -6;
        offsety = -6;
        break;
    case 150: // Seesaw Lift
        width = 280;
        height = 20;
        offsetx= 20;
        break;
    case 153: // Platform Generator
        width = 85;
        height = 21;
        offsetx = 0;
        break;
    case 154: // 4 plat rickshaw
        if (getNybble(5) == 1)
        {
            width = 116;
            height = 90;
            offsetx = -48;
            offsety = -34;
        }
        else
        {
            width = 174;
            height = 130;
            offsetx = -40;
            offsety = -54;
        }
        break;
    case 155: // Ludwig Von Poopa
        width = 38;
        height = 54;
        offsetx = -19;
        offsety = -35;
        break;
    case 162: // Morton
        width = 67;
        height = 61;
        offsetx = -33.5;
        offsety = -30;
        break;
    case 165: // Koopa Troopa
        width = 27;
        height = 35;
        offsetx = -5;
        offsety = -15;
        break;
    case 167: // Pipe Piranha Plant - Down
        width = 30;
        height = 37;
        offsetx = 5;
        offsety = 40;
        break;
    case 172: // Pipe Bone Piranha Plant - Up
        width = 30;
        height = 34;
        offsetx = 5;
        offsety = -35;
        break;
    case 173: // Pipe Bone Piranha Plant - Left
        width = 34;
        height = 30;
        offsetx = -35;
        offsety = 5;
        break;
    case 174: // Pipe Bone Piranha Plant - Right
        width = 34;
        height = 30;
        offsetx = 40;
        offsety = 5;
        break;
    case 175: // Grounded Piranha Plant
        width = 54;
        height = 33;
        offsetx = -8;
        break;
    case 176: // Big Grounded Piranha plant
        if (getNybble(5) != 1)
        {
            width = 110;
            height = 65;
            offsetx = -25;
            offsety = 16;
        }
        else
        {
            width = 110;
            height = 65;
            offsetx = -25;
            offsety = 60;
        }
        break;
    case 179: // Grounded Bone Piranha Plant
        width = 53;
        height = 33;
        offsetx = -8;
        offsety = 8;
        break;
    case 180: // Big Grounded Bone Piranha plant
        if (getNybble(5) != 1)
        {
            width = 110;
            height = 68;
            offsetx = -25;
            offsety = 14;
        }
        else
        {
            width = 110;
            height = 68;
            offsetx = -25;
            offsety = 58;
        }
        break;
    case 181: // Pipe Piranha Plant - Left
        width = 37;
        height = 30;
        offsetx = -37;
        offsety = 5;
        break;
    case 182: // Pipe Piranha Plant - Right
        width = 37;
        height = 30;
        offsetx = 40;
        offsety = 5;
        break;
    case 183: // Pipe Piranha Plant - Up
        width = 30;
        height = 37;
        offsetx = 5;
        offsety = -37;
        break;
    case 184: // Parabomb
        width = 29;
        height = 38;
        offsetx = -5;
        offsety = -18;
        break;
    case 185: // Koopa Paratroopa
        width = 32;
        height = 36;
        offsetx = -7;
        offsety = -15;
        break;
    case 186: // Koopa Paratroopa Generator
        width = 32;
        height = 36;
        offsetx = -7;
        offsety = -15;
        break;
    case 189: case 190: case 191: case 192: case 193: // Rect Blocks
        width = getNybble(15)*20+20;
        if (width == 20) width = 40;
        height = getNybble(13)*20+20;
        if (height == 20) height = 40;
        if (getNybble(9) == 1 || getNybble(9) == 3) { height += 20; offsety-=20; }
        if (getNybble(9) == 2 || getNybble(9) == 3) height += 20;
        if (getNybble(9) == 4 || getNybble(9) == 6) { width += 20; offsetx-=20; }
        if (getNybble(9) == 5 || getNybble(9) == 6) width += 20;
        if (id == 192)
        {
            width += 6;
            offsetx -= 3;
        }
        break;
    case 194: // Cheep Cheep
        width = 22;
        height = 21;
        offsety = -3;
        break;
    case 195: // Big Cheep Cheep
        width = 60;
        height = 56;
        offsety = -5;
        break;
    case 200: // Spiny Cheep Cheep
        width = 20;
        height = 26;
        offsety = -6;
        break;
    case 205: // Red Ring
        width = 39;
        height = 56;
        offsety = 2;
        break;
    case 206: // Gold Ring
        width = 40;
        height = 56;
        offsety = 2;
        break;
    case 211: // Roy Koopa
        width = 78;
        height = 47;
        offsetx = -46;
        offsety = -27;
        break;
    case 212: // Roy Koopa's Dick
        width = 41;
        height = 200;
        if (getNybble(5) == 1) {offsetx = 20;} else {offsetx = -41;}
        break;
    case 213: // Pokey
        width = 36;
        height = getNybble(5) * 24 + 13;
        offsety = - height + 24 + 1;
        break;
    case 215: // Bob-omb Cannon
        width = 31;
        height = 32;
        if (getNybble(5) != 1) offsetx = -1;
        else offsetx = -10;
        offsety = -12;
        break;
    case 216: // Boss Shutter
        width = 34;
        height = 60;
        offsety = 20;
        offsetx = 3;
        break;
    case 219: // Star Coin
        width = 40;
        height = 40;
        break;
    case 221: // ! Switch
        width = 22;
        height = 24;
        offsetx = -1;
        if (getNybble(5) != 1) offsety = -4;
        break;
    case 223: // ? Switch
        width = 22;
        height = 24;
        offsetx = -1;
        if (getNybble(5) != 1) offsety = -4;
        break;
    case 225: // P Switch
        width = 22;
        height = 24;
        offsetx = -1;
        if (getNybble(5) != 1) offsety = -4;
        break;
    case 228: // Boo
        width = 45;
        height = 44;
        offsetx = -12;
        offsety = 5;
        break;
    case 229: //Big Boo
        width = 132;
        height = 132;
        offsetx = -16;
        offsety = 15;
        break;
    case 231: // Boohemoth
        width = 234;
        height = 234;
        //Makes sure boo is shown between zone lines.
        offsety = -40;
        break;
    case 234: // Spiked Ball
        width = 38;
        height = 38;
        offsetx = 1;
        offsety = 1;
        break;
    case 235: // Big Spiked Ball
        width = 76;
        height = 76;
        offsetx = 12;
        offsety = 2;
        break;
    case 236: // Mega Spiked Ball
        width = 154;
        height = 154;
        offsetx = -23;
        offsety = -7;
        break;
    case 240: // Urchin
        if (getNybble(5) != 1)
        {
            width = 26;
            height = 26;
            offsetx = -3;
            offsety = -3;
        }
        else
        {
            width = 51;
            height = 48;
            offsetx = -5;
            offsety = -4;
        }
        break;
    case 244: // Chain Chomp
        width = 63;
        height = 63;
        offsetx = -41;
        break;
    case 245: // Wendy
        width = 51;
        height = 52;
        offsetx = -25.5;
        offsety = -31;
        break;
    case 246: // Wendy Water
        width = 440;
        height = 22;
        offsetx = -20;
        break;
    case 247: // Invisible Trampoline Block
        width = 20;
        height = 20;
       break;
    case 251: // Treasure Chest
        width = 48;
        height = 32;
        offsetx = -14;
        offsety = -12;
        break;
    case 253: // Larry Koopa Floor Stage Platform Thing
        if (getNybble(10)==3) {width = 60;} else {width = 80;}
        height = 10;
        break;
    case 255: // Bowser Head Statue
        width = 40;
        height = 42;
        offsetx = -18;
        offsety = -1;
        break;
    case 257: // Spine Coaster
        width = 326;
        height = 84;
        break;
    case 266: // Flash Koopalings
        width = 117;
        height = 154;
        break;
    case 267: case 275: case 276: // Long Question Blocks
        width = 60;
        height = 20;
        break;
    case 269: // Gold Ship
        width = 285;
        height = 96;
        break;
    case 270: // Icy Spiked Ball
        width = 38;
        height = 38;
        offsetx = 1;
        offsety = 1;
        break;
    case 272: // Peach Cage
        width = 70;
        height = 131;
        break;
    case 273: // Coin Roulette Block
        width = 31;
        height = 30;
        offsetx = -5;
        offsety = -5;
        break;
    case 274: // Flying Gold Block Spawn Point
        width = 28;
        height = 23;
        offsetx = -4;
        offsety = -1;
        break;
    case 277: // Switchable Conveyor Belt
        width = 160;
        break;
    case 278: // Assist Block
        width = 26;
        height = 26;
        offsetx = -3;
        offsety = -5;
        break;
    case 279: // Lemmy Ball
        width = 30;
        height = 30;
        offsetx = -3;
        offsety = -15;
        break;
    case 280: // + Clock
        width = 22;
        height = 26;
        offsetx = -3;
        offsety = -1;
        break;
    case 287: // Toad House Door
        width = 40;
        height = 60;
        break;
    case 289: // Lemmy Mushroom
        if (getNybble(15) == 0) {width = 99; offsetx = -50;} else {width = 40; offsetx = -10;}
        height = 30;
        offsety = 10;
        break;
    case 292: // Warp Cannon Signboard
        width = 65;
        height = 66;
        offsetx = -22;
        offsety = -46;
        break;
    case 293: // Punching Glove
        width = 32;
        height = 35;
        break;
    case 294: // Warp Cannon
        width = 100;
        height = 67;
        offsetx = -40;
        offsety = -27;
        break;
    case 296: // Toad
        width = 25;
        height = 39;
        offsetx = -1;
        offsety = -19;
        break;
    case 299: // Lemmy Fall Block
        width = 40;
        height = 20;
        break;
    case 300: // Clap Coin
        width = 20;
        height = 20;
        break;
    case 302: // Moon Coin
        width = 40;
        height = 40;
        break;
        break;
    case 303: // Rotato Moon Coin
        width = 40;
        height = 40;
        break;
    case 310: //Evil Internet Bowser Lifts
        width = 81;
        height = 24;
        offsetx = -40.5;
            break;
    case 311: //Coin Meteor
        width = 60;
        height = 60;
        offsetx = -30;
        offsety = -30;
        break;
    case 314: // Ruins rickshaw
        if (getNybble(5) != 1)
        {
            width = 128;
            height = 89;
            offsetx = -60;
            offsety = -60;
        }
        else
        {
            width = 166;
            height = 110;
            offsetx = -90;
            offsety = -80;
        }
        break;
    case 315: // Peach For Credits
        width = 24;
        height = 47;
        break;
    case 320: // Line Controlled Platform
        width = 304;
        height = 22;
        offsetx = -290;
        offsety = 20;
        break;
    case 322: // Big Grinder
        width = 86;
        height = 86;
        offsetx = -23;
        offsety = -23;
        break;
    case 323: // Ending Birds
        width = 37;
        height = 33;
        offsetx = -18.5;
        offsety = -16.5;
        break;
    default:
        width = 20;
        height = 20;
        offsetx = 0;
        offsety = 0;
    }
}

int Sprite::getType() const { return 1; }
int Sprite::getid() const { return id; }

quint8 Sprite::getByte(int id) const { return spriteData[id]; }
void Sprite::setByte(int id, quint8 nbr) { spriteData[id] = nbr; }

quint8 Sprite::getNybble(int id) const
{
    if (id%2 == 0) return spriteData[id/2] >> 4;
    else return spriteData[id/2] & 0xF;
}

void Sprite::setNybble(int id, quint8 nbr)
{
    if (id%2 == 0) spriteData[id/2] = ((spriteData[id/2] & 0xF) | nbr << 4);
    else spriteData[id/2] = ((spriteData[id/2] & 0xF0) | nbr);
}

int Sprite::getNybbleData(int startNybble, int endNybble)
{
    int data = 0;

    for (int i = startNybble; i <= endNybble; i++)
        data = data << 4 | getNybble(i);

    return data;
}

void Sprite::setNybbleData(int data, int startNybble, int endNybble)
{
    for (int i = endNybble; i >= startNybble; i--)
    {
        setNybble(i, (quint8)(data & 0xF));
        data = data >> 4;
    }
}

// Format: 1:ID:X:Y:SD0:SD1:...:SD11
QString Sprite::toString(int xOffset, int yOffset) const
{
    QString str("1:%1:%2:%3");
    for (int i=0; i<12; i++) str.append(QString(":%1").arg(spriteData[i]));
    return str.arg(id).arg(x+xOffset).arg(y+yOffset);
}


// Entrance
Entrance::Entrance(int x, int y, qint16 cameraX, qint16 cameraY, quint8 id, quint8 destArea, quint8 destEntr, quint8 entrType, quint8 settings, quint8 unk1, quint8 unk2)
{
    this->x = x;
    this->y = y;
    this->cameraX = cameraX;
    this->cameraY = cameraY;
    this->id = id;
    this->destArea = destArea;
    this->destEntr = destEntr;
    this->entrType = entrType;
    this->settings = settings;
    this->unk1 = unk1;
    this->unk2 = unk2;
}

Entrance::Entrance(Entrance *entr)
{
    x = entr->getx();
    y = entr->gety();
    cameraX = entr->getCameraX();
    cameraY = entr->getCameraY();
    id = entr->getid();
    destArea = entr->getDestArea();
    destEntr = entr->getDestEntr();
    entrType = entr->getEntrType();
    settings = entr->getSettings();
    unk1 = entr->getUnk1();
    unk2 = entr->getUnk2();
}

// Format: 2:ID:Type:X:Y:DestArea:DestEntr:CamX:CamY:Settings
QString Entrance::toString(int xOffset, int yOffset) const { return QString("2:%1:%2:%3:%4:%5:%6:%7:%8:%9").arg(id).arg(entrType).arg(x+xOffset).arg(y+yOffset).arg(destArea).arg(destEntr).arg(cameraX).arg(cameraY).arg(settings); }


// Zone
Zone::Zone(int x, int y, int width, int height, quint8 id, quint8 progPathId, quint8 musicId, quint8 multiplayerTracking, quint16 unk1)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->id = id;
    this->progPathId = progPathId;
    this->musicId = musicId;
    this->multiplayerTracking = multiplayerTracking;
    this->unk1 = unk1;
}

Zone::Zone(Zone *zone)
{
    x = zone->getx();
    y = zone->gety();
    width = zone->getwidth();
    height = zone->getheight();
    id = zone->getid();
    progPathId = zone->getProgPathId();
    musicId = zone->getMusicId();
    multiplayerTracking = zone->getMultiplayerTracking();
    unk1 = zone->getUnk1();
    upperBound = zone->getUpperBound();
    lowerBound = zone->getLowerBound();
    unkUpperBound = zone->getUnkUpperBound();
    unkLowerBound = zone->getUnkLowerBound();
    upScrolling = zone->getUpScrolling();
    xScrollRate = zone->getXScrollRate();
    yScrollRate = zone->getYScrollRate();
    bgXPos = zone->getBgXPos();
    bgYPos = zone->getBgYPos();
    bgName = zone->getBgName();
    bgUnk1 = zone->getBgUnk1();
}

bool Zone::clickDetection(int xcheck, int ycheck)
{
    return QRect(x,y,38,18).contains(xcheck, ycheck);
}

bool Zone::clickDetection(QRect rect)
{
    return rect.intersects(QRect(x,y,38,18));
}

void Zone::setBounding(tempZoneBounding bounding)
{
    this->upperBound = bounding.upperBound;
    this->lowerBound = bounding.lowerBound;
    this->unkUpperBound = bounding.unkUpperBound;
    this->unkLowerBound = bounding.unkLowerBound;
    this->upScrolling = bounding.upScrolling;
}

void Zone::setBackground(tempZoneBackground background)
{
    this->xScrollRate = background.xScrollRate;
    this->yScrollRate = background.yScrollRate;
    this->bgXPos = background.xPos;
    this->bgYPos = background.yPos;
    this->bgName = background.name;
    this->bgUnk1 = background.unk1;
}


// Location
Location::Location(int x, int y, int width, int height, int id)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->id = id;
}

Location::Location(Location *loc)
{
    x = loc->getx();
    y = loc->gety();
    width = loc->getwidth();
    height = loc->getheight();
    id = loc->getid();
}

int Location::getType() const { return 4; }
int Location::getid() const { return id; }

// Format: 4:ID:X:Y:Width:Height
QString Location::toString(int xOffset, int yOffset) const { return QString("4:%1:%2:%3:%4:%5").arg(id).arg(x+xOffset).arg(y+yOffset).arg(width).arg(height); }


// Path
Path::Path(quint16 id, quint16 unk1)
{
    this->id = id;
    this->unk1 = unk1;
}

Path::Path(Path *path)
{
    id = path->getid();
    unk1 = path->getUnk1();
    foreach (PathNode* node, path->getNodes())
        nodes.append(new PathNode(node, this));
}

void Path::insertNode(PathNode* node, int index)
{
    if (index == -1)
        nodes.append(node);
    else
        nodes.insert(index, node);
}

void Path::removeNode(PathNode *node)
{
    nodes.removeOne(node);
}

QList<PathNode*> Path::getNodes() const { return nodes; }

// Path Node
PathNode::PathNode(int x, int y, float speed, float accel, quint32 unk1, Path* parentPath)
{
    this->x = x;
    this->y = y;
    this->speed = speed;
    this->accel = accel;
    this->unk1 = unk1;
    this->parentPath = parentPath;
}

PathNode::PathNode(PathNode *node, Path* parentPath)
{
    x = node->getx();
    y = node->gety();
    speed = node->getSpeed();
    accel = node->getAccel();
    unk1 = node->getUnk1();
    this->parentPath = parentPath;
}

// Progress Path
ProgressPath::ProgressPath(quint16 id, quint8 alternatePathFlag)
{
    this->id = id;
    this->alternatePathFlag = alternatePathFlag;
}

ProgressPath::ProgressPath(ProgressPath *path)
{
    id = path->getid();
    alternatePathFlag = path->getAlternatePathFlag();
    foreach (ProgressPathNode* node, path->getNodes())
        nodes.append(new ProgressPathNode(node, this));
}

void ProgressPath::insertNode(ProgressPathNode* node, int index)
{
    if (index == -1)
        nodes.append(node);
    else
        nodes.insert(index, node);
}

void ProgressPath::removeNode(ProgressPathNode *node)
{
    nodes.removeOne(node);
}

QList<ProgressPathNode*> ProgressPath::getNodes() const { return nodes; }

// Progress Path Node
ProgressPathNode::ProgressPathNode(int x, int y, ProgressPath *parentPath)
{
    this->x = x;
    this->y = y;
    this->parentPath = parentPath;
}

ProgressPathNode::ProgressPathNode(ProgressPathNode *node, ProgressPath *parentPath)
{
    x = node->getx();
    y = node->gety();
    this->parentPath = parentPath;
}
