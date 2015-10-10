#include "InformationData.h"

const string INFORMATION_FONT = "fonts/Marker Felt.ttf";
const int INFORMATION_FONTSIZE = 100;

const Color3B INFORMATION_COLOR = Color3B::BLACK;

const Point TIME_POSITION = Point(0, HEIGHT * 5 / 6);
const Point TIME_ANCHOR = Point(0, 0.5);
const float TIME_SIZE = 0.05f;
const Color3B TIME_COLOR = Color3B::BLACK;

const Color3B SELF_HEALTH_COLOR = Color3B::WHITE;
const Point SELF_HEALTH_POSITION = Point(WIDTH / 4, HEIGHT);

const Color3B ENELM_HEALTH_COLOR = Color3B::WHITE;
const Point ENEMY_HEALTH_POSITION = Point(WIDTH * 3 / 4, HEIGHT);

const string SELF_HEALTH_IMG = "health.png";
const string ENEMY_HEALTH_IMG = "enemy.png";

const float HEALTH_SIZE = 0.06f;

const float INFORMATION_SIZE = 0.04f;
const Color3B ATK_COLOR = Color3B::RED;
const Color3B DEF_COLOR = Color3B::BLUE;

const Point SELF_ATK_POSITION = Point(0, HEIGHT * 2 / 6);
const Point SELF_ATK_ANCHOR = Point(0, 1);

const Point SELF_DEF_POSITION = Point(0, HEIGHT * 2 / 6);
const Point SELF_DEF_ANCHOR = Point(0, 0);

const Point ENEMY_ATK_POSITION = Point(0, HEIGHT * 4 / 6);
const Point ENEMY_ATK_ANCHOR = Point(0, 1);

const Point ENEMY_DEF_POSITION = Point(0, HEIGHT * 4 / 6);
const Point ENEMY_DEF_ANCHOR = Point(0, 0);

const float DAMAGE_SIZE = 0.03f;
const Color3B DAMAGE_COLOR = Color3B::RED;

const Point SELF_DAMAGE_POSITION = Point(WIDTH * 1 / 4, HEIGHT*0.93f);
const Point SELF_DAMAGE_ANCHOR = Point(1, 0.5);

const Point ENEMY_DAMAGE_POSITION = Point(WIDTH * 3 / 4, HEIGHT*0.93f);
const Point ENEMY_DAMAGE_ANCHOR = Point(1, 0.5);

const Point DPS_POSITION = Point(WIDTH, HEIGHT * 2 / 6);
const Point DPS_ANCHOR = Point(1, 0.5);

const Point RANDOM_SEED_POSITION = Point(WIDTH, HEIGHT * 4 / 6);
const Point RANDOM_SEED_ANCHOR = Point(1, 0.5);