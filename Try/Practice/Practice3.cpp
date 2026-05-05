#include<bits/stdc++.h>
#include <cctype>
#include <vector>
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
typedef long long ll;
using namespace std;

void Rabin_Karp(string txt,string p,int q,int base)
{
    int n = txt.size();
    int m = p.size();

    if(m>n){
        cout << "Pattern longer than text" << endl;
        return;
    }

    int pHash = 0;

    for(int i=0;i<m;++i){
        int charVal = tolower(p[i]) - 'a' + 1;
        pHash = (pHash * base + charVal) % q;
    }

    cout << "Pattern Hash : " << pHash << endl;

    vector<int>matches;

    for(int i=0;i<=n-m;++i)
    {
        int THash = 0;
        string w = "";
        for(int j=0;j<m;++j)
        {
            w+=txt[i+j];
            int charVal = tolower(txt[i+j]) - 'a' + 1;
            THash = (THash * base + charVal) % q;
        }

        cout << "Window '"<<w<<"' Hash :" << THash << endl; 

    //     if(THash == pHash){
    //         bool match = true;

    //         for(int j=0;j<m;++j){
    //             if(txt[i+j]==p[j]){
    //                 match = false;
    //                 break; 
    //             }
    //         }
    //         if(match){
    //             matches.push_back(i);
    //         }
    //     }
    // }


    // if (matches.empty()) {
    //     cout << "Pattern not found" << endl;
    // } else {
    //     cout << "Pattern found at indices: ";
    //     for (int pos : matches) {
    //         cout << pos << " ";
    //     }
    //     cout << endl;
     }
}

int main(){
    FastIO;
    string txt,pattern;

    cin >> txt >> pattern;


    Rabin_Karp(txt,pattern,101,256);

    return 0;
}