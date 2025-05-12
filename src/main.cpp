#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include "train.h"
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

void performExperiment(int n, std::vector<int>& opCounts, std::vector<double>& times, bool allLightsOn, bool allLightsOff) {
    Train train;
    for (int i = 0; i < n; i++) {
        bool light = allLightsOn ? true : (allLightsOff ? false : rand() % 2);
        train.addCar(light);
    }
    auto start = std::chrono::high_resolution_clock::now();
    int ops = train.getLength();
    auto end = std::chrono::high_resolution_clock::now();
    
    opCounts.push_back(train.getOpCount());
    times.push_back(std::chrono::duration<double, std::milli>(end - start).count());
}

int main() {
    std::vector<int> opCounts;
    std::vector<double> times;
    std::vector<int> lengths;
    for (int n = 2; n <= 100; n += 10) {
        performExperiment(n, opCounts, times, true, false); 
        performExperiment(n, opCounts, times, false, true); 
        performExperiment(n, opCounts, times, false, false);
        lengths.push_back(n);
    }
    plt::figure();
    plt::title("Количество операций от длины поезда");
    plt::xlabel("Длина поезда");
    plt::ylabel("Количество операций");
    plt::plot(lengths, opCounts, "r-");
    plt::save("result/plot-1.png");

    plt::figure();
    plt::title("Время вычисления от длины поезда");
    plt::xlabel("Длина поезда");
    plt::ylabel("Время (мс)");
    plt::plot(lengths, times, "b-");
    plt::save("result/plot-2.png");

    return 0;
}