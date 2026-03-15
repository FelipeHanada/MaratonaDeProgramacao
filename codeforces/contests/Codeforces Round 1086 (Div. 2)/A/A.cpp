#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        map<int,int> cnt;
        int big = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j< n; j++) {
                int x;
                cin >> x;
                cnt[x]++;
                big = max(big, cnt[x]);
            }
        }

        cout << (big <= n*(n-1) ? "YES" : "NO") << '\n';
    }
}
