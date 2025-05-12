// Copyright 2022 NNTU-CS AND V47
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

#include <iostream>
#include <random>

class Train {
 private:
  struct Car {
    bool light;
    Car *next;
    Car *prev;
  };
  int countOp;
  Car *first; 
 public:
  Train();
  ~Train();
  void addCar(bool light);
  int getLength();        
  int getOpCount();       
  void resetOpCount();
};
#endif  // INCLUDE_TRAIN_H_
