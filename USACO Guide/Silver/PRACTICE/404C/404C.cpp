#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> d(n);
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        d[x].push_back(i);
    }

    if (d[0].size() != 1 || d[1].size() > k) {
        cout << "-1";
        return 0;
    }
    for (int i=2; i<n; i++) {
        if (d[i].size() > (k-1)*d[i-1].size()) {
            cout << "-1\n";
            return 0;
        }
    }

    // podemos minimizar a quantidade de arestas incidentes em cada vértice construindo uma arvore
    // se em algum momento, a quantidade vertices que distam di ultrapassar o limite de (k-1)*quantidade de vértices que distam di-1

    queue<int> q;
    cout << n-1 << '\n';
    for (int x : d[1]) {
        cout << d[0].front() << ' ' << x << '\n';
        q.push(x);
    }

    for (int i=2; i<n; i++) {
        int available = k-1;
        for (int x : d[i]) {
            if (!available) {
                q.pop();
                available = k-1;
            }
            available--;
            cout << q.front() << ' ' << x << '\n';
        }

        while (!q.empty()) q.pop();
        for (int x : d[i]) {
            q.push(x);
        }
    }
}
