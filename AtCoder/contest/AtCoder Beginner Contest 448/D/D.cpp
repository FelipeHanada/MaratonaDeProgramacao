#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define _1 first
#define _2 second
using ll = long long;


int main() { _
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    set<int> s;
    map<int, int> comp;
    for (int i=0; i<n; i++) {
        s.insert(a[i]);
    }
    {
        int i=0;
        for (int x : s) {
            comp[x] = i++;
        }
        for (int i=0; i<n; i++) a[i] = comp[a[i]];
    }

    vector<vector<int>> adj(n);
    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> cnt_in_stk(n, 0);
    vector<bool> ans(n, 0);
    set<int> dupl;
    stack<array<int,3>> stk;
    stk.push({0, 1, -1});
    while (!stk.empty()) {
        auto [curr, state, parent] = stk.top(); stk.pop();

        if (state) {
            stk.push({curr, 0, parent});
            if (cnt_in_stk[a[curr]]++) dupl.insert(a[curr]);

            ans[curr] = !dupl.empty();

            for (int neighbor : adj[curr]) if (neighbor != parent) {
                stk.push({neighbor, 1, curr});
            }

        } else {
            cnt_in_stk[a[curr]]--;
            if (cnt_in_stk[a[curr]] < 2) dupl.erase(a[curr]);
        }
    }

    for (int i=0; i<n; i++) {
        cout << (ans[i] ? "Yes" : "No") << '\n';
    }
}
