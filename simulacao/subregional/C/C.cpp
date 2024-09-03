#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 1e5;
vector<int> adj[MAX_N];
int v[MAX_N];

int main() {
    int n; cin >> n;
    for (int a=1; a<n; a++) {
        int b; cin >> b; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i=0; i<n; i++) {
        cin >> v[i];
    }

    vector<int> a[n];
    queue<int> q; q.emplace(0);
    vector<bool> seen(n, false); seen[0] = true;
    while (q.size() > 0) {
        int curr = q.front(); q.pop();
        a[curr].push_back(v[curr]);

        for (int x : adj[curr]) {
            if (seen[x]) continue;
            seen[x] = true;
            for (int i : a[curr]) {
                a[x].push_back(i);
            }
            q.emplace(x);
        }
    }

    cout << endl;
    cout << endl;
}