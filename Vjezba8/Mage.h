#ifndef MAGE_H
#define MAGE_H
#include "Player.h"
using namespace std;

class Mage : public Player{
protected:
    int mana;
public:
    Mage(string name, int mana);
    void attackEnemy(Enemy* target) override;
    void specialAbility() override;
    void displayStatus() const override;
};

#endif
