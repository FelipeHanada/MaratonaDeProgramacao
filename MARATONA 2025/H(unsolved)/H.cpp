#include <bits/stdc++.h>
using namespace std;

int convert(const string& s) {
    int ans = 0;
    for (char c : s) {
        ans <<= 1;
        ans += (c - '0');
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;

    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> s;
        a[i] = convert(s);
    }

    //we run knapsack
    vector<int> dp(1<<k, 0);
    for ()

    int q;
    cin >> q;
    while (q--) {
        cin >> s;
        int e = convert(s);
    }
}
