#include <iostream>
using namespace std;

struct box {
    public:
    box(int length, int width, int height, double weight, int value)
        : length(length),
          width(width),
          height(height),
          weight(weight),
          value(value) {
    }
    int getLength() const {
        return length;
    }
    int getWidth() const {
        return width;
    }
    int getHeight() const {
        return height;
    }
    double getWeight() const {
        return weight;
    }
    int getValue() const {
        return value;
    }
    static int boxesSumm(const vector<box>& boxes) {
        int sum = 0;
        for (box b : boxes) {
            sum += b.getValue();
        }
        return sum;
    }
    static bool boxesIsLegit(const vector<box>& boxes, int maxL) {
        int sum = 0;
        for (box b : boxes) {
            sum += b.getLength() + b.getWidth() + b.getHeight();
        }
        return sum <= maxL;
    }
    static double boxesMaxWeight(const vector<box>& boxes, int maxV) {
        int maxWeight = 0;
        for (box b : boxes) {
            if (b.getWeight() > maxWeight && b.getLength()*b.getHeight()*b.getWidth() <= maxV) {
                maxWeight = b.getWeight();
            }
        }
        return maxWeight;
    }


    private:
        int length;
        int width;
        int height;
        double weight;
        int value;
};

int main() {
    box b1{6,5,6,4,5};
    box b2{5,4,5,1,5};
    box b3{2,3,2,10,5};
    box b4{1,1,1,5,5};
    vector<box> boxes = {b1,b2,b3,b4};
    cout << boolalpha;
    cout << "Суммарная стоимость = " << box::boxesSumm(boxes) << endl;
    cout << "Меньше? - " << box::boxesIsLegit(boxes,12000) << endl;
    cout << "Максимальный вес = " << box::boxesMaxWeight(boxes,12) << endl;
    return 0;
}
