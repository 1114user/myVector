#include <iostream>
#include "myVect.h"
using namespace std;

int main() {
    myVector v;
    for (int i = 0; i < 1000; i++) {
        v.push_back(i);
    }
    myVector v1 = v;
    v1 = v1;
    myVector v2;
    v2 = v1;
    return 0;
}