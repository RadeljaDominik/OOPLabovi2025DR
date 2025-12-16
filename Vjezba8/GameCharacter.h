#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H
#include <string>
#include <iostream>
using namespace std;
class GameCharacter{
private:
    int health;
    int score;
public:
    GameCharacter(int health);
    virtual ~GameCharacter();
    virtual void displayStatus() const = 0;
    virtual void specialAbility() const = 0;
    void takeDamage(int dmg);
    bool isAlive() const;
    int getHealth() const;
    string getName() const;
};
#endif
