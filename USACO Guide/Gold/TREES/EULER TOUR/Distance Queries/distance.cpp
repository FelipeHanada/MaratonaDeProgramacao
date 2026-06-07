#include <bits/stdc++.h>
using namespace std;


int n, q;
vector<vector<int>> adj;
vector<int> height, first;
vector<pair<int, int>> euler;
void dfs(int i, int p) {
    first[i] = euler.size();
    euler.push_back({ height[i], i });
    for (int neighbor : adj[i]) if (neighbor != p) {
        height[neighbor] = height[i] + 1;
        dfs(neighbor, i);
        euler.push_back({ height[i], i });
    }
}
vector<vector<pair<int, int>>> st;
int flog2(int x) { return __builtin_clz(1) - __builtin_clz(x); }
pair<int, int> st_min(int l, int r) {
    int k = flog2(r - l);
    return min(st[k][l], st[k][r-(1<<k)]);
}


int main() {
    cin >> n >> q;
    adj.resize(n);
    for (int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    height.resize(n);
    first.resize(n);
    height[0] = 0;
    dfs(0, -1);

    st.push_back(euler);
    for (int k=1; (1<<k)<=euler.size(); k++) {
        st.push_back(vector<pair<int, int>>());
        for (int i=0; i+(1<<k) <= euler.size(); i++) {
            st[k].push_back(min(st[k-1][i], st[k-1][i+(1<<(k-1))]));
        }
    }

    while (q--) {
        int a, b; cin >> a >> b; a--; b--;
        int l = min(first[a], first[b]), r = max(first[a], first[b]);
        auto [ hlca, lca ] = st_min(l, r+1);
        cout << height[a] + height[b] - 2 * hlca << '\n';
    }
}