#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 300;
set<int> adj[MAX_N];
int weighs[MAX_N][MAX_N];
int fw[MAX_N][MAX_N];

int main() {
    int n, m; cin >> n >> m;

    for (int i=0; i<n; i++) {
        fill_n(fw[i], n, 1e9);
    }

    pair<int, int> roads[m];
    for (int i=0; i<m; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        a--; b--;
        adj[a].insert(b);
        adj[b].insert(a);
        roads[i] = {a, b};
        weighs[a][b] = weighs[b][a] = l;
    }

    for (int a=0; a<n; a++) {
        for (int b : adj[a]) {
            for (int c : adj[b]) {
                fw[a][c] = fw[c][a] = min(fw[a][c], weighs[a][b] + weighs[b][c]);
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int a=0; a<n-1; a++) {
            if (a == i) continue;

            for (int b=0; b<n; b++) {
                int d_min = min(fw[a][b], fw[a][i] + fw[b][i]);
                // juntar 2 segmentos 2+
                
                if (adj[a].find(i) != adj[a].end()) {
                    d_min = min(d_min, weighs[a][i] + fw[b][i]);
                    // juntar um segmento 2+ e um segmento 1
                }
                if (adj[b].find(i) != adj[b].end()) {
                    d_min = min(d_min, weighs[b][i] + fw[a][i]);
                }

                fw[a][b] = fw[b][a] = d_min;
            }
        }
    }

    for (int i=0; i<m; i++) {
        int a = roads[i].first;
        int b = roads[i].second;

        cout << fw[a][b] << endl;
    }
}