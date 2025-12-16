#ifndef ENEMY_H
#define ENEMY_H
#include "Player.h"
using namespace std;

class Enemy : public GameCharacter{
protected:
    int difficulty;
    string name;
public:
    Enemy(int difficulty, string name, int health);
    ~Enemy();
    virtual void attackPlayer(Player* target) = 0;
};

#endif
