#include <bits/stdc++.h>
using namespace std;

/*
there is a solution iff there is two of the same number on the array
*/
void solve(){
    int n;
    cin >> n;
    bool ok = false;
    set<int> s;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        if (s.find(x) != s.end()) ok = true;
        s.insert(x);
    }

    cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}