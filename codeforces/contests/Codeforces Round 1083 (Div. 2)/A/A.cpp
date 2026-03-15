#include <bits/stdc++.h>
using namespace std;



using ll = long long;
#define _1 first
#define _2 second

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int big = -1;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            if (a[i] == n) big = i;
        }
    
        if (a[0] != n) swap(a[0], a[big]);
    
        for (int x : a) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}
