#ifndef OBJECTRENDERER_H
#define OBJECTRENDERER_H

#include "objects.h"

#include <QPainter>

class ObjectRenderer
{
public:
    ObjectRenderer() {}
    ObjectRenderer(Object *) {}
    virtual ~ObjectRenderer() {}
    virtual void render(QPainter *) {}
};

class SpriteRenderer: public ObjectRenderer
{
public:
    SpriteRenderer() {}
    SpriteRenderer(const Sprite *spr);
    void render(QPainter *painter);
protected:
    const Sprite *spr;
    ObjectRenderer *ret;
};

class NormalImageRenderer: public ObjectRenderer
{
public:
    NormalImageRenderer(const Object *obj, QString filename);
    NormalImageRenderer(QRect rect, QString filename);
    void render(QPainter *painter);
protected:
    QRect rect;
    QString filename;
};

class RoundedRectRenderer: public ObjectRenderer
{
public:
    RoundedRectRenderer();
    RoundedRectRenderer(const Object *obj, QString text, QColor color, QTextOption align = Qt::AlignHCenter | Qt::AlignVCenter);
    void render(QPainter *painter);
protected:
    const Object *obj;
    QString text;
    QColor color;
    QTextOption align;
};


// Special Sprite Renderers

// Lava
class LavaRenderer: public SpriteRenderer
{
public:
    LavaRenderer(const Sprite *spr);
    void render(QPainter *painter);
protected:
    const Sprite *spr;
};

// Poison
class PoisonRenderer: public SpriteRenderer
{
public:
    PoisonRenderer(const Sprite *spr);
    void render(QPainter *painter);
protected:
    const Sprite *spr;
};

// Water
class WaterRenderer: public SpriteRenderer
{
public:
    WaterRenderer(const Sprite *spr);
    void render(QPainter *painter);
protected:
    const Sprite *spr;
};

// Sprite 38 Reznor Wheel
class ReznorRenderer: public SpriteRenderer
{
public:
    ReznorRenderer(const Sprite *spr);
    void render(QPainter *painter);
protected:
    const Sprite *spr;
};

// Sprite 39 Rez Plat
class PlatRenderer: public SpriteRenderer
{
public:
    PlatRenderer(const Sprite *spr);
    void render(QPainter *painter);
protected:
    const Sprite *spr;
};

// Sprite 68: Pipe Enemy
class PipeEnemyRenderer: public SpriteRenderer
{
public:
    PipeEnemyRenderer(const Sprite *spr);
    void render(QPainter *painter);
protected:
    const Sprite *spr;
};

// Sprite 78: FRICKEN FLAMETHROWER
class FireBarRenderer: public SpriteRenderer
{
public:
    FireBarRenderer(const Sprite *spr);
    void render(QPainter *painter);
protected:
    const Sprite *spr;
};

// Sprite 97: End of Level Flag
class GoalRenderer: public ObjectRenderer
{
public:
    GoalRenderer(const Sprite *spr);
    void render(QPainter *painter);
protected:
    const Object *obj;
    NormalImageRenderer *pole;
    NormalImageRenderer *fort;
};

// Sprite 109: Signboard
class SignboardRenderer: public ObjectRenderer
{
public:
    SignboardRenderer(const Sprite *spr);
    void render(QPainter *painter);
protected:
    const Object *obj;
    NormalImageRenderer *img;
};

// Sprite 114: Floating Box
class FloatingBoxRenderer: public ObjectRenderer
{
public:
    FloatingBoxRenderer(const Sprite *spr);
    void render(QPainter *painter);
protected:
    const Object *obj;
    NormalImageRenderer *img;
};

// Sprite 115: Bullet Bill Launcher
class BulletBillLauncherRenderer: public SpriteRenderer
{
public:
    BulletBillLauncherRenderer(const Sprite *spr);
    void render(QPainter *painter);
protected:
    const Sprite *spr;
};

// Sprite 124: Mushroom Platform
class MushroomPlatformRenderer: public ObjectRenderer
{
public:
    MushroomPlatformRenderer(const Sprite *spr, QString basePath);
    void render(QPainter *painter);
protected:
    const Sprite *spr;
    QString basePath;
};

// Sprite 135: Goomba
class GoombaRenderer: public SpriteRenderer
{
public:
    GoombaRenderer(const Sprite *spr);
    void render(QPainter *painter);
protected:
    const Sprite *spr;
};

// Sprite 139: Goomba Tower
class GoombaTowerRenderer: public ObjectRenderer
{
public:
    GoombaTowerRenderer(const Sprite *spr);
    void render(QPainter *painter);
protected:
    const Object *obj;
    NormalImageRenderer *top;
    QList<NormalImageRenderer*> middle;
    NormalImageRenderer *bottom;
};

// Sprite 213: Pokey
class PokeyRenderer: public ObjectRenderer
{
public:
    PokeyRenderer(const Sprite *spr);
    void render(QPainter *painter);
protected:
    const Object *obj;
    NormalImageRenderer *top;
    QList<NormalImageRenderer*> middle;
    NormalImageRenderer *bottom;
};

// Sprite 165: Koopa Troopa
class KoopaTroopaRenderer: public ObjectRenderer
{
public:
    KoopaTroopaRenderer(const Sprite *spr);
    void render(QPainter *painter);
protected:
    const Object *obj;
    NormalImageRenderer *img;
};

// Sprite 165: Koopa Troopa
class KoopaParatroopaRenderer: public ObjectRenderer
{
public:
    KoopaParatroopaRenderer(const Sprite *spr);
    void render(QPainter *painter);
protected:
    const Object *obj;
    NormalImageRenderer *img;
};

// Sprite 165: Koopa Troopa Gen
class KoopaParatroopaGenRenderer: public ObjectRenderer
{
public:
    KoopaParatroopaGenRenderer(const Sprite *spr);
    void render(QPainter *painter);
protected:
    const Object *obj;
    NormalImageRenderer *img;
};

// Sprite 189: RecLiftRenderer
class RecLiftRenderer: public SpriteRenderer
{
public:
    RecLiftRenderer(const Sprite *spr, QString path);
    void render(QPainter *painter);
protected:
    const Sprite *spr;
    QString path;
    int sideOffset = 0;
};

// Sprite 212 Roy's Balls
class BallsRenderer: public SpriteRenderer
{
public:
    BallsRenderer(const Sprite *spr);
    void render(QPainter *painter);
protected:
    const Sprite *spr;
};

// Sprite 215: Bob-omb Cannon
class BobOmbCannonRenderer: public SpriteRenderer
{
public:
    BobOmbCannonRenderer(const Sprite *spr);
    void render(QPainter *painter);
protected:
    const Sprite *spr;
};

// Sprite 221/223/225: Switches
class SwitchRenderer: public ObjectRenderer
{
public:
    SwitchRenderer(const Sprite *spr, QString filename);
    void render(QPainter *painter);
protected:
    const Object *obj;
    QString filename;
    NormalImageRenderer *img;
};

// Sprite 239: Lemmy Mushroom
class LMRenderer: public SpriteRenderer
{
public:
    LMRenderer(const Sprite *spr);
    void render(QPainter *painter);
protected:
    const Sprite *spr;
};

// Sprite 240: Urchin
class UrchinRenderer: public SpriteRenderer
{
public:
    UrchinRenderer(const Sprite *spr);
    void render(QPainter *painter);
protected:
    const Sprite *spr;
};

// Sprite 253 Larry Platform
class LarryPlatformRenderer: public SpriteRenderer
{
public:
    LarryPlatformRenderer(const Sprite *spr);
    void render(QPainter *painter);
protected:
    const Sprite *spr;
};

// Sprites 267/275/276: Long ? Blocks
class LongQBlockRenderer: public SpriteRenderer
{
public:
    LongQBlockRenderer(const Sprite *spr, QString filename);
    void render(QPainter *painter);
protected:
    const Sprite *spr;
    NormalImageRenderer* block;
};

// Sprite 280: + Clock
class ClockRenderer: public SpriteRenderer
{
public:
    ClockRenderer(const Sprite *spr);
    void render(QPainter *painter);
protected:
    const Sprite *spr;
};

class EntranceRenderer : public ObjectRenderer
{
public:
    EntranceRenderer(const Entrance *entrance);
    void render(QPainter *painter);
private:
    RoundedRectRenderer *rect;
    const Entrance* entr;
};


#endif // OBJECTRENDERER_H
