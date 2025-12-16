#include "Boss.h"
using namespace std;

Boss::Boss(string n)
    :Enemy(8,n,300){}

void Boss::attackPlayer(Player* target){
    if(!target || !target -> isAlive()){return;}
    target -> takeDamage(10*difficulty);
}

void Boss::specialAbility(){
    health+=50;
    if(health>300){
        health=300;
    }
    cout<<name<<" heals using his unfathomable force!";
}

void Boss::displayStatus(){
    cout<<name<<endl<<"Class : [Boss]"<<endl<<"HP: "<<health<<endl;
}
