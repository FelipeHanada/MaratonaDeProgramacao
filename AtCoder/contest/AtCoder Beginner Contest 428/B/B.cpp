#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int max_ocurr = 0;
    map<string, int> t;
    for (int i=0; i<s.size()-k+1; i++) {
        string curr;
        for (int j=0; j<k; j++) {
            curr.push_back(s[i+j]);
        }
        t[curr]++;
        max_ocurr = max(max_ocurr, t[curr]);
    }

    cout << max_ocurr << '\n';
    for (auto [a, b] : t) {
        if (b == max_ocurr) {
            cout << a << ' ';
        }
    }
    cout << '\n';
}