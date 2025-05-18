// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() {
first = nullptr;
countOp = 0;
}
void Train::addCar(bool light) {
  Car* node = new Car;
  if (!first) {
  node->light = light;
  node->prev = node;
  node->next = node;
  first = node;
  } else {
  node->light = light;
  node->next = first;
  node->prev = first->prev;
  first->prev->next = node;
  first->prev = node;
  }
}
int Train::getLength() {
  countOp = 0;
     while (true) {
        Car* SecFirst = first;
  int carriages = 1;
     SecFirst->light = true;
     SecFirst = SecFirst->next;
     countOp += 2;
  while (!SecFirst->light) {
    SecFirst = SecFirst->next;
         countOp +=2;
         ++carriages;
  }
  SecFirst->light = false;
  if (!first->light)
  return carriages;
}
}
int Train::getOpCount() {
  return countOp;
}
