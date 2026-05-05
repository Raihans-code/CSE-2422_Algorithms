#include<bits/stdc++.h>


using namespace std;

int Kandanes_Max_Sub_Sum(vector<int>& arr)
{
    int arr_length = arr.size();
    int max_sum = arr[0];  // Start with first element
    int curr_sum = 0;

    for(int i = 0; i < arr_length; ++i)
    {
        curr_sum += arr[i];

        if(curr_sum > max_sum) 
            max_sum = curr_sum;

        if(curr_sum < 0) 
            curr_sum = 0;
    }

    return max_sum;
}

int main()
{
    vector<int>arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Given Array: ";
    for(int i:arr) cout << i << " ";
        cout << endl;

    cout <<"Max Subarray Sum : " <<  Kandanes_Max_Sub_Sum(arr) << endl;

    return 0;
}