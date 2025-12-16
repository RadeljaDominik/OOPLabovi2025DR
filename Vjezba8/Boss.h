#ifndef BOSS_H
#define BOSS_H
#include "Enemy.h"
#include "Player.h"
using namespace std;

class Boss : public Enemy{
public:
    Boss(string name);
    void attackPlayer(Player* target) override;
    void specialAbility() override;
    void displayStatus() override;
};

#endif
