#include <algorithm>
#include<bits/stdc++.h>
#include <utility>
#include <vector>
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
typedef long long ll;
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

       sort(nums.begin(),nums.end());

       
        
    }
};     

int main()
{
    FastIO;
    vector<int> nums = {2,7,11,15};

    Solution s;

    vector<int>ans = s.twoSum(nums,9);

    for(int i:ans) cout << i << " ";

    return 0;
}
    