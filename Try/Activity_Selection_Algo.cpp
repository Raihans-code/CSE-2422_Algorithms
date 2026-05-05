#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
typedef long long ll;
using namespace std;

void Activity_Selection(vector<pair<int,int>>&v){

    int sz = v.size();

    sort(v.begin(), v.end());   // sort by finish time

    vector<pair<int,int>> ans;
    ans.push_back({v[0].second, v[0].first});  // add first interval

    int last_finish = v[0].first;  // track last finish time

    for(int i = 1; i < sz; ++i)
    {
        if(v[i].second >= last_finish)  // if current start >= last finish
        {
            ans.push_back({v[i].second, v[i].first});
            last_finish = v[i].first;   // update last finish time
        }
    }

    for(auto i : ans) 
        cout << i.first << " " << i.second << endl;
}

int main()
{
    FastIO;

    int n;
    cin >> n;
    
    vector<pair<int,int>> v(n);  // (finish, start)

    for(int i = 0; i < n; ++i)
    {
        int start, finish;
        cin >> start >> finish;
        v[i].first = finish;   // store finish time first for sorting
        v[i].second = start;   // store start time second
    }

    Activity_Selection(v);
    
    return 0;
}