#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define pii pair<int, int>
#define f first
#define s second

/*

*/

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> m;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        m[x]++;
    }

    deque<int> dq(m.size());
    {
        int i=0;
        for (auto [k, v] : m) {
            dq[i++] = v;
        }
    }
    sort(dq.begin(), dq.end());

    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
