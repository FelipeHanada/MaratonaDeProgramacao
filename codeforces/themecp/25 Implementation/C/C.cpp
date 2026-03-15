#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k, d;
        cin >> n >> k >> d;
        vector<int> a(n), v(k);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<k; i++) cin >> v[i];

        int best = 0;
        for (int i=0; i<min(2*n+1, d); i++) {
            int curr = (d - i - 1)/2;
            for (int j=0; j<n; j++) curr += (a[j] == j+1);
            best = max(best, curr);

            for (int j=0; j<v[i%k]; j++) a[j]++;
        }

        cout << best << '\n';
    }
}