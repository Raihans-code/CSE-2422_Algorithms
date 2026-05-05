#include<iostream>
#include <vector>
#include "../random_int_array_generator.h"
#include <ctime>

using namespace std;

void Quick_Sort(vector<int>&arr, int length);
void Quicksort_recursion(vector<int>&arr, int low, int high);
int partition(vector<int>&arr, int low, int high);

template<typename Func>
void functionToTime(Func func, vector<int>&arr, int length) {

    clock_t start = clock();
    // Program code here  
    
    func(arr,length);


    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    cout << endl;
    std::cout << "Elapsed time: " << elapsed << " seconds." << std::endl;
}

int main() {
  
    vector<int> arr1 = generateArray(10 , 10);
    vector<int> arr2 = generateArray(100 , 100);
    vector<int> arr3 = generateArray(1000 , 1000);
    vector<int> arr4 = generateArray(10000 , 10000);
    vector<int> arr5 = generateArray(100000 , 100000);

    functionToTime(Quick_Sort,arr1,arr1.size());

    cout << "for Array 1 :" << endl;
    for(int i:arr1) cout << i << " ";
        cout << endl;

    functionToTime(Quick_Sort, arr2, arr2.size());

    cout << "for Array 2 :" << endl;
    for(int i:arr2) cout << i << " ";
        cout << endl;
    
    functionToTime(Quick_Sort, arr3, arr3.size());

    cout << "for Array 3 :" << endl;
    for(int i:arr3) cout << i << " ";
        cout << endl;
    
    functionToTime(Quick_Sort, arr4, arr4.size());

    cout << "for Array 4 :" << endl;
    for(int i:arr4) cout << i << " ";
        cout << endl;

    functionToTime(Quick_Sort, arr5, arr5.size());

    cout << "for Array 5 :" << endl;
    for(int i:arr5) cout << i << " ";
        cout << endl;

  return 0;
}

void Quick_Sort(vector<int>& arr, int length) {
    srand(time(nullptr));
    Quicksort_recursion(arr, 0, length - 1);
}

void Quicksort_recursion(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        Quicksort_recursion(arr, low, pivot_index - 1);
        Quicksort_recursion(arr, pivot_index + 1, high);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot_index = low + (rand() % (high - low + 1));

    if (pivot_index != high)
        swap(arr[pivot_index], arr[high]);

    int pivot_value = arr[high];
    int i = low;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot_value) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[high]);
    return i;
}