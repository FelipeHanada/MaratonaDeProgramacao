#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    const ll NO_PATH = INT64_MAX >> 1;
    vector<vector<ll>> adj(n, vector<ll>(n, NO_PATH));
    int a, b; ll c;
    for (int i=0; i<m; i++) {
        cin >> a >> b >> c;
        adj[a-1][b-1] = adj[b-1][a-1] = min(adj[a-1][b-1], c);
    }

    vector<vector<ll>> fw(n, vector<ll>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i == j) fw[i][j] = 0;
            else fw[i][j] = adj[i][j];
        }
    }

    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
            }
        }
    }

    while (q--) {
        cin >> a >> b;
        if (fw[a-1][b-1] == NO_PATH) {
            cout << "-1\n";
        } else {
            cout << fw[a-1][b-1] << '\n';
        }
    }
}
