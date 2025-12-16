#include "Gnome.h"
using namespace std;

Gnome::Gnome(string n)
    :Enemy(3,n,90){}

void Gnome::attackPlayer(Player* target){
    if(!target || !target -> isAlive()){return;}
    target -> takeDamage(5*difficulty);
}

void Gnome::specialAbility(){
    cout<<name<<" blows into his horn!";
}

void Gnome::displayStatus(){
    cout<<name<<endl<<"Class : [Gnome]"<<endl<<"HP: "<<health<<endl;
}
