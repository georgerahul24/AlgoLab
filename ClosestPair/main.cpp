#include <iostream>
#include "MergeSort.hpp"
#include "ONLogN.hpp"

using namespace std;

int main() {
    PointArray *pa = new PointArray();
    pa->getPoints();
    pa->print();


    ONLogN o();

    return 0;
};
