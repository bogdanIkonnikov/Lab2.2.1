#include <iostream>
#include "boxMod.h"
#include <vector>
using namespace std;
class Container {
public:
    Container(int length, int width, int height, int weight, double maxWeight):
    length(length),
    width(width),
    height(height),
    weight(weight),
    maxWeight(maxWeight),
    boxes() {}
    void add(box b) {
        if (weight + b.getWeight() <= maxWeight) {
            boxes.push_back(b);
        }
        else {
            throw new exception(); //разобраться с исключениями
        }
    }
    box get(int i) {
        return boxes[i];
    }

private:
    vector<box> boxes;
    int width, height, length;
    double weight, maxWeight;
};