#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
            int n;
    cin >> n;   
    set<int> s;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    int ans = 0;
    auto it = s.begin();
    while (it != s.end() && *it == ans) {
        ans ++;
        it++;
    }
    cout << ans << '\n';
    }
}