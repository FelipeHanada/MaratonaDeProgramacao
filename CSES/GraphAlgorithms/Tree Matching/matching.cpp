#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
pair<int, int> dfs(int curr, int p) {
    pair<int, int> ans = { 0, 0 };
    // ans.first = melhor resposta onde o vertice curr nao foi coberto
    // ans.second = melhor resposta onde o vertice curr foi coberto
    //              => algum dos filhos nao pode ser coberto
    //              => adiciona uma aresta nova

    vector<pair<int, int>> childs;
    int aux = 0; bool free = 0;
    for (int neighbor : adj[curr]) if (neighbor != p) {
        childs.push_back(dfs(neighbor, curr));
        if (childs.back().first >= childs.back().second) {
            aux += childs.back().first;
            free = 1;
        } else {
            aux += childs.back().second;
        }
    }

    if (free) ans.second = aux + 1;
    for (auto [x, y] : childs) {
        ans.first += max(x, y);
        if (!free) ans.second = max(ans.second, aux - y + x + 1);
    }

    return ans;
}

int main() {
    cin >> n;
    adj.resize(n);
    for (int i=0; i<n-1; i++) {
        int x, y; cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    auto [ x, y ] = dfs(0, -1);
    cout << max(x, y) << '\n';
}