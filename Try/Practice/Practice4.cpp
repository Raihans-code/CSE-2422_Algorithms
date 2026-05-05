#include<bits/stdc++.h>
#include <vector>
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
typedef long long ll;
using namespace std;
 
vector<int> Rabin_Karp(string txt, string p, int q,int base) {
    int n = txt.size();
    int m = p.size();
    
    if (m > n) {
        cout << "Pattern longer than text" << endl;
        return {};
    }
    
    
    int hashP = 0;
    for (int i = 0; i < m; i++) {
        
        int val = int(p[i]) ;
        hashP = (hashP * base + val) % q;  
    }
    
    cout << "Pattern hash: " << hashP << endl;
    
    
    vector<int> matches;
    
    for (int i = 0; i <= n - m; i++) {
        
        int hashT = 0;
        for (int j = 0; j < m; j++) {
            int val = int(txt[i+j]);
            hashT = (hashT * base + val) % q;
        }

        cout << "Hash for Window " << i+1 << " = " << hashT << endl;
        
        // Check if hashes match
        if (hashP == hashT) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (txt[i + j] != p[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                matches.push_back(i);
            }
        }
    }
    
    // Display results
    // if (matches.empty()) {
    //     cout << "Pattern not found" << endl;
    // } else {
    //     cout << "Pattern found at indices: ";
    //     for (int pos : matches) {
    //         cout << pos << " ";
    //     }
    //     cout << endl;
    // }
    return matches;
}    

int main()
{
    FastIO;

    string txt,pattern;

    cin >> txt >> pattern;

    vector<int> id  = Rabin_Karp(txt,pattern,101,256);

    cout << "Match Indices : ";
    for(auto u:id) cout << u << " ";
        cout << endl;

    int total_sum = 0,len = id.size(),sz = pattern.size();

    for(int i = 0;i<len;++i)
    {   
        int sum = 0;
        string w = "";
        for(int j=0;j<sz;++j)
        {
            w += txt[id[i]+j];
            sum+=int(txt[id[i]+j]);
        }
        cout << "Sum for '"<<w<<"' : " << sum << endl;
        total_sum+=sum;
    }

    cout << "Total : " << total_sum << endl;

    return 0;
}
    