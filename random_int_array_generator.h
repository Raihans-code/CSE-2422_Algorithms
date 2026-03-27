// #include "random_int_array_genarator.h"
#ifndef RANDOM_INT_ARRAY_GENERATOR
#define RANDOM_INT_ARRAY_GENERATOR
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


vector<int> generateArray(int size, int limit) {
    srand(time(0));

    if (limit > 100000) {
        cout << "Limit exceeds 10^5!\n";
        return {0};
    }

    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % limit + 1;  
    }
    return arr;
}

#endif