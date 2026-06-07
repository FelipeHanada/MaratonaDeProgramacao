#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<vector<int>> childs;
vector<int> height, first;
vector<pair<int, int>> euler;
void dfs(int curr) {
    first[curr] = euler.size();
    euler.push_back({ height[curr], curr });
    for (int child : childs[curr]) {
        height[child] = height[curr] + 1;
        dfs(child);
        euler.push_back({ height[curr], curr });
    }
}
vector<vector<pair<int, int>>> st;
int flog2(int x) { return __builtin_clz(1) - __builtin_clz(x); }
pair<int, int> st_min(int l, int r) {
    if (l == r) return st[0][l];
    int k = flog2(r - l);
    return min(st[k][l], st[k][r - (1<<k)]);
}


int main() {
    cin >> n >> q;
    childs.resize(n);
    for (int i=1; i<n; i++) {
        int p; cin >> p; p--;
        childs[p].push_back(i);
    }

    first.resize(n);
    height.resize(n);
    height[0] = 0;
    dfs(0);

    st.push_back(euler);
    for (int k=1; (1<<k) <= int(euler.size()); k++) {
        st.push_back(vector<pair<int, int>>());
        for (int i=0; i + (1<<(k-1)) < int(st[k-1].size()); i++) {
            st.back().push_back(
                min(st[k-1][i], st[k-1][i + (1<<(k-1))])
            );
        }
    }

    while (q--) {
        int a, b; cin >> a >> b; a--; b--;
        int l = min(first[a], first[b]), r = max(first[a], first[b]);
        auto [ h, lca ] = st_min(l, r + 1);
        cout << lca + 1 << '\n';
    }
}