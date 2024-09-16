#include <bits/stdc++.h>
using namespace std;


struct square_matrix {
    vector<vector<int>> data;
    
    square_matrix(int n) {
        data = vector<vector<int>>(n, vector<int>(n, 0));
    }

    int size() const {
        return data.size();
    }
    
    const int get(int i, int j) const {
        return data[i][j];
    }

    void set(int i, int j, int x) {
        data[i][j] = x;
    }

    void add(int i, int j, int x) {
        data[i][j] += x;
    }

    square_matrix friend operator*(const square_matrix &a, const square_matrix &b) {
        if (a.size() != b.size())
            return square_matrix(0);

        int n = a.size();
        square_matrix r(n);

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                r.set(i, j, 0);

                for (int k=0; k<n; k++) {
                    r.add(i, j, a.get(i, k) * b.get(k, j));
                }
            }
        }

        return r;
    }
};


square_matrix paths_fixed_length(square_matrix adj, int len) {
    square_matrix r(adj.size());
    for (int i=0; i<r.size(); i++)
        r.set(i, i, 1);

    while (len > 0) {
        if (len & 1)
            r = r * adj;

        len >>= 1;
        adj = adj * adj;
    }

    return r;
}

int main() {
    freopen("pathfixedlength.in", "r", stdin);

    int n, m, l;
    cin >> n >> m >> l;

    square_matrix adj(n);
    
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;

        adj.add(a, b, 1);
        adj.add(b, a, 1);
    }

    square_matrix paths = paths_fixed_length(adj, l);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << "from " << i << " to " << j << " there are " << paths.get(i, j) << " paths" << endl;
        }
    }
}
