#ifndef GNOME_H
#define GNOME_H
#include "Enemy.h"
using namespace std;

class Gnome : public Enemy{
public:
    Gnome(string name);
    void attackPlayer(Player* target) override;
    void specialAbility() override;
    void displayStatus() const override;
};

#endif
