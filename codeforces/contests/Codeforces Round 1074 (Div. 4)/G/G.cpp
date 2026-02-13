#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

/*
(i, j, k) = sum of mex(a[l]) forall l != i,k
            if a[i][j] <= mex(a[i]) and a[i].count(a[i][j]) == 1, sum mex(a[i])-1
            if a[i][j] == mex(a[k])

*/

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> a(n);
    int total = 0;
    map<int, int> gcnt;
    vector<map<int, int>> cnt(n);
    vector<array<int,2>> sweet(n);
    for (int i=0; i<n; i++) {
        int size;
        cin >> size;
        total += size;
        a[i].assign(size, 0);
        for (int j=0; j<size; j++) {
            cin >> a[i][j];
            cnt[i][a[i][j]]++;
            gcnt[a[i][j]]++;
        }
        
        int mex = 0;
        auto it = cnt[i].begin();
        while (it != cnt[i].end() && it->first == mex) {
            mex++;
            it++;
        }

        sweet[i][0] = mex;
        mex++;
        while (it != cnt[i].end() && it->first == mex) {
            mex++;
            it++;
        }
        sweet[i][1] = mex;
    }

    ll ans = 0;
    for (int i=0; i<n; i++) {
        // for every element a[i][j] in a[i], there are n-1 triples that removes a[i][j] from a[i]
        for (int j=0; j<a[i].size(); j++) {
            if (a[i][j] < sweet[i][0] && cnt[i][a[i][j]] == 1) {
                ans += a[i][j] * (n-1);
            } else {
                // wont change mex
                ans += sweet[i][0] * (n-1); // sum mex
            }
        }

        // for every element sweet[i][0] added, mex is set to sweet[i][1]
        ans += (ll)sweet[i][1] * (gcnt[sweet[i][0]]);
        ans += (ll)sweet[i][0] * (total - gcnt[sweet[i][0]] - a[i].size());

        // (total - a[i].size()) * (n-2)
        ans += (ll)sweet[i][0] * (total - a[i].size()) * (n-2);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    int tt;
    cin >> tt;
    while (tt--) solve();    
    return 0;
}
