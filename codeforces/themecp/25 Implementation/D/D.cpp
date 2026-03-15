#include <bits/stdc++.h>
using namespace std;


using ll = long long;

/*
11
0 0 0 5 0 0 0 4 0 0 11
9 2 6 0 8 1 7 0 3 0 10
*/

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];

    int start = -1;
    for (int i=0; i<n && start == -1; i++) if (b[i] == 1)
        start = i;
    
    if (start != -1) {
        bool ok = 1;
        for (int i=1; start+i < n && ok; i++) {
            ok = (b[start+i] == i + 1);
        }
       
        for (int i=0; ok && i<start; i++) if (b[i]) {
            ok = (b[i] >= n - start + 2 + i);
        }

        if (ok) {
            cout << start << '\n';
            return 0;
        }
    }

    int delta = 0;
    for (int i=0; i<n; i++) if (b[i]) {
        delta = max(delta, (2+i) - b[i]);
    }

    cout << delta + n << '\n';
}
