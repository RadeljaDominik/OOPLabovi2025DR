#ifndef PLAYER_H
#define PLAYER_H
#include "GameCharacter.h"
using namespace std;

class Enemy;

class Player : public GameCharacter{
protected:
    int score;
    string name;
public:
    Player(string name, int health);
    virtual ~Player();
    virtual void attackEnemy(Enemy* target)=0;
    void addScore(int s);
};

#endif
