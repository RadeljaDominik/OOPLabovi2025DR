#include "GameCharacter.h"
using namespace std;
GameCharacter::GameCharacter(int h){
    :health(h),score(0){}
}
GameCharacter::~GameCharacter(){}

void GameCharacter::takeDamage(int dmg){
    health -= dmg;
}

bool GameCharacter::isAlive(){
    return health>0;
}

int GameCharacter::getHealth(){
    return health;
}


