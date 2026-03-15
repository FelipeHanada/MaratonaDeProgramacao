#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define _0 first
#define _1 second;


int main() { _
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for (char c : s) {
        cnt[c - 'a']++;
    }

    int big = 0;
    for (int i=0; i<26; i++) {
        big = max(big, cnt[i]);
    }

    for (char c : s) {
        if (cnt[c - 'a'] == big) continue;
        cout << c;
    }
    cout << '\n';
}
