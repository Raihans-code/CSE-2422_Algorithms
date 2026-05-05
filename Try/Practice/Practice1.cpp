#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
typedef long long ll;
using namespace std;

bool cmp1(vector<int>&v1,vector<int>&v2)
{
    if(v1[1] < v2[1]) return 1;
    else if(v1[1] == v2[1]) return (v1[0] < v2[0]);
    else return 0;
}

bool cmp2(vector<int>&v1,vector<int>&v2)
{
    if(v1[3] > v2[3]) return 1;
    else if(v1[3] == v2[3]) return (v1[2] < v2[2]);
    else return 0;
}

vector<vector<int>> Activity_Selection(vector<vector<int>>&v){

    sort(v.begin(),v.end(),cmp1);
    int sz = v.size();
    vector<vector<int>>res;
    res.push_back(v[0]);
    int last_finish = v[0][1];
    

    for(int i=1;i<sz;++i)
    {
        if(v[i][0]>=last_finish)
        {
            res.push_back(v[i]);
            last_finish = v[i][1];
        } 
    }

    return res;
}

int main()
{
    FastIO;

    vector<vector<int>>v;
    int n;
    cin >> n;

    for(int i=0;i<n;++i)
    {
        int s,f,w,p;
        cin >> s >> f >> w >> p;
        v.push_back({s,f,w,p});
    }

    vector<vector<int>>a = Activity_Selection(v);

    sort(a.begin(),a.end(),cmp2);

    int len = a.size();

    int capacity = 15;
    int stored = 0;
    for(int i=0;i<len;++i)
    {
        if(stored>=capacity) break;
        for(int j=0;j<4;++j)
        {
            cout << a[i][j] << " ";
        }

        stored += v[i][3];

    }
    

    return 0;
}
    