#include "Mage.h"
using namespace std;

Mage::Mage(string n, int m)
    :Player(n,80),mana(100)

void Mage::attackEnemy(Enemy* target){
    if(!target || !target -> isAlive()){return;}
    if(mana>=20){
        target->takeDamage(40);
        mana-=40;
    }else{
        target->takeDamage(20);
    }
    if(!target->isAlive()){
        addScore(10);
    }
}

void Mage::specialAbility(){
    if(health>50){
        cout<<name<<" teleports!";
    }
}

void Mage::displayStatus() const{
    cout<<name<<endl<<"Class : [Mage]"<<endl<<"HP: "<<health<<" | Mana : "<<mana<<endl;
}


