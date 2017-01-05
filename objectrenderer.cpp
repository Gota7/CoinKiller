#include "objectrenderer.h"
#include "objects.h"

#include <QPainter>

SpriteRenderer::SpriteRenderer(const Sprite *spr)
{
    this->spr = spr;

    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/sprites/");

    switch (spr->getid()) {

    extern bool LemmyMode;

    if (LemmyMode == false) {

    case 0: // Autoscroll
        ret = new NormalImageRenderer(spr, basePath + "autoscroll.png");
        break;
        case 1: // I LOVE FREAKEN PIPE BOOBS
            ret = new NormalImageRenderer(spr, basePath + "pipe_bubbles.png");
            break;
    case 2: // I LOVE FREAKIN BUBBLES
        ret = new NormalImageRenderer(spr, basePath + "bubbles.png");
        break;
    case 3: // Cheep Chomp
        ret = new NormalImageRenderer(spr, basePath + "cheep_chomp.png");
        break;
    case 4: // Burner Right
        ret = new NormalImageRenderer(spr, basePath + "burner_right.png");
        break;
    case 5: // Burner Down
        ret = new NormalImageRenderer(spr, basePath + "burner_down.png");
        break;
    case 6: // Burner Left
        ret = new NormalImageRenderer(spr, basePath + "burner_left.png");
        break;
    case 7: // Burner Up
        ret = new NormalImageRenderer(spr, basePath + "burner_up.png");
        break;
    case 8: // Swoop
        ret = new NormalImageRenderer(spr, basePath + "swoop.png");
        break;
    case 9: // Whomp
        ret = new NormalImageRenderer(spr, basePath + "whomp.png");
        break;
    case 10: // Lemmy Conveyor
        ret = new NormalImageRenderer(spr, basePath + "lemmy_conveyor.png");
        break;
    case 12: // Lava
        ret = new LavaRenderer(spr);
        break;
    case 13: // Poison
        ret = new PoisonRenderer(spr);
        break;
        case 14: // Cloud FG
            ret = new NormalImageRenderer(spr, basePath + "cloud.png");
            break;
    case 15: // Water
        ret = new WaterRenderer(spr);
        break;
    case 18: // Tile Greek
        ret = new NormalImageRenderer(spr, basePath + "tile_god.png");
        break;
    case 19: // Desert Crater
        ret = new NormalImageRenderer(spr, basePath + "desert_crater.png");
        break;
    case 20: // Gold Block
        ret = new NormalImageRenderer(spr, basePath + "gold_block.png");
        break;
    case 21: // Note Block
        ret = new NormalImageRenderer(spr, basePath + "note_block.png");
        break;
        case 22: // Special Exit
            ret = new NormalImageRenderer(spr, basePath + "special_exit.png");
            break;
    case 23: // Hidden Block
        ret = new NormalImageRenderer(spr, basePath + "hidden_block.png");
        break;
    case 27: // POW Block
        ret = new NormalImageRenderer(spr, basePath + "pow_block.png");
        break;
        case 26: // Roulette Block
            ret = new NormalImageRenderer(spr, basePath + "roulette.png");
            break;
        case 28: // Movement Controlled POW Block
            ret = new NormalImageRenderer(spr, basePath + "mov_pow_block.png");
            break;
    case 29: // Bob-omb
        ret = new NormalImageRenderer(spr, basePath + "bob-omb.png");
        break;
    case 30: // Squidward's Testicles
        ret = new NormalImageRenderer(spr, basePath + "boss_controller.png");
        break;
    case 31: // Boomerang Bro.
        ret = new NormalImageRenderer(spr, basePath + "boomerang_bro.png");
        break;
    case 32: // Fire Bro.
        ret = new NormalImageRenderer(spr, basePath + "fire_bro.png");
        break;
    case 33: // Hammer Bro.
        ret = new NormalImageRenderer(spr, basePath + "hammer_bro.png");
        break;
        case 34: // Sledge Bro.
            ret = new NormalImageRenderer(spr, basePath + "sledge.png");
            break;
    case 35: // Lava Bubble
        ret = new NormalImageRenderer(spr, basePath + "lava_bubble.png");
        break;
        case 38: // Reznor Wheel
            ret = new ReznorRenderer(spr);
            break;
        case 39: // Reznor Wheel
            ret = new PlatRenderer(spr);
            break;
        case 49: // Chain
            ret = new NormalImageRenderer(spr, basePath + "chain.png");
            break;
        case 50: // Chain Controller
            ret = new NormalImageRenderer(spr, basePath + "chain_controller.png");
            break;
    case 52: // Checkpoint Flag
        ret = new NormalImageRenderer(spr, basePath + "checkpoint_flag.png");
        break;
        case 54: // Rotate Control
            ret = new NormalImageRenderer(spr, basePath + "rotate_control.png");
            break;
    case 55: // Coin
        ret = new NormalImageRenderer(spr, basePath + "coin.png");
        break;
    case 56: // Coin Bubble
        ret = new NormalImageRenderer(spr, basePath + "coin_bubble.png");
        break;
    case 57: // Coin Eruption
        ret = new NormalImageRenderer(spr, basePath + "coin_erupt.png");
        break;
    case 59: // Rotating Coin
        ret = new NormalImageRenderer(spr, basePath + "rot_coin.png");
        break;
    case 60: // Movement Controlled Coin
        ret = new NormalImageRenderer(spr, basePath + "mov_coin.png");
        break;
    case 61: // Red Coin
        ret = new NormalImageRenderer(spr, basePath + "red_coin.png");
        break;
    case 62: // Rotating Red Coin
        ret = new NormalImageRenderer(spr, basePath + "rot_red_coin.png");
        break;
    case 63: // Left Skewer
        ret = new NormalImageRenderer(spr, basePath + "left_skewer.png");
        break;
    case 64: // Right Skewer
        ret = new NormalImageRenderer(spr, basePath + "right_skewer.png");
        break;
        case 65: // Right Skewer
            ret = new NormalImageRenderer(spr, basePath + "respawn_pipe.png");
            break;
    case 66: // Pipe Cannon
        ret = new NormalImageRenderer(spr, basePath + "pipe_cannon.png");
        break;
    case 67: // Pipe Cannon - Ludwig Bossfight
        ret = new NormalImageRenderer(spr, basePath + "pipe_cannon_ludwig.png");
        break;
        case 68: // Enemy Generator
            ret = new PipeEnemyRenderer(spr);
            break;
    case 69: // Door
        ret = new NormalImageRenderer(spr, basePath + "door.png");
        break;
    case 70: // Castle Boss Door
        ret = new NormalImageRenderer(spr, basePath + "door_castle.png");
        break;
    case 71: // Closed Door
        ret = new NormalImageRenderer(spr, basePath + "door_closed.png");
        break;
    case 72: // Final Boss Door
        ret = new NormalImageRenderer(spr, basePath + "door_final_boss.png");
        break;
    case 73: // Ghost House Door
        ret = new NormalImageRenderer(spr, basePath + "door_ghosthouse.png");
        break;
        case 74: // Flag Door
            ret = new NormalImageRenderer(spr, basePath + "flag_door.png");
            break;
    case 75: // Tower Boss Door
        ret = new NormalImageRenderer(spr, basePath + "door_tower.png");
        break;
    case 76: // Big Thwomp
        ret = new NormalImageRenderer(spr, basePath + "big_thwomp.png");
        break;
    case 77: // Thwomp
        ret = new NormalImageRenderer(spr, basePath + "thwomp.png");
        break;
        case 78: // Fire Bar Renderererer
            ret = new FireBarRenderer(spr);
            break;
        case 79: // Fire Out
            ret = new NormalImageRenderer(spr, basePath + "fire_out.png");
            break;
        case 80: // Fire In
            ret = new NormalImageRenderer(spr, basePath + "fire_in.png");
            break;
    case 81: // Fireball Pipe - ! Junction
        ret = new NormalImageRenderer(spr, basePath + "fireballpipe_junction.png");
        break;
    case 83: // Fish Bone
        ret = new NormalImageRenderer(spr, basePath + "fish_bone.png");
        break;
        case 84: // Chainer
            ret = new NormalImageRenderer(spr, basePath + "chainer.png");
            break;
        case 85: // Fish Bone
            ret = new NormalImageRenderer(spr, basePath + "if_loc.png");
            break;
        case 87: // Flag Control
            ret = new NormalImageRenderer(spr, basePath + "flag_control.png");
            break;
    case 91: // Coin Coffer
        ret = new NormalImageRenderer(spr, basePath + "coin_coffer.png");
        break;
    case 92: // Grinder
        ret = new NormalImageRenderer(spr, basePath + "grinder.png");
        break;
    case 93: // Scuttlebug
        ret = new NormalImageRenderer(spr, basePath + "scuttlebug.png");
        break;
    case 95: // Blooper
        ret = new NormalImageRenderer(spr, basePath + "blooper.png");
        break;
    case 97: // End of Level Flag
        ret = new GoalRenderer(spr);
        break;
        case 98: // Group ID
            ret = new NormalImageRenderer(spr, basePath + "group_id.png");
            break;
    case 99: // Wiggler
        ret = new NormalImageRenderer(spr, basePath + "wiggler.png");
        break;
    case 102: // Trampoline
        ret = new NormalImageRenderer(spr, basePath + "iggy.png");
        break;
        case 103: // Toad Controller
            ret = new NormalImageRenderer(spr, basePath + "toad_controller.png");
            break;
    case 106: // Trampoline
        ret = new NormalImageRenderer(spr, basePath + "trampoline.png");
        break;
    case 108: // Spider Web
        ret = new NormalImageRenderer(spr, basePath + "spider_web.png");
        break;
    case 109: // Signboard
        ret = new SignboardRenderer(spr);
        break;
    case 110: // Dry Bones
        ret = new NormalImageRenderer(spr, basePath + "dry_bones.png");
        break;
    case 111: // Giant Dry Bones
        ret = new NormalImageRenderer(spr, basePath + "sgiant_dry_bones.png");
        break;
    case 114: // Floating Box
        ret = new FloatingBoxRenderer(spr);
        break;
    case 115: // Floating Box
        ret = new BulletBillLauncherRenderer(spr);
        break;
    case 117: // Banzi Bill Launcher
        ret = new NormalImageRenderer(spr, basePath + "banzai_bill_launcher.png");
        break;
    case 124: // Mushroom Platform
        ret = new MushroomPlatformRenderer(spr, basePath + "mushroom_platform/");
        break;
    case 125: // Bowser
        ret = new NormalImageRenderer(spr, basePath + "bowser.png");
        break;
    case 128: // Dry Bowser
        ret = new NormalImageRenderer(spr, basePath + "dry_bowser.png");
        break;
    case 129: // Big Dry Bowser
        ret = new NormalImageRenderer(spr, basePath + "big_dry_bowser.png");
        break;
    case 130: // Big Bowser
        ret = new NormalImageRenderer(spr, basePath + "big_bowser.png");
        break;
    case 135: // Goomba
        ret = new GoombaRenderer(spr);
        break;
    case 136: // Bone Goomba
        ret = new NormalImageRenderer(spr, basePath + "bone_goomba.png");
        break;
    case 137: // Micro Goomba
        ret = new NormalImageRenderer(spr, basePath + "micro_goomba.png");
        break;
    case 138: // Paragoomba
        ret = new NormalImageRenderer(spr, basePath + "paragoomba.png");
        break;
    case 139: // Goomba Tower
        ret = new GoombaTowerRenderer(spr);
        break;
    case 140: // Crowber
        ret = new NormalImageRenderer(spr, basePath + "crowber.png");
        break;
    case 141: // Larry
        ret = new NormalImageRenderer(spr, basePath + "larry.png");
        break;
    case 142: // LEMMAYYY!!!
        ret = new NormalImageRenderer(spr, basePath + "lemmy.png");
        break;
    case 143: // Conveyor Belt Switch
        ret = new NormalImageRenderer(spr, basePath + "conveyor_belt_switch.png");
        break;
    case 150: // Seesaw Lift
        ret = new NormalImageRenderer(spr, basePath + "seesaw_lift.png");
        break;
        case 153: // Platform Generator
            ret = new NormalImageRenderer(spr, basePath + "plat_gen.png");
            break;
        case 155: //Ludwig Von Randomness
            ret = new NormalImageRenderer(spr, basePath + "ludwig.png");
            break;
        case 156: //Camera Limit Left
            ret = new NormalImageRenderer(spr, basePath + "camera_limit_left.png");
            break;
        case 157: //Camera Limit Right
            ret = new NormalImageRenderer(spr, basePath + "camera_limit_right");
            break;
    case 158: // Buzzy Beetle
        ret = new NormalImageRenderer(spr, basePath + "buzzy_beetle.png");
        break;
        case 162: // Morton
            ret = new NormalImageRenderer(spr, basePath + "morton.png");
            break;
    case 165: // Koopa Troopa
        ret = new KoopaTroopaRenderer(spr);
        break;
        case 166: // Back and Forth Controller
            ret = new NormalImageRenderer(spr, basePath + "back_forth.png");
            break;
    case 167: // Pipe Piranha Plant - Down
        ret = new NormalImageRenderer(spr, basePath + "piranha_pipe_down.png");
        break;
    case 175: // Grounded Piranha Plant
        ret = new NormalImageRenderer(spr, basePath + "piranha_plant.png");
        break;
    case 181: // Pipe Piranha Plant - Left
        ret = new NormalImageRenderer(spr, basePath + "piranha_pipe_left.png");
        break;
    case 182: // Pipe Piranha Plant - Right
        ret = new NormalImageRenderer(spr, basePath + "piranha_pipe_right.png");
        break;
    case 183: // Pipe Piranha Plant - Up
        ret = new NormalImageRenderer(spr, basePath + "piranha_pipe_up.png");
        break;
    case 184: // Parabomb
        ret = new NormalImageRenderer(spr, basePath + "parabomb.png");
        break;
    case 185: // KoopaParatroopa
        ret = new KoopaParatroopaRenderer(spr);
        break;
        case 186: // Koopa Paratroopa Generator
            ret = new KoopaParatroopaGenRenderer(spr);
            break;
    case 189: // Rectangle Lift - Tower
        ret = new RecLiftRenderer(spr, basePath + "tower_rectangle_lift/");
        break;
    case 190: // Rectangle Lift - Ghosthouse (Checkered)
        ret = new RecLiftRenderer(spr, basePath + "checkered_rectangle_lift/");
        break;
    case 191: // Rectangle Lift - Desert
        ret = new RecLiftRenderer(spr, basePath + "desert_rectangle_lift/");
        break;
    case 192: // Rectangle Lift - Castle
        ret = new RecLiftRenderer(spr, basePath + "castle_rectangle_lift/");
        break;
    case 193: // Rectangle Lift - Underwater
        ret = new RecLiftRenderer(spr, basePath + "underwater_rectangle_lift/");
        break;
    case 194: // Cheep Cheep
        ret = new NormalImageRenderer(spr, basePath + "cheep_cheep.png");
        break;
    case 195: // Big Cheep Cheep
        ret = new NormalImageRenderer(spr, basePath + "big_cheep_cheep.png");
        break;
        case 200: // Spiny Cheep Cheep
            ret = new NormalImageRenderer(spr, basePath + "spiny_cheep_cheep.png");
            break;
        case 204: // Movement Brick
            ret = new NormalImageRenderer(spr, basePath + "mov_brick.png");
            break;
    case 205: // Red Ring
        ret = new NormalImageRenderer(spr, basePath + "red_ring.png");
        break;
    case 206: // Gold Ring
        ret = new NormalImageRenderer(spr, basePath + "gold_ring.png");
        break;
    case 211: // Roy Koopa
        ret = new NormalImageRenderer(spr, basePath + "boss_roy.png");
        break;
        case 212: // Roy's Dick
            ret = new BallsRenderer(spr);
            break;
    case 213: // Pokey
        ret = new PokeyRenderer(spr);
        break;
        case 214: // Scroll Camera
            ret = new NormalImageRenderer(spr, basePath + "scroll_camera.png");
            break;
    case 215: // Bob-omb Cannon
        ret = new BobOmbCannonRenderer(spr);
        break;
    case 216: // Boss Shutter
        ret = new NormalImageRenderer(spr, basePath + "boss_shutter.png");
        break;
    case 219: // Star Coin
        ret = new NormalImageRenderer(spr, basePath + "star_coin.png");
        break;
    case 220: // Star Coin
        ret = new NormalImageRenderer(spr, basePath + "rotating_star_coin.png");
        break;
    case 221: // ! Switch
        ret = new SwitchRenderer(spr, basePath + "exclamation_switch.png");
        break;
    case 223: // ? Switch
        ret = new SwitchRenderer(spr, basePath + "question_switch.png");
        break;
    case 225: // P Switch
        ret = new SwitchRenderer(spr, basePath + "p_switch.png");
        break;
        case 226: // Brick P Switch
            ret = new SwitchRenderer(spr, basePath + "brick_p.png");
            break;
    case 231: // Boohemoth
        ret = new NormalImageRenderer(spr, basePath + "boohemoth.png");
        break;
    case 234: // Spiked Ball
        ret = new NormalImageRenderer(spr, basePath + "spiked_ball.png");
        break;
    case 235: // Big Spiked Ball
        ret = new NormalImageRenderer(spr, basePath + "big_spiked_ball.png");
        break;
    case 236: // Mega Spiked Ball
        ret = new NormalImageRenderer(spr, basePath + "mega_spiked_ball.png");
        break;
    case 240: // Urchin
        ret = new UrchinRenderer(spr);
        break;
        case 245: // Wendy
            ret = new NormalImageRenderer(spr, basePath + "wendy.png");
            break;
        case 246: // Wendy Water
            ret = new NormalImageRenderer(spr, basePath + "wendy_water.png");
            break;
    case 247: // Invisible Trampoline Block
        ret = new NormalImageRenderer(spr, basePath + "invisible_tramp.png");
        break;
    case 253: // Larry Platform
        ret = new LarryPlatformRenderer(spr);
        break;
    case 255: // Bowser Head Statue
        ret = new NormalImageRenderer(spr, basePath + "bowser_head_statue.png");
        break;
        case 256: // Invisible Solid
            ret = new NormalImageRenderer(spr, basePath + "invisible.png");
            break;
    case 257: // Spine Coaster
        ret = new NormalImageRenderer(spr, basePath + "spine_coaster.png");
        break;
        case 260: // Roy Cutscene
            ret = new NormalImageRenderer(spr, basePath + "roy_controller.png");
            break;
    case 266: // Flash Koopalings
        ret = new NormalImageRenderer(spr, basePath + "flash_koopalings.png");
        break;
    case 267: // Long Question Block
        ret = new LongQBlockRenderer(spr, basePath + "long_question_block.png");
        break;
    case 269: // Gold Ship
        ret = new NormalImageRenderer(spr, basePath + "gold_ship.png");
        break;
    case 270: // Icy Spiked Ball
        ret = new NormalImageRenderer(spr, basePath + "icy_spiked_ball.png");
        break;
    case 272: // Peach Cage
        ret = new NormalImageRenderer(spr, basePath + "peach_cage.png");
        break;
    case 273: // Coin Roulette Block
        ret = new NormalImageRenderer(spr, basePath + "coin_roulette_block.png");
        break;
    case 274: // Flying Gold Block Spawn Point
        ret = new NormalImageRenderer(spr, basePath + "flying_gold_block.png");
        break;
    case 275: // Long Question Block - Underground
        ret = new LongQBlockRenderer(spr, basePath + "long_question_block_underground.png");
        break;
    case 276: // Long Question Block - Lava
        ret = new LongQBlockRenderer(spr, basePath + "long_question_block_lava.png");
        break;
    case 277: // Switchable Conveyor Belt
        ret = new NormalImageRenderer(spr, basePath + "switchable_conveyor_belt.png");
        break;
    case 278: // Assist Block
        ret = new NormalImageRenderer(spr, basePath + "assist_block.png");
        break;
    case 279: // Lemmy Ball
        ret = new NormalImageRenderer(spr, basePath + "lemmy_ball.png");
        break;
    case 280: // + Clock
        ret = new ClockRenderer(spr);
        break;
    case 287: // Toad House Door
        ret = new NormalImageRenderer(spr, basePath + "door_toadhouse.png");
        break;
        case 288: // Mega Mushroom Controller
            ret = new NormalImageRenderer(spr, basePath + "mega_control.png");
            break;
        case 289: // Lemmy Mushroom
            ret = new LMRenderer(spr);
            break;
        case 292: // Warp Cannon Signboards
            ret = new NormalImageRenderer(spr, basePath + "warp_sign.png");
            break;
    case 293: // Punching Glove
        ret = new NormalImageRenderer(spr, basePath + "punching_glove.png");
        break;
    case 294: // Warp Cannon
        ret = new NormalImageRenderer(spr, basePath + "warp_cannon.png");
        break;
    case 296: // Toad
        ret = new NormalImageRenderer(spr, basePath + "toad.png");
        break;
        case 298: // Applause Kun
            ret = new NormalImageRenderer(spr, basePath + "applause_kun.png");
            break;
    case 299: // Lemmy Fall Block
        ret = new NormalImageRenderer(spr, basePath + "lemmy_fall_block.png");
        break;
    case 300: // Clap Coin
        ret = new NormalImageRenderer(spr, basePath + "clap_coin.png");
        break;
    case 302: // Moon Coin
        ret = new NormalImageRenderer(spr, basePath + "moon_coin.png");
        break;
    case 303: // Rotato Moon Coin
        ret = new NormalImageRenderer(spr, basePath + "rot_moon_coin.png");
        break;
        case 310: // Boner Land (Bowser Lift)
            ret = new NormalImageRenderer(spr, basePath + "bowser_lift.png");
            break;
        case 311: // Coin Meteor
            ret = new NormalImageRenderer(spr, basePath + "coin_meteor.png");
            break;
        case 312: // No Inventory
            ret = new NormalImageRenderer(spr, basePath + "no_inventory.png");
            break;
    case 315: // Peach For Credits
        ret = new NormalImageRenderer(spr, basePath + "peach_credits.png");
        break;
        case 316: // Cannon Warp
            ret = new NormalImageRenderer(spr, basePath + "cannon_rush.png");
            break;
        case 320: // Line PLatform
            ret = new NormalImageRenderer(spr, basePath + "line_lift.png");
            break;
    case 322: // Big Grinder
        ret = new NormalImageRenderer(spr, basePath + "big_grinder.png");
        break;
        case 323: // Ending Birds
            ret = new NormalImageRenderer(spr, basePath + "ending_birds.png");
            break;
    }
    default:
        if (LemmyMode == false) {ret = new RoundedRectRenderer(spr, QString("%1").arg(spr->getid()), QColor(0,90,150,150));} else {ret = new NormalImageRenderer(spr, basePath + "lemmy.png");}
            break;
    }
}

void SpriteRenderer::render(QPainter *painter)
{
    ret->render(painter);
}


NormalImageRenderer::NormalImageRenderer(const Object *obj, QString filename)
{
    rect = QRect(obj->getx()+obj->getOffsetX(), obj->gety()+obj->getOffsetY(), obj->getwidth(), obj->getheight());
    this->filename = filename;
}

NormalImageRenderer::NormalImageRenderer(QRect rect, QString filename)
{
    this->rect = rect;
    this->filename = filename;
}

void NormalImageRenderer::render(QPainter *painter)
{
    painter->drawPixmap(rect, QPixmap(filename));
}


RoundedRectRenderer::RoundedRectRenderer(const Object *obj, QString text, QColor color, QTextOption align)
{
    this->obj = obj;
    this->text = text;
    this->color = color;
    this->align = align;
}

void RoundedRectRenderer::render(QPainter *painter)
{
    QRect rect(obj->getx()+obj->getOffsetX(), obj->gety()+obj->getOffsetY(), obj->getwidth(), obj->getheight());

    painter->setPen(QColor(0,0,0));

    QPainterPath path;
    path.addRoundedRect(rect, 2.0, 2.0);
    painter->fillPath(path, color);
    painter->drawPath(path);

    painter->setFont(QFont("Arial", 7, QFont::Normal));
    painter->drawText(rect, text, align);
}

//Sprite Lava
void LavaRenderer::render(QPainter *painter)
{
    extern bool ShowLiquid;
    extern int zonewidth;

    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/sprites/");

    //for (int i=0; i<zonewidth; i++) {
    if(ShowLiquid){painter->drawPixmap(spr->getx()+spr->getOffsetX()/*+i*spr->getwidth()*/, spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "lava.png"));}//}
    if (ShowLiquid==false) {painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "lava_block.png"));}


    }

LavaRenderer::LavaRenderer(const Sprite *spr) {

    this->spr=spr;

}

//Sprite Poison
void PoisonRenderer::render(QPainter *painter)
{
    extern bool ShowLiquid;

    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/sprites/");

    //for (int i=0; i<zonewidth; i++) {
    if(ShowLiquid){painter->drawPixmap(spr->getx()+spr->getOffsetX()/*+i*spr->getwidth()*/, spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "poison.png"));}//}
    if (ShowLiquid==false) {painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "poison_block.png"));}



    }

PoisonRenderer::PoisonRenderer(const Sprite *spr) {

    this->spr=spr;

}

//Sprite Water
void WaterRenderer::render(QPainter *painter)
{
    extern bool ShowLiquid;

    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/sprites/");

    //for (int i=0; i<zonewidth; i++) {
    if(ShowLiquid){painter->drawPixmap(spr->getx()+spr->getOffsetX()/*+i*spr->getwidth()*/, spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "water.png"));}//}
    if (ShowLiquid==false) {painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "water_block.png"));}


    }

WaterRenderer::WaterRenderer(const Sprite *spr) {

    this->spr=spr;

}

// Sprite 38: Reznor
ReznorRenderer::ReznorRenderer(const Sprite *spr)
{
    this->spr = spr;
}

void ReznorRenderer::render(QPainter *painter)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/sprites/");

    if (spr->getNybble(5) == 5 && spr->getNybble(6) == 0) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "rez_wheel_2-4.png"));
    if (spr->getNybble(5) == 15 && spr->getNybble(6) == 0) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "rez_wheel_4-4.png"));

}

// Sprite 39: Reznor Platform
PlatRenderer::PlatRenderer(const Sprite *spr)
{
    this->spr = spr;
}

void PlatRenderer::render(QPainter *painter)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/sprites/");

    for (int i = 0; i < spr->getNybble(4); i++) painter->drawPixmap(spr->getx()+spr->getOffsetX() + i*20, spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "plat_middle"));

}

// Sprite 68: Pipe Enemy
PipeEnemyRenderer::PipeEnemyRenderer(const Sprite *spr)
{
    this->spr = spr;
}

void PipeEnemyRenderer::render(QPainter *painter)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/sprites/");

    if (spr->getNybble(4) == 0 && spr->getNybble(5) == 0) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "pipe_goomba_up.png"));
    if (spr->getNybble(4) == 0 && spr->getNybble(5) == 1) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "pipe_goomba_down.png"));
    if (spr->getNybble(4) == 0 && spr->getNybble(5) == 2) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "pipe_goomba_left.png"));
    if (spr->getNybble(4) == 0 && spr->getNybble(5) == 3) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "pipe_goomba_right.png"));

    if (spr->getNybble(4) == 1 && spr->getNybble(5) == 0) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "pipe_bomb_up.png"));
    if (spr->getNybble(4) == 1 && spr->getNybble(5) == 1) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "pipe_bomb_down.png"));
    if (spr->getNybble(4) == 1 && spr->getNybble(5) == 2) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "pipe_bomb_left.png"));
    if (spr->getNybble(4) == 1 && spr->getNybble(5) == 3) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "pipe_bomb_right.png"));

    if (spr->getNybble(4) == 2 && spr->getNybble(5) == 0) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "pipe_bone_up.png"));
    if (spr->getNybble(4) == 2 && spr->getNybble(5) == 1) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "pipe_bone_down.png"));
    if (spr->getNybble(4) == 2 && spr->getNybble(5) == 2) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "pipe_bone_left.png"));
    if (spr->getNybble(4) == 2 && spr->getNybble(5) == 3) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "pipe_bone_right.png"));
}

// Sprite 78: Fire up yo as
FireBarRenderer::FireBarRenderer(const Sprite *spr)
{
    this->spr = spr;
}

void FireBarRenderer::render(QPainter *painter)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/sprites/");

    painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "fire_base"));

    if (spr->getNybble(5) != 0){

        painter->drawEllipse(spr->getx()+spr->getOffsetX() - spr->getNybble(5)*20, spr->gety()+spr->getOffsetY() - spr->getNybble(5)*20, spr->getNybble(5)*40+20, spr->getNybble(5)*40+20);

        for (int i=0;i<spr->getNybble(5);i++){painter->drawPixmap(spr->getx()+spr->getOffsetX() + i*20+20, spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "fire_ball.png"));}

    }

}

// Sprite 97: End of Level Flag
GoalRenderer::GoalRenderer(const Sprite *spr)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/sprites/");

    if (spr->getNybble(10) == 1)
    {
        pole = new NormalImageRenderer(spr, basePath + "flagpole_secret.png");
        fort = new NormalImageRenderer(QRect(spr->getx()+200, spr->gety()+80, 120, 120), basePath + "castle_secret.png");
    }
    else
    {
        pole = new NormalImageRenderer(spr, basePath + "flagpole.png");
        fort = new NormalImageRenderer(QRect(spr->getx()+200, spr->gety()+80, 120, 120), basePath + "castle.png");
    }
}

void GoalRenderer::render(QPainter *painter)
{
    pole->render(painter);
    fort->render(painter);
}


// Sprite 109: Signboard
SignboardRenderer::SignboardRenderer(const Sprite *spr)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/sprites/");
    QString signboardPath("sign_%1");

    if (spr->getNybble(5) < 10) img = new NormalImageRenderer(spr, basePath + signboardPath.arg(spr->getNybble(5)));
    else img = new NormalImageRenderer(spr, basePath + signboardPath.arg(7));
}

void SignboardRenderer::render(QPainter *painter)
{
    img->render(painter);
}


// Sprite 114: Floating Box
FloatingBoxRenderer::FloatingBoxRenderer(const Sprite *spr)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/sprites/");

    if (spr->getNybble(5) == 1) img = new NormalImageRenderer(spr, basePath + "floating_box_big.png");
    else img = new NormalImageRenderer(spr, basePath + "floating_box_small.png");
}

void FloatingBoxRenderer::render(QPainter *painter)
{
    img->render(painter);
}


// Sprite 115: Bullet Bill Launcher
BulletBillLauncherRenderer::BulletBillLauncherRenderer(const Sprite *spr)
{
    this->spr = spr;
}

void BulletBillLauncherRenderer::render(QPainter *painter)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/sprites/");

    if (spr->getNybble(10) == 1)
    {
        painter->drawPixmap(spr->getx(), spr->gety()+spr->getheight()-40, 20, 40, QPixmap(basePath + "bullet_bill_launcher_flipped.png"));
        for (int i = 0; i < spr->getNybble(4); i++) painter->drawPixmap(spr->getx(), spr->gety()+i*20, 20, 20, QPixmap(basePath + "bullet_bill_launcher_middle.png"));
    }
    else
    {
        painter->drawPixmap(spr->getx(), spr->gety()+spr->getOffsetY(), 20, 40, QPixmap(basePath + "bullet_bill_launcher.png"));
        for (int i = 0; i < spr->getNybble(4); i++) painter->drawPixmap(spr->getx(), spr->gety()+spr->getOffsetY()+40+i*20, 20, 20, QPixmap(basePath + "bullet_bill_launcher_middle.png"));
    }
}


// Sprite 135: Goomba
GoombaRenderer::GoombaRenderer(const Sprite *spr)
{
    this->spr = spr;
}

void GoombaRenderer::render(QPainter *painter)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/sprites/");

    if (spr->getNybble(14) == 0) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "goomba.png"));
    if (spr->getNybble(14) == 1) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "goomba_blue.png"));
    if (spr->getNybble(14) == 2) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "goomba_red.png"));
}


// Sprite 139: Goomba Tower
GoombaTowerRenderer::GoombaTowerRenderer(const Sprite *spr)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/sprites/");

    top = new NormalImageRenderer(QRect(spr->getx(), spr->gety()+spr->getOffsetY(), spr->getwidth(), 25), basePath + "goomba_tower_top.png");
    bottom = new NormalImageRenderer(QRect(spr->getx(), spr->gety(), spr->getwidth(), 21), basePath + "goomba_tower_bottom.png");

    if (spr->getNybble(5) < 3) return;
    for (int i = 0; i < spr->getNybble(5)-2; i++) middle.append(new NormalImageRenderer(QRect(spr->getx(), spr->gety()+spr->getOffsetY()+25+i*21, spr->getwidth(), 21), basePath + "goomba_tower_middle.png"));
}

void GoombaTowerRenderer::render(QPainter *painter)
{
    top->render(painter);
    for(int i = 0; i < middle.size(); i++) middle[i]->render(painter);
    bottom->render(painter);
}

// Sprite 213: Pokey
PokeyRenderer::PokeyRenderer(const Sprite *spr)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/sprites/");

    top = new NormalImageRenderer(QRect(spr->getx(), spr->gety()+spr->getOffsetY(), spr->getwidth(), 36), basePath + "pokey_top.png");
    bottom = new NormalImageRenderer(QRect(spr->getx(), spr->gety(), spr->getwidth(), 24), basePath + "pokey_bottom.png");

    if (spr->getNybble(5) < 3) return;
    for (int i = 0; i < spr->getNybble(5)-2; i++) middle.append(new NormalImageRenderer(QRect(spr->getx(), spr->gety()+spr->getOffsetY()+36+i*24, spr->getwidth(), 24), basePath + "pokey_middle.png"));
}

void PokeyRenderer::render(QPainter *painter)
{
    top->render(painter);
    for(int i = 0; i < middle.size(); i++) middle[i]->render(painter);
    bottom->render(painter);
}


// Sprite 165: Koopa Troopa
KoopaTroopaRenderer::KoopaTroopaRenderer(const Sprite *spr)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/sprites/");

    if (spr->getNybble(5) == 1) img = new NormalImageRenderer(spr, basePath + "koopa_troopa_red.png");
    else img = new NormalImageRenderer(spr, basePath + "koopa_troopa_green.png");
}

void KoopaTroopaRenderer::render(QPainter *painter)
{
    img->render(painter);
}

// Koopa Paratroopa
KoopaParatroopaRenderer::KoopaParatroopaRenderer(const Sprite *spr)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/sprites/");

    if (spr->getNybble(5) == 1) img = new NormalImageRenderer(spr, basePath + "koopa_paratroopa_red.png");
    else img = new NormalImageRenderer(spr, basePath + "koopa_paratroopa_green.png");
}

void KoopaParatroopaRenderer::render(QPainter *painter)
{
    img->render(painter);
}

// Koopa Paratroopa Gen
KoopaParatroopaGenRenderer::KoopaParatroopaGenRenderer(const Sprite *spr)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/sprites/");

    if (spr->getNybble(5) == 1) img = new NormalImageRenderer(spr, basePath + "koopa_paratroopa_red_gen.png");
    else img = new NormalImageRenderer(spr, basePath + "koopa_paratroopa_green_gen.png");
}

void KoopaParatroopaGenRenderer::render(QPainter *painter)
{
    img->render(painter);
}


// Sprite 221/223/225: Switches
SwitchRenderer::SwitchRenderer(const Sprite *spr, QString filename)
{
    this->filename = filename;
    if (spr->getNybble(5) == 1) filename.insert(filename.size()-4, "_flipped");

    img = new NormalImageRenderer(spr, filename);
}

void SwitchRenderer::render(QPainter *painter)
{
    img->render(painter);
}


// RecLiftRenderer
RecLiftRenderer::RecLiftRenderer(const Sprite *spr, QString path)
{
    this->spr = spr;
    this->path = path;
    if (spr->getid() == 192) sideOffset = 3;
}

void RecLiftRenderer::render(QPainter *painter)
{
    int blockWidth = spr->getNybble(15) > 0 ? spr->getNybble(15)*20 : 20;
    int blockHeight = spr->getNybble(13) > 0 ? spr->getNybble(13)*20 : 20;

    painter->drawPixmap(QRect(spr->getx()-sideOffset, spr->gety(), 20+sideOffset, 20), QPixmap(path + "tl.png"));
    painter->drawPixmap(QRect(spr->getx()-sideOffset, spr->gety()+blockHeight, 20+sideOffset, 20), QPixmap(path + "bl.png"));
    painter->drawPixmap(QRect(spr->getx()+blockWidth, spr->gety(), 20+sideOffset, 20), QPixmap(path + "tr.png"));
    painter->drawPixmap(QRect(spr->getx()+blockWidth, spr->gety()+blockHeight, 20+sideOffset, 20), QPixmap(path + "br.png"));

    for (int i = 0; i < spr->getNybble(15)-1; i++)
    {
        painter->drawPixmap(QRect(spr->getx() + i*20+20, spr->gety(), 20, 20), QPixmap(path + "t.png"));
        painter->drawPixmap(QRect(spr->getx() + i*20+20, spr->gety()+blockHeight, 20, 20), QPixmap(path + "b.png"));
    }
    for (int i = 0; i < spr->getNybble(13)-1; i++)
    {
        painter->drawPixmap(QRect(spr->getx(), spr->gety() + i*20+20, 20, 20), QPixmap(path + "l.png"));
        painter->drawPixmap(QRect(spr->getx()+blockWidth, spr->gety() + i*20+20, 20, 20), QPixmap(path + "r.png"));
    }
    for (int x = 20; x < blockWidth; x+=20)
        for (int y = 20; y < blockHeight; y+=20)
            painter->drawPixmap(QRect(spr->getx()+x, spr->gety()+y, 20, 20), QPixmap(path + "c.png"));
    if (spr->getNybble(9) == 1 || spr->getNybble(9) == 3) for (int x = 0; x < blockWidth+20; x+=20) painter->drawPixmap(QRect(spr->getx()+x, spr->gety()-20, 20, 20), QPixmap(path + "s_t.png"));
    if (spr->getNybble(9) == 2 || spr->getNybble(9) == 3) for (int x = 0; x < blockWidth+20; x+=20) painter->drawPixmap(QRect(spr->getx()+x, spr->gety()+blockHeight+20, 20, 20), QPixmap(path + "s_b.png"));
    if (spr->getNybble(9) == 4 || spr->getNybble(9) == 6) for (int y = 0; y < blockHeight+20; y+=20) painter->drawPixmap(QRect(spr->getx()-20, spr->gety()+y, 20, 20), QPixmap(path + "s_l.png"));
    if (spr->getNybble(9) == 5 || spr->getNybble(9) == 6) for (int y = 0; y < blockHeight+20; y+=20) painter->drawPixmap(QRect(spr->getx()+blockWidth+20, spr->gety()+y, 20, 20), QPixmap(path + "s_r.png"));
}

// Sprite 124: Mushroom Platform Renderer
MushroomPlatformRenderer::MushroomPlatformRenderer(const Sprite *spr, QString basePath)
{
    this->spr = spr;
    this->basePath = basePath;
}

void MushroomPlatformRenderer::render(QPainter *painter)
{
    painter->drawPixmap(QRect(spr->getx()+spr->getOffsetX(), spr->gety(), 24, 20), QPixmap(basePath + "l.png"));
    painter->drawPixmap(QRect(spr->getx()-spr->getOffsetX()-24, spr->gety(), 24, 20), QPixmap(basePath + "r.png"));
    for (int i = 24; i < spr->getwidth()-24; i += 20)
        painter->drawPixmap(QRect(spr->getx()+spr->getOffsetX()+i, spr->gety(), 20, 20), QPixmap(basePath + "m.png"));
}


// Sprite 212: Roy's Penis
BallsRenderer::BallsRenderer(const Sprite *spr)
{
    this->spr = spr;
}

void BallsRenderer::render(QPainter *painter)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/sprites/");

    if (spr->getNybble(5) == 0) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "wall_l.png"));
    if (spr->getNybble(5) == 1) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "wall_r.png"));
}

// Sprite 215: Bob-omb Cannon
BobOmbCannonRenderer::BobOmbCannonRenderer(const Sprite *spr)
{
    this->spr = spr;
}

void BobOmbCannonRenderer::render(QPainter *painter)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/sprites/");

    if (spr->getNybble(5) != 1) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "cannon_right.png"));
    else painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "cannon_left.png"));
}

// Sprite 239: Lemmy's Mushroom
LMRenderer::LMRenderer(const Sprite *spr)
{
    this->spr = spr;
}

void LMRenderer::render(QPainter *painter)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/sprites/");

    if (spr->getNybble(15) == 0) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "lemmy_big.png"));
    if (spr->getNybble(15) == 1) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "lemmy_small.png"));
}

// Sprite 240: Urchin
UrchinRenderer::UrchinRenderer(const Sprite *spr)
{
    this->spr = spr;
}

void UrchinRenderer::render(QPainter *painter)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/sprites/");

    if (spr->getNybble(5) != 1) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "urchin.png"));
    else painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "urchin_big.png"));
}

// Sprite 289: Larry Platform
LarryPlatformRenderer::LarryPlatformRenderer(const Sprite *spr)
{
    this->spr = spr;
}

void LarryPlatformRenderer::render(QPainter *painter)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/sprites/");

    if (spr->getNybble(10) == 3) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "larry_platform3.png"));
    if (spr->getNybble(10) == 4) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "larry_platform4.png"));
}

// Sprites 267/275/276: Long ? Blocks
LongQBlockRenderer::LongQBlockRenderer(const Sprite *spr, QString filename)
{
    this->spr = spr;
    block = new NormalImageRenderer(spr, filename);
}

void LongQBlockRenderer::render(QPainter *painter)
{
    block->render(painter);

    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/tileoverlays/");
    QString overlay;

    switch (spr->getNybble(13))
    {
        case 1: case 8: overlay = "coin.png"; break;
        case 2: overlay = "fire_flower.png"; break;
        case 4: overlay = "super_leaf.png"; break;
        case 5: overlay = "gold_flower.png"; break;
        case 6: overlay = "mini_mushroom.png"; break;
        case 7: overlay = "super_star.png"; break;
        case 10: overlay = "10_coins.png"; break;
        case 11: overlay = "1up_mushroom.png"; break;
        case 13: overlay = "trampoline.png"; break;
        case 14: overlay = "coin_super_mushroom.png"; break;
        default: return; break;
    }

    painter->drawPixmap(spr->getx()+spr->getOffsetX()+20, spr->gety()+spr->getOffsetY(), 20, 20, QPixmap(basePath + overlay));
}


// Sprite 280: + Clock
ClockRenderer::ClockRenderer(const Sprite *spr)
{
    this->spr = spr;
}

void ClockRenderer::render(QPainter *painter)
{
    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/sprites/");

    if (spr->getNybble(5) != 1) painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "clock_50.png"));
    else painter->drawPixmap(spr->getx()+spr->getOffsetX(), spr->gety()+spr->getOffsetY(), spr->getwidth(), spr->getheight(), QPixmap(basePath + "clock_10.png"));
}


// Entrance Renderer
EntranceRenderer::EntranceRenderer(const Entrance *entrance)
{
    this->entr = entrance;

    this->rect = new RoundedRectRenderer(entrance, "", QColor(0,0,0,150));
}

void EntranceRenderer::render(QPainter *painter)
{
    rect->render(painter);
    QRect textRect(entr->getx()+2, entr->gety()+1, 16, 20);
    QRect imgRect(entr->getx(), entr->gety(), 20, 20);

    QString basePath(QCoreApplication::applicationDirPath() + "/CoinKiller_data/entrances/");

    switch (entr->getEntrType())
    {
    case 0: case 1:
        painter->drawText(textRect, "N", Qt::AlignLeft | Qt::AlignBottom);
        painter->drawPixmap(imgRect, QPixmap(basePath + "normal.png"));
        break;
    case 2:
        painter->drawPixmap(imgRect, QPixmap(basePath + "door_exit.png"));
        break;
    case 3:
        painter->drawPixmap(imgRect, QPixmap(basePath + "pipe_up.png"));
        break;
    case 4:
        painter->drawPixmap(imgRect, QPixmap(basePath + "pipe_down.png"));
        break;
    case 5:
        painter->drawPixmap(imgRect, QPixmap(basePath + "pipe_left.png"));
        break;
    case 6:
        painter->drawPixmap(imgRect, QPixmap(basePath + "pipe_right.png"));
        break;
    case 7:
        painter->drawText(textRect, "F", Qt::AlignLeft | Qt::AlignBottom);
        painter->drawPixmap(imgRect, QPixmap(basePath + "down.png"));
        break;
    case 8:
        painter->drawText(textRect, "G", Qt::AlignLeft | Qt::AlignBottom);
        painter->drawPixmap(imgRect, QPixmap(basePath + "down.png"));
        break;
    case 9:
        painter->drawText(textRect, "S", Qt::AlignLeft | Qt::AlignBottom);
        painter->drawPixmap(imgRect, QPixmap(basePath + "normal.png"));
        break;
    case 10:
        painter->drawText(textRect, "S", Qt::AlignLeft | Qt::AlignBottom);
        painter->drawPixmap(imgRect, QPixmap(basePath + "swimming.png"));
        break;
    case 20:
        painter->drawText(textRect, "J", Qt::AlignLeft | Qt::AlignBottom);
        painter->drawPixmap(imgRect, QPixmap(basePath + "up.png"));
        break;
    case 21:
        painter->drawText(textRect, "V", Qt::AlignLeft | Qt::AlignBottom);
        painter->drawPixmap(imgRect, QPixmap(basePath + "up.png"));
        break;
    case 23: case 25: case 26:
        painter->drawText(textRect, "B", Qt::AlignLeft | Qt::AlignBottom);
        painter->drawPixmap(imgRect, QPixmap(basePath + "normal.png"));
        break;
    case 24:
        painter->drawText(textRect, "J", Qt::AlignLeft | Qt::AlignBottom);
        painter->drawPixmap(imgRect, QPixmap(basePath + "left.png"));
        break;
    case 27:
        painter->drawPixmap(imgRect, QPixmap(basePath + "door_entrance.png"));
        break;
    default:painter->drawText(textRect, "?", Qt::AlignLeft | Qt::AlignBottom);
        painter->drawPixmap(imgRect, QPixmap(basePath + "unknown.png"));
        break;
    }

    painter->setFont(QFont("Arial", 7, QFont::Normal));
    painter->drawText(textRect, QString("%1").arg(entr->getid()), Qt::AlignLeft | Qt::AlignTop);
}
