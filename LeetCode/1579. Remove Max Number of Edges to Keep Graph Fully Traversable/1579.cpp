#include <bits/stdc++.h>
using namespace std;


struct DSU {
    vector<int> parent;
    vector<int> rank;
    DSU(int n) {
        parent.assign(n, -1);
        rank.assign(n, 1);
    }
    int find(int i) {
        if (parent[i] == -1) return i;
        return parent[i] = find(i);
    }
    int union_set(int i, int j) {
        int pi = find(i), pj = find(j);
        if (pi == pj) return 0;

        if (rank[pi] < rank[pj]) swap(pi, pj);
        parent[pj] = pi;
        if (rank[pi] == rank[pj]) rank[pi]++;
        return 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.rbegin(), edges.rend());
        vector<vector<int>> adj1(n);
        vector<vector<int>> adj2(n);
        set<pair<int, int>> s;
        int ans = 0;
        DSU dsu(n);
        int a_edges = 0, b_edges = 0, c_edges = 0;
        for (auto e : edges) {
            int t = e[0], x = e[1] - 1, y = e[2] - 1;
            if (t == 3) {
                if (dsu.union_set(x, y)) {
                    c_edges++;
                } else {
                    ans++;
                }
                s.insert({x, y});
                adj1[x].push_back(y);
                adj1[y].push_back(x);
                adj2[x].push_back(y);
                adj2[y].push_back(x);
            } else if (t == 2) {
                if (s.count({x, y})) {
                    ans++;
                    continue;
                }
                adj2[x].push_back(y);
                adj2[y].push_back(x);
                b_edges++;
            } else {
                if (s.count({x, y})) {
                    ans++;
                    continue;
                }
                adj1[x].push_back(y);
                adj1[y].push_back(x);
                a_edges++;
            }
        }

        // test for reachability if we can
        // the graph will be a gentree
        set<int> seen;
        stack<int> dfs;
        dfs.push(0);
        seen.insert(0);
        while (!dfs.empty()) {
            auto curr = dfs.top();
            dfs.pop();
            for (int neighbor : adj1[curr]) {
                if (seen.count(neighbor)) continue;
                seen.insert(neighbor);
                dfs.push(neighbor);
            }
        }
        if (seen.size() < n) return -1;

        seen.clear();
        dfs.push(0);
        seen.insert(0);
        while (!dfs.empty()) {
            auto curr = dfs.top();
            dfs.pop();
            for (int neighbor : adj2[curr]) {
                if (seen.count(neighbor)) continue;
                seen.insert(neighbor);
                dfs.push(neighbor);
            }
        }
        if (seen.size() < n) return -1;

        return ans + (a_edges + c_edges - (n-1)) + (b_edges + c_edges - (n-1));
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges;
    edges.push_back((vector<int>){3,1,2});
    edges.push_back((vector<int>){3,2,3});
    edges.push_back((vector<int>){1,1,3});
    edges.push_back((vector<int>){1,2,4});
    edges.push_back((vector<int>){1,1,2});
    edges.push_back((vector<int>){2,3,4});
    cout << sol.maxNumEdgesToRemove(
        4,
        edges
    ) << '\n';
}