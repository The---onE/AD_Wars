#include "EnemyActData.h"

const float ACT_SIZE = 0.1f;
const float ACT_HEIGHT = ACT_SIZE * HEIGHT;

const float ACT_CENTER = WIDTH / 2;
const float ACT_BOTTOM = 0.2f * HEIGHT;
const float BOLCK_INTERVAL = 0.01f * HEIGHT;

const float FALL_TIME = 0.05f;

const int MAX_GAP = 2;

Point getCenterByIndex(int index)
{
	Point center = Point(ACT_CENTER, ACT_BOTTOM + ACT_HEIGHT / 2 + (ACT_HEIGHT + BOLCK_INTERVAL)*index);
	return center;
}
