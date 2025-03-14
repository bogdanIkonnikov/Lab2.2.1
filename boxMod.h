#include <iostream>
#include <vector>
using namespace std;
class box {
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

    void setLength(int length) {
        box::length = length;
    }

    void setWidth(int width) {
        box::width = width;
    }

    void setHeight(int height) {
        box::height = height;
    }

    void setWeight(double weight) {
        box::weight = weight;
    }

    void setValue(int value) {
        box::value = value;
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
    static bool canBoxesInsert(vector<box> boxes){
        box buf(0,0,0,0,0);
        for (int j = boxes.size() - 1; j > 0; j--){
            for(int i = 0; i < j; i++){
                if (boxes[i].getHeight() > boxes[i+1].getHeight() &&
                    boxes[i].getLength() > boxes[i+1].getLength() &&
                    boxes[i].getWidth() > boxes[i+1].getWidth()) {
                    buf = boxes[i];
                    boxes[i] = boxes[i+1];
                    boxes[i+1] = buf;
                }
            }
        }
        int l = 0,w = 0,h = 0;
        for (box b : boxes){
            if (b.getLength() > l && b.getWidth() > w && b.getHeight() > h) {
                l = b.getLength();
                w = b.getWidth();
                h = b.getHeight();
            } else {
                return false;
            };
        }
        return true;
    }
    bool operator==(const box& b) const {
        return length == b.length && width == b.width && height == b.height && weight == b.weight && value == b.value;
    }
    friend std::ostream& operator<<(std::ostream& os, const box& box){
        os << "Длина коробки = " << box.length
           << ", ширина = " << box.width
           << ", высота = " << box.height
           << ", вес = " << box.weight
           << ", стоимость содержимого = " << box.value << " коп.";
        return os;
    }
    friend std::istream& operator>>(std::istream& is, box& box){
        cout << "\nВведите \n";
        cout << "Длину: ";
        is >> box.length;
        cout << "\nШирину: ";
        is >> box.width;
        cout << "\nВысоту: ";
        is >> box.height;
        cout << "\nВес: ";
        is >> box.weight;
        cout << "\nСтоимость: ";
        is >> box.value;
        return is;
    }



private:
    int length;
    int width;
    int height;
    double weight;
    int value;
};
