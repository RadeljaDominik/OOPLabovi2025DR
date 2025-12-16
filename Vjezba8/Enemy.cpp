#include "Enemy.h"
using namespace std;


Enemy::Enemy(int h, string n, int dif)
    :GameCharacter(h),name(n),difficulty(dif){}

Enemy::~Enemy(){}

