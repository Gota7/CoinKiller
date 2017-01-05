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

#ifndef CTPK_H
#define CTPK_H

#include "filesystem.h"

#include <QImage>


class Ctpk
{
public:
    Ctpk(FileBase* file);
    ~Ctpk();

    QImage* getTexture(quint32 num);


private:
    qint32 clampColor(qint32 val)
    {
        if (val > 255) return 255;
        if (val < 0) return 0;
        return val;
    }

    FileBase* file;

    quint16 numTextures;
    quint32 texSectionOffset;
    quint32 texSectionSize;
    quint32 hashSectionOffset;
    quint32 infoSectionOffset;
};

#endif // CTPK_H
