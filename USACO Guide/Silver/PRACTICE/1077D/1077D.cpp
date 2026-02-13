#include <bits/stdc++.h>
using namespace std;


int n, k;
map<int, int> s;
multiset<pair<int, int>> ms;

bool check(int x) {
    // it is possible to an array t cut x times?

    int remaining = k;
    for (auto it = ms.rbegin(); remaining > 0 && it != ms.rend(); it++) {
        if (it->first / x == 0) return false;
        remaining -= it->first / x;
    }

    return (remaining <= 0);
}


int main() {
    cin >> n >> k;

    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        s[x]++;
    }

    for (auto x : s) {
        ms.insert(make_pair(x.second, x.first));
    }

    int l=0, r=2e5;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    l--;

    vector<int> ans;
    for (auto it = ms.rbegin(); ans.size() < k && it != ms.rend(); it++) {
        for (int i=0; ans.size() < k && i<it->first/l; i++) {
            ans.push_back(it->second);
        }
    }

    for (int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}
