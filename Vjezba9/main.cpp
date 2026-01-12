#include <iostream>
#include <memory>
#include "ZooSection.h"
#include "ZooKeeper.h"
#include "Lion.h"
#include "Elephant.h"
#include "Dolphin.h"
#include "SeaTurtle.h"
using namespace std;

int main() {
    try {
        ZooSection<Animal> section;
        ZooKeeper keeper;

        section.addAnimal(make_unique<Lion>("Simba",5,190));
        section.addAnimal(make_unique<Elephant>("Dumbo",10,1200));
        section.addAnimal(make_unique<Dolphin>("Flipper",8,150));
        section.addAnimal(make_unique<SeaTurtle>("Leonardo",50,100));

        for (size_t i = 0; i < section.size(); ++i)
            keeper.processAnimal(section.getAnimal(i));

        cout << "\nUkupna hrana: "
                  << section.totalFood() << " kg\n";
        cout << "Nahranjeno: "
                  << ZooKeeper::getTotalAnimalsServed() << endl;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    return 0;
}
