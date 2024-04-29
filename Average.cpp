#include "Average.hpp"
#include <iostream>

using namespace std;

double Average(const std::vector<double>& v){
    if (static_cast<int>(v.size()) == 0) {
        return 0;
    }
    double sum = 0;
    for (double i : v){
        sum += i;
    }
    return sum / v.size();
}