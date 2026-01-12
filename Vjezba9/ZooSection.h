#ifndef ZOOSECTION_H
#define ZOOSECTION_H

#include <vector>
#include <memory>
#include <stdexcept>

using namespace std;

template <typename T>
class ZooSection {
    vector<unique_ptr<T>> animals;

public:
    void addAnimal(unique_ptr<T> animal){
        if(!animal){
            throw runtime_error("nullptr animal");
        }
        animal.push_back(move(animal));
    }
    double totalFood() const{
        double sum = 0;
        for(const auto& a : animals){
            sum += a->getDailyFood();
        }
        return sum;
    }
    size_t size() const {return animals.size();}
    T* getAnimal(size_t i) const{
        if(i>=animals.size()){
            throw out_of_range("Index");
        }
        return animals[i].get();
    }
}

#endif
