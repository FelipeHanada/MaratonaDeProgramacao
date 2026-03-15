#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;
#define _0 first
#define _1 second

int main() {
    int n, l, r; string s;
    cin >> n >> l >> r >> s;

    vector<queue<int>> to_enter(26);
    vector<queue<int>> in(26);
    ll ans = 0;
    for (int i=0; i<n; i++) {
        int c = s[i]-'a';
        while (!to_enter[c].empty() && i - to_enter[c].front() >= l) {
            in[c].push(to_enter[c].front());    
            to_enter[c].pop();
        }
        while (!in[c].empty() && i - in[c].front() > r) in[c].pop();

        ans += in[c].size();
        to_enter[c].push(i);
    }

    cout << ans << '\n';
}
