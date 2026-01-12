#include "ZooKeeper.h"
#include <iostream>

int ZooKeeper::totalAnimalsServed = 0;

void ZooKeeper::processAnimal(Animal* animal) {
    std::cout << "Species: " << animal->getSpecies()
              << ", Name: " << animal->getName()
              << ", Food: " << animal->getDailyFood() << "kg\n";
    totalAnimalsServed++;
}

int ZooKeeper::getTotalAnimalsServed() {
    return totalAnimalsServed;
}
