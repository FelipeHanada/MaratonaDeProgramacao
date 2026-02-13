#include <bits/stdc++.h>
using namespace std;


/*
two strings p and q are anagrams of each other iff.
    p.cnt(c) = q.cnt(c) for each character c

- for a string s, a reducible anagram s' is such that:
    for some index i (0<i<n-1), s[0..i].cnt(c) == s'[0..i].cnt(c) for all char c
- therefore, s has an irreducible anagram iff.
    for some anagram s'
    for all indices i (0<i<n-1),
        s[0..i].cnt(c) == s'[0..i].cnt(c) for some char c

- single char strings always have an irreducible anagram (itself)
- s = xWy (different chars on the begining and the end) always have an irreducible anagram 
    that is: s' = yWx, for every index i
        s[0..i].cnt(x) < s[0..i].cnt(x) (since we removed x from the begining)
- s with atleast three different chars always have an irreducible anagram
    WLOG, suppose that s starts and end with a char x and y is the last distinct char.
    we can build s' such that, s' = cnt(y)*y | cnt(x)*x | rest
*/

int main() {
    string s;
    cin >> s;

    vector<vector<int>> prefix(26, vector<int>(s.size()+1, 0));
    for (int i=1; i<=s.size(); i++) {
        prefix[s[i-1]-'a'][i]++;
        
        for (int j=0; j<26; j++) {
            prefix[j][i] += prefix[j][i-1];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;

        if (l == r-1 || s[l] != s[r-1]) {
            // single char or different ends
            cout << "Yes\n";
        } else {
            int diff = 0;
            for (int i=0; i<26; i++) {
                if (prefix[i][r] - prefix[i][l] > 0) diff++;
            }

            if (diff > 2) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
}