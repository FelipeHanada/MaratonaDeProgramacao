#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define _1 first
#define _2 second
using ll = long long;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m, 0), b(m, 0);
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        a[x-1]++;
        b[y-1]++;
    }

    for (int i=0; i<m; i++) {
        cout << b[i] - a[i] << '\n';
    }
}