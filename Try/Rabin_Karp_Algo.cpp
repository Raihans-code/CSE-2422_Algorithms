#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

void Rabin_Karp(string txt, string p, int q) {
    int n = txt.size();
    int m = p.size();
    int d = 256;  // Number of characters in alphabet
    
    if (m > n || m == 0) {
        cout << "Invalid pattern or text" << endl;
        return;
    }
    
    // Calculate hash for pattern
    int hashP = 0;
    int hashT = 0;
    int h = 1;
    
    // Calculate h = d^(m-1) % q
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }
    
    // Calculate initial hash for pattern and first window of text
    for (int i = 0; i < m; i++) {
        hashP = (d * hashP + p[i]) % q;
        hashT = (d * hashT + txt[i]) % q;
    }
    
    
    
    // Slide the pattern over text
    vector<int> matches;
    
    for (int i = 0; i <= n - m; i++) {
        // If hashes match, verify character by character
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
                cout << "Pattern found at index: " << i << endl;
            }
        }
        
        // Calculate hash for next window
        if (i < n - m) {
            hashT = (d * (hashT - txt[i] * h) + txt[i + m]) % q;
            
            // Make sure hash is positive
            if (hashT < 0) {
                hashT += q;
            }
        }
    }
    
    if (matches.empty()) {
        cout << "Pattern not found" << endl;
    } else {
        cout << "Total matches: " << matches.size() << endl;
    }
}

// Alternative simpler version using your approach but corrected
void Rabin_Karp_Simple(string txt, string p, int q) {
    int n = txt.size();
    int m = p.size();
    
    if (m > n) {
        cout << "Pattern longer than text" << endl;
        return;
    }
    
    // Calculate pattern hash (your method corrected)
    int hashP = 0;
    for (int i = 0; i < m; i++) {
        // Convert char to position (a=1, b=2, etc.)
        int charVal = tolower(p[i]) - 'a' + 1;
        hashP = (hashP * 10 + charVal) % q;  // Using base 10 for simplicity
    }
    
    cout << "Pattern hash: " << hashP << endl;
    
    // Search in text
    vector<int> matches;
    
    for (int i = 0; i <= n - m; i++) {
        // Calculate hash for current window
        int hashT = 0;
        for (int j = 0; j < m; j++) {
            int charVal = tolower(txt[i + j]) - 'a' + 1;
            hashT = (hashT * 10 + charVal) % q;
        }
        
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
    if (matches.empty()) {
        cout << "Pattern not found" << endl;
    } else {
        cout << "Pattern found at indices: ";
        for (int pos : matches) {
            cout << pos << " ";
        }
        cout << endl;
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    int prime = 101;  // A prime number for modulus
    
    cout << "Using efficient rolling hash method:" << endl;
    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;
    Rabin_Karp(text, pattern, prime);
    
    cout << "\nUsing simpler (but slower) method:" << endl;
    Rabin_Karp_Simple(text, pattern, prime);
    
    // Another example
    cout << "\n--- Another Example ---" << endl;
    text = "AABAACAADAABAABA";
    pattern = "AABA";
    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;
    Rabin_Karp(text, pattern, prime);
    
    return 0;
}