#include <bits/stdc++.h>
using namespace std;


#define pii pair<int, int>
#define f first
#define s second
constexpr int MAX_N = 40000;
int b, e, p, n, m;
int distB[MAX_N];
int distE[MAX_N];
int distP[MAX_N];


int main() {
    freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);

    cin >> b >> e >> p >> n >> m;
    fill_n(distB, n, -1);
    fill_n(distE, n, -1);
    fill_n(distP, n, -1);
    vector<vector<int>> adj(n);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    queue<int> bfsB, bfsE;
    bfsB.push(0); // bessie
    distB[0] = 0;
    while (!bfsB.empty()) {
        auto i = bfsB.front();
        bfsB.pop();

        for (int neighbor : adj[i]) {
            if (distB[neighbor] >= 0) continue;
            distB[neighbor] = distB[i] + b;
            bfsB.push(neighbor);
        }
    }

    set<pii> bfsP;
    bfsE.push(1); // elise
    distE[1] = 0;
    while (!bfsE.empty()) {
        int i = bfsE.front();
        bfsE.pop();

        bfsP.insert(make_pair(distB[i] + distE[i], i));

        for (int neighbor : adj[i]) {
            if (distE[neighbor] >= 0) continue;
            distE[neighbor] = distE[i] + e;
            bfsE.push(neighbor);
        }
    }

    while (distP[n-1] < 0 && !bfsP.empty()) {
        auto [dist, i] = *bfsP.begin();
        bfsP.erase(bfsP.begin());
        if (distP[i] >= 0) continue;
        distP[i] = dist;

        for (int neighbor : adj[i]) {
            if (distP[neighbor] >= 0) continue;
            bfsP.insert(make_pair(distP[i] + p, neighbor));
        }
    }

    cout << min(distB[n-1] + distE[n-1], distP[n-1]) << '\n';
}
