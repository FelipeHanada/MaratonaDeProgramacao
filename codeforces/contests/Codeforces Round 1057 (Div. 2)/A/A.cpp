#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    set<int> a;
    int x;
    for (int i=0; i<n; i++) {
        cin >> x;
        a.insert(x);
    }
    cout << a.size() << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--)  {
        solve();
    }
}
