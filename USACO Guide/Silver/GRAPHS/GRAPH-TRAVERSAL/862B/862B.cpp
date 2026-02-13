#include <bits/stdc++.h>
using namespace std;


#define ll long long
constexpr int MAX_N = 1e5;
int n;
int color[MAX_N];

int main() {
    cin >> n;
    vector<vector<int>> adj(n, vector<int>());
    int a, b;
    for (int i=0; i<n-1; i++) {
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    fill_n(color, n, -1);
    stack<int> s; s.push(0);
    color[0] = 0;
    int q[2] = {1, 0};
    while (!s.empty()) {
        int curr = s.top(); s.pop();
        
        for (int next : adj[curr]) {
            if (color[next] != -1) continue;
            
            color[next] = (color[curr] == 1 ? 0 : 1);
            q[color[next]]++;
            s.push(next);
        }
    }

    ll ans = 0;
    for (int i=0; i<n; i++) {
        ans += q[(color[i] == 1 ? 0 : 1)] - adj[i].size();
    }

    cout << ans / 2 << '\n';
}