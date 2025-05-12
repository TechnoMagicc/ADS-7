// Copyright 2021 NNTU-CS
#include "train.h"
class Train {
  private:
    struct Car {
        bool light;
        Car* next;
        Car* prev;
    };
    
    int countOp;
    Car* first; 

  public:
    Train() : countOp(0), first(nullptr) {}

    void addCar(bool light) {
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

    int getLength() {
        if (!first) return 0;
        int length = 1;
        Car* current = first->next;
        countOp = 0;
        while (current != first) {
            length++;
            current = current->next;
            countOp++;
        }
        return length;
    }

    int getOpCount() {
        return countOp;
    }

    ~Train() {
        if (first) {
            Car* current = first;
            Car* next;
            do {
                next = current->next;
                delete current;
                current = next;
            } while (current != first);
        }
    }
};

void runExperiment(int n, std::vector<int>& operations, std::vector<double>& times, int lightState) {
    Train train;
    for (int i = 0; i < n; ++i) {
        train.addCar(lightState == 0 ? false : true);
    }
    
    auto start = std::chrono::high_resolution_clock::now();
    int ops = train.getLength();
    auto end = std::chrono::high_resolution_clock::now();
    
    operations.push_back(train.getOpCount());
    times.push_back(std::chrono::duration<double, std::milli>(end - start).count());
}
