#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<array<ll,26>> a(n);
    array<ll,26> cnt;
    fill(cnt.begin(), cnt.end(), 0);
    for (int i=0; i<n; i++) {
        fill(a[i].begin(), a[i].end(), 0);
        string s; cin >> s;
        for (char c : s) {
            cnt[c-'A']++;
            a[i][c-'A']++;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<26; j++) cnt[j] -= a[i][j];
    
        ll k = INT64_MAX;
        for (int j=0; j<26 && k >= 0; j++) {
            // we have cnt[letter]*m pieces available
            // we use a[i][j] to make one sign for the missing pkg
            // and use the rest to build the other signs (costing cnt[j])
            if (cnt[j]*m - a[i][j] < 0) {
                k = -1;
                continue;
            }
            if (!cnt[j]) continue;
            k = min(k, (cnt[j]*m - a[i][j]) / cnt[j]);
        }
        
        for (int j=0; j<26; j++) cnt[j] += a[i][j];
        
        if (k < 0) cout << "-1 ";
        else cout << k << ' ';
    }
    cout << '\n';
}