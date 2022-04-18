#include <iostream>
#include "Weight.h"

using namespace std;

int main() {
    cout << "Starting fatCat" << endl;

    Weight weight1(6, Weight::POUND, 9);
    weight1.Weight::dump();


    Weight weight2(4, Weight::KILO, 3);
    weight2.Weight::dump();
    //weight2.Weight::convertWeight(Weight)

    Weight weight3(1, Weight::SLUG, 8);
    weight3.Weight::dump();

    cout << "\nEnding fatCat" << endl;
    return 0;
}
