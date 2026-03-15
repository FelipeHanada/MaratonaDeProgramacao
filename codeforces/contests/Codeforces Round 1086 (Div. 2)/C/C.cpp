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
        vector<int> c(n), p(n);
        for (int i=0; i<n; i++) {
            cin >> c[i] >> p[i];
        }

        vector<float> best(n);
        float right = 0;
        for (int i=n-1; i>=0; i--) {
            best[i] = c[i] + (1 - p[i]/100.0)*right;
            right = max(right, best[i]);
        }

        cout << fixed << setprecision(9) << right << '\n';
    }
}