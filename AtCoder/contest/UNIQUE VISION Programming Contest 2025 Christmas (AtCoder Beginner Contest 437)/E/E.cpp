#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
    int n;
    cin >> n;

    
    
    vector<vector<array<int, 2>>> adj(1);
    int new_id = 1;

    // vector<array<int, 2>> v(n);
    vector<unordered_set<int>> mark(n+1);
    vector<int> id(n+1);
    id[0] = 0;
    vector<vector<int>> val(1);
    
    for (int i=0; i<n; i++) {
    	int p, x;
        cin >> p >> x;

    	if (!mark[p].count(x)) {
            mark[p].insert(x);

    		id[i] = new_id++;
    		val.push_back({});
            adj.push_back({});
    	} else {
            id[i] = 
        }
    	
        adj[id[p]].push_back({x, id[i]});
    	val[id[i]].push_back(i);
    }
    
    for (int i=0; i<adj.size(); i++) {
    	sort(adj[i].begin(), adj[i].end());
    	reverse(adj[i].begin(), adj[i].end());
    }

    
    stack<int> dfs;
    dfs.push(0);
    while (!dfs.empty()) {
    	int curr = dfs.top(); dfs.pop();

        for (int j : val[curr]) {
            cout << j << ' ';
        }

    	for (auto [x, c] : adj[curr]) {
    		dfs.push(c);
    	}
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    solve();    
    return 0;
}
