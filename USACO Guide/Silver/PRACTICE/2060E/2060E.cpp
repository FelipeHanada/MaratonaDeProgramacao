#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define pii pair<int, int>
#define f first
#define s second

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    int a, b;
    vector<pii> edges1;
    vector<set<int>> adj1(n);
    for (int i=0; i<m1; i++) {
        cin >> a >> b;
        edges1.push_back(make_pair(a-1, b-1));
        adj1[a-1].insert(b-1);
        adj1[b-1].insert(a-1);
    }

    vector<vector<int>> adj2(n);
    for (int i=0; i<m2; i++) {
        cin >> a >> b;
        adj2[a-1].push_back(b-1);
        adj2[b-1].push_back(a-1);
    }

    int id2 = 0;
    vector<int> c2(n, -1);
    for (int i=0; i<n; i++) {
        if (c2[i] != -1) continue;
        deque<int> stk = {i}; c2[i] = id2;
        while (!stk.empty()) {
            int curr = stk.back(); stk.pop_back();
            for (int neighbor : adj2[curr]) {
                if (c2[neighbor] != -1) continue;
                stk.push_back(neighbor);
                c2[neighbor] = id2;
            }
        }
        id2++;
    }

    ll ans = 0;
    for (pii edge : edges1) {
        if (c2[edge.f] != c2[edge.s]) {
            ans++;
            adj1[edge.f].erase(edge.s);
            adj1[edge.s].erase(edge.f);
        }
    }

    int id1 = 0;
    vector<int> c1(n, -1);
    for (int i=0; i<n; i++) {
        if (c1[i] != -1) continue;
        deque<int> stk = {i}; c1[i] = id1;
        while (!stk.empty()) {
            int curr = stk.back(); stk.pop_back();
            for (int neighbor : adj1[curr]) {
                if (c1[neighbor] != -1) continue;
                stk.push_back(neighbor);
                c1[neighbor] = id1;
            }
        }
        id1++;
    }

    cout << ans + id1 - id2 << '\n';
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
