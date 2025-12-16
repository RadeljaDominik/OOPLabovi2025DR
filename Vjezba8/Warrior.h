#ifndef WARRIOR_H
#define WARRIOR_H
#include "Player.h"
using namespace std;

class Warrior : public Player{
protected:
    bool shieldActive;
public:
    Warrior(string name);
    void attackEnemy(Enemy* target)override;
    void specialAbility() override;
    void displayStatus() const override;
}

#endif

