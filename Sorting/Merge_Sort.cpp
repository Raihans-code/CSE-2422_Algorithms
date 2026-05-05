#include<iostream>
#include <vector>
#include "../random_int_array_generator.h"
#include <ctime>

using namespace std;

void Merge_sort(vector<int>&arr, int length);
void Merge_sort_recursion(vector<int>&arr, int left, int right);
void Merge_sorted_arrays(vector<int>&arr, int left, int middle, int right);

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

    functionToTime(Merge_sort,arr1,arr1.size());

    cout << "for Array 1 :" << endl;
    for(int i:arr1) cout << i << " ";
        cout << endl;

    functionToTime(Merge_sort, arr2, arr2.size());

    cout << "for Array 2 :" << endl;
    for(int i:arr2) cout << i << " ";
        cout << endl;
    
    functionToTime(Merge_sort, arr3, arr3.size());

    cout << "for Array 3 :" << endl;
    for(int i:arr3) cout << i << " ";
        cout << endl;
    
    functionToTime(Merge_sort, arr4, arr4.size());

    cout << "for Array 4 :" << endl;
    for(int i:arr4) cout << i << " ";
        cout << endl;

    functionToTime(Merge_sort, arr5, arr5.size());

    cout << "for Array 5 :" << endl;
    for(int i:arr5) cout << i << " ";
        cout << endl;
}



void Merge_sort(vector<int>&arr, int length) {
  Merge_sort_recursion(arr, 0, length - 1);
}

void Merge_sort_recursion(vector<int>&arr, int left, int right) {
  if (left < right) {
    int middle = left + (right - left) / 2;
    Merge_sort_recursion(arr, left, middle);
    Merge_sort_recursion(arr, middle + 1, right);

    Merge_sorted_arrays(arr, left, middle, right);
  }
}

void Merge_sorted_arrays(vector<int>&arr,int left,int middle,int right)
{
    int left_length = middle - left + 1;
    int right_length = right - middle;

    vector<int> tmp_left(left_length);
    vector<int> tmp_right(right_length);

    int i,j,k;

    for(i=0;i<left_length;++i) tmp_left[i] = arr[left+i];
    for(i=0;i<right_length;++i) tmp_right[i] = arr[middle + 1 + i];

    for(i=0,j=0,k=left;k<=right;++k)
    {
        if((i < left_length) && ((j>=right_length) || (tmp_left[i] <= tmp_right[j]))){

            arr[k] = tmp_left[i];
            i++;
        }
        else{
            arr[k] = tmp_right[j];
            j++;
        }
    }
}