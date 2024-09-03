#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    bool h_farms[n];
    for (int i=0; i<n; i++) {
        char c; cin >> c;
        h_farms[i] = (c == 'H');
    }

    vector<vector<int>> adj(n);
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<vector<pair<bool, bool>>> fw(n, vector<pair<bool, bool>>(n, {false, false}));
    for (int a=0; a<n; a++) {
        fw[a][a] = {h_farms[a], !h_farms[a]};
        for (int b : adj[a]) {
            bool h = (h_farms[a] || h_farms[b]);
            bool g = (!h_farms[a] || !h_farms[b]);
            fw[a][b] = {h, g};
        }
    }
    // floyd warshall algorithm
    for (int i=0; i<n; i++) {
        // vertex i is the intermediate
        for (auto a = adj[i].begin(); next(a) != adj[i].end(); a++) {
            for (auto b = next(a); b != adj[i].end(); b++) {
                int va = *a;
                int vb = *b;
                bool h = fw[i][va].first || fw[i][vb].first;
                bool g = fw[i][va].second || fw[i][vb].second;
                fw[va][vb] = {h, g};
                fw[vb][va] = {h, g};
            }
        }
    }

    for (int i=0; i<m; i++) {
        int a, b; char c;
        cin >> a >> b >> c;
        a--; b--;

        if ((c == 'H') ? fw[a][b].first : fw[a][b].second) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << endl;
}
