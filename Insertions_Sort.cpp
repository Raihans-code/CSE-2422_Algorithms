#include<iostream>
#include <vector>
#include "random_int_array_generator.h"
#include <ctime>
using namespace std;


void insertion_sort(vector<int> &arr,int length)
{
    for(int i=1;i<length;++i)
    {
        int key = arr[i];
        int  j = i - 1;

        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

template<typename Func>
void functionToTime(Func func, vector<int> arr, int length) {

    clock_t start = clock();
    // Program code here  
    
    func(arr,length);


    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Elapsed time: " << elapsed << " seconds." << std::endl;
}



int main(){

    vector<int> arr1 = generateArray(10 , 10);
    vector<int> arr2 = generateArray(100 , 100);
    vector<int> arr3 = generateArray(1000 , 1000);
    vector<int> arr4 = generateArray(10000 , 10000);
    vector<int> arr5 = generateArray(100000 , 100000);

    functionToTime(insertion_sort,arr1,arr1.size());

    cout << "for arr1 :" << endl;
    for(int i:arr1) cout << i << " ";
        cout << endl;

    functionToTime(insertion_sort, arr2, arr2.size());

    cout << "for arr2 :" << endl;
    for(int i:arr2) cout << i << " ";
        cout << endl;
    
    functionToTime(insertion_sort, arr3, arr3.size());

    cout << "for arr3 :" << endl;
    for(int i:arr3) cout << i << " ";
        cout << endl;
    
    functionToTime(insertion_sort, arr4, arr4.size());

    cout << "for arr4 :" << endl;
    for(int i:arr4) cout << i << " ";
        cout << endl;

    functionToTime(insertion_sort, arr5, arr5.size());

    cout << "for arr5 :" << endl;
    for(int i:arr5) cout << i << " ";
        cout << endl;

    return 0;
}