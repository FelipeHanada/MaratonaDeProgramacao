#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 2e5;
vector<int> divs[MAX_N+1];
void precompute() {
    for (int i=2; i<=MAX_N; i++) {
        for (int j=i; j<=MAX_N; j+=i) {
            divs[j].push_back(i);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    vector<int> count(n+1, 0), big;
    for (int i=0; i<n; i++) {
        vector<int> next;
        for (int& d : divs[a[i]]) {
            count[d]++;
            if (count[d] <= i) {
                ans = max(ans, count[d]);
            } else {
                next.push_back(d);
            }
        }
 
        for (int& x : big) {
            if (count[x] <= i) {
                ans = max(ans, count[x]);
            }
        }
        big = next;
        cout << ans << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    precompute();
    while (t--) {
        solve();
    }
}