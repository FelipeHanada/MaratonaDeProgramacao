#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int n;
    cin >> n;

    string word;
    map<char, int> ans;
    for (int i=0; i<n; i++) {
        map<char, int> f, s;

        cin >> word;
        for (auto c : word) f[c]++;

        cin >> word;
        for (auto c : word) s[c]++;

        for (char c='a'; c<='z'; c++) {
            ans[c] += max(f[c], s[c]);
        }
    }

    for (auto it : ans) {
        cout << it.second << '\n';
    }
}
