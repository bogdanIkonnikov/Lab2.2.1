#include "boxMod.h"
#include <iostream>
using namespace std;



int main() {
    box b1{6, 5, 6, 4, 5};
    box b1copy{6, 5, 6, 4, 5};
    box b2{3, 2, 3, 15, 5};
    box b3{5, 4, 5, 10, 5};
    box b4{1, 1, 1, 5, 5};
    vector<box> boxes = {b1, b2, b3, b4};
    cout << boolalpha;
    cout << "Суммарная стоимость = " << box::boxesSumm(boxes) << endl;
    cout << "Меньше? - " << box::boxesIsLegit(boxes, 12000) << endl;
    cout << "Максимальный вес = " << box::boxesMaxWeight(boxes, 12) << endl;
    cout << "Можно друг в друга? - " << box::canBoxesInsert(boxes) << endl;
    cout << "Коробки b1 и b2 равны? - " << (b1 == b2) << endl;
    cout << "Коробки b1 и b1copy равны? - " << (b1 == b1copy) << endl;
    cout << b1;
    cin >> b1;
    cout << b1;
    return 0;
}
