#include <bits/stdc++.h>
using namespace std;
 
 
#define ll long long
#define _1 first
#define _2 second
 
 
void precompute() {
}
 
void solve() {
    int n, k;
    cin >> n >> k;
    unordered_set<int> s;
    vector<int> a;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        if (!s.count(x)) {
            a.push_back(x);
            s.insert(x);
        }
    }
    sort(a.begin(), a.end());
 
    unordered_set<int> marked;
    vector<int> ans;
    bool ok = true;
    for (int i=0; i<a.size() && ok; i++) {
        if (marked.count(a[i])) continue;
        ans.push_back(a[i]);

        for (int j=a[i]; j<=k && ok; j+=a[i]) {
            if (!s.count(j)) {
                ok = false;
            }
            marked.insert(j);
        }
    }
 
    if (!ok) {
        cout << "-1\n";
    } else {
        cout << ans.size() << '\n';
        for (int x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }
 
}
 
int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #endif
 
    int t;
    cin >> t;
    precompute();
    while (t--) {
        solve();
    }
}