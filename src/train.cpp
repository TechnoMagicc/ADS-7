// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() : countOp(0), first(nullptr) {}
Train::~Train() {
    if (first != nullptr) {
        Car* current = first;
        do {
            Car* toDelete = current;
            current = current->next;
            delete toDelete;
        } while (current != first);
    }
}
void Train::addCar(bool lit) {
    Car* newWagon = new Car(lit);
    if (first == nullptr) {
        first = newWagon;
        first->next = first;
        first->prev = first;
    } else {
        Car* tail = first->prev;
        tail->next = newWagon;
        newWagon->prev = tail;
        newWagon->next = first;
        first->prev = newWagon;
    }
}
int Train::getLength() {
    if (first == nullptr) return 0;

    first->light = true;
    Car* current = first->next;
    int length = 1;
    countOp++;

    while (true) {
        while (!current->light) {
            current = current->next;
            countOp++;
            length++;
        }

        current->light = false;
        for (int i = 0; i < length; ++i) {
            current = current->prev;
            countOp++;
        }
        if (!current->light) {
            return length;
        }
        current = current->next;
    }
}

int Train::getOpCount() {
    return countOp;
}
