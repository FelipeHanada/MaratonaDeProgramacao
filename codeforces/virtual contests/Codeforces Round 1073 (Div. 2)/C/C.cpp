#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool ordered = true;
    bool one = s[0] == '1';
    for (int i=1; i<n; i++) {
        if (s[i] == '0' && one) ordered = false;
        if (s[i] == '1') one = true;
    }

    if (ordered) {
        cout << "Bob\n";
        return;
    }

    int i=0, j=n-1;
    set<int> ans;
    while (i < j) {
        while (i < j && s[i] != '1') i++;
        while (j > i && s[j] != '0') j--;
        if (i < j) {
            ans.insert(i);
            ans.insert(j);
            i++; j--;            
        }
    }

    cout << "Alice\n";
    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
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
