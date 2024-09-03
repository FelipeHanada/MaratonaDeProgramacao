#include <bits/stdc++.h>

using namespace std;


int main() {
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);

    int n;
    cin >> n;

    vector<vector<int>> adj_matrix(n);
    int a, b;
    for (int i=0; i<n-1; i++) {
        cin >> a >> b;
        a--; b--;
        adj_matrix[a].push_back(b);
        adj_matrix[b].push_back(a);
    }

    int max_neighbors = INT32_MIN;
    for (int i=0; i<n; i++) {
        max_neighbors = max(max_neighbors, (int) adj_matrix[i].size() + 1);
    }

    cout << max_neighbors << endl;
}
