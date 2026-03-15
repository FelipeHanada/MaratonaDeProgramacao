#include <bits/stdc++.h>
using namespace std;


using ll = long long;

/*
7
1 2 1 2 1 2 1
6 8 3 1 5 1 5

1: 6 5 5 3
2: 8 1 1
*/

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> u(n), s(n);
        for (int i=0; i<n; i++) cin >> u[i];
        for (int i=0; i<n; i++) cin >> s[i];

        vector<vector<int>> a(n);
        for (int i=0; i<n; i++) {
            a[u[i]-1].push_back(s[i]);
        }
        for (int i=0; i<n; i++) sort(a[i].rbegin(), a[i].rend());

        vector<int> ans(n+1, 0);
        for (auto v : a) {
            
        }
    }
}
