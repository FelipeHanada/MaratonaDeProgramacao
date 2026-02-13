#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

int query(int i, int j) {
    cout << "? " << i+1 << ' ' << j+1 << '\n';
    fflush(stdout);
    int x;
    cin >> x;
    return x;
}


void solve() {
    int n;
    cin >> n;

    unordered_set<int> out;
    vector<vector<int>> adj(n);
    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    while (out.size() < n) {
        for (int i=0; i<n; i++) if (!out.count(i)) {
            vector<bool> seen(n, false);
            fill_n(seen.begin(), seen.end(), false);
            queue<int> q; q.push(i);
            int start = -1;
            while (!q.empty()) {
                int curr = q.front(); q.pop();
                start = curr;
                for (int neighbor : adj[curr]) {
                    if (seen[neighbor] || out.count(neighbor)) continue;
                    seen[neighbor] = true;
                    q.push(neighbor);
                }
            }

            int end = -1;
            map<int, int> parent;
            queue<int> q; q.push(start);
            while (!q.empty()) {
                int curr = q.front(); q.pop();
                end = curr;
                for (int neighbor : adj[curr]) {
                    if (seen[neighbor] || out.count(neighbor)) continue;
                    seen[neighbor] = true;
                    q.push(neighbor);
                    parent[neighbor] = curr;
                }
            }

            int x = query(start, end);
            if (x) {
                deque<int> dq;
                    
            } else {
                while (end != start) {
                    out.insert(end);
                    end = parent[end];
                }
                out.insert(start);
            }
        }
    }
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
