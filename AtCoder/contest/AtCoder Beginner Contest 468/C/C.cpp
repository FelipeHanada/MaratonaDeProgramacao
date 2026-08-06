#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n;
    vector<int> p, q;

    cin >> n;
    p.resize(n); q.resize(n);
    for (int i=0; i<n; i++) cin >> p[i];
    for (int i=0; i<n; i++) cin >> q[i];

    auto solve = [&](const vector<int>& a) -> ll {
        ll ans = 0;
        ll p = 1; for (int i=1; i<n; i++) p *= i;
        vector<int> rem(n); iota(rem.begin(), rem.end(), 1);
        for (int i=0; i<n-1; i++) {
            for (int j=0; rem[j] != a[i] && j<rem.size(); j++) {
                ans += p;
            }

            rem.erase(find(rem.begin(), rem.end(), a[i]));

            p /= n - i - 1;
        }

        return ans;
    };


    cout << max(0LL, solve(q) - solve(p) - 1) << '\n';
}

/*
1
1
2 
2
3 1 2
3 2 1

*/
