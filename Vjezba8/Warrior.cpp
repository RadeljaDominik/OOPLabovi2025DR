#include "Warrior.h"
#include "Enemy.h"
using namespace std;

Warrior::Warrior(string n)
    :Player(n,120),shieldActive(false){}

void Warrior::attackEnemy(Enemy* target){
    if(!target || !target->isAlive()){return};
    target ->takeDamage(20);
    if(!target->isAlive()){
        addScore(10);
    }
}

void Warrior::specialAbility(){
    shieldActive = true;
    cout<<name<<" lifts his shield!"<<endl;
}

void Warrior::displayStatus() const{
    cout<<name<<endl<<"Class : [Warrior]"<<endl<<"HP: "<<health<<endl;
}
