#include "Player.h"
#include "Enemy.h"
using namespace std;

Player::Player(string n, int h)
    : name(n),GameCharacter(h){}

Player::~Player();

void Player::addScore(int s){
    score+=s;
}
