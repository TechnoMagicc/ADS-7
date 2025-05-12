#include "train.h"
#include <iostream>
#include <cstdlib>

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
    Car* newCar = new Car{light, nullptr, nullptr};
    if (!first) {
        first = newCar;
        first->next = first;
        first->prev = first;
    } else {
        Car* last = first->prev;
        last->next = newCar;
        newCar->prev = last;
        newCar->next = first;
        first->prev = newCar;
    }
}

int Train::getLength() {
    if (!first) return 0;

    int length = 0;
    Car* current = first;
    do {
        length++;
        countOp++;
        current = current->next;
    } while (current != first);
    return length;
}

int Train::getOpCount() {
    return countOp;
}