#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    deque<int> zeros;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            zeros.push_back(i);
        }
    }

    queue<pair<int, int>> ans;
    while (!zeros.empty()) {
        int i = zeros.back(); zeros.pop_back();
        if (i == n-1 || !zeros.empty()) {
            if (!zeros.empty() && zeros.back() == i-1) zeros.pop_back();
            ans.push({i, i+1});
        } else {
            ans.push({i+1, i+2});
        }
        n--;
    }
    cout << ans.size() + 1 << '\n';
    while (!ans.empty()) {
        auto [a, b] = ans.front();
        ans.pop();
        cout << a << ' ' << b << '\n';
    }
    cout << 1 << ' ' << n << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}