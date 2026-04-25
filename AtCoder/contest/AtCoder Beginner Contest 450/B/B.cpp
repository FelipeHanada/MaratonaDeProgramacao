#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector c(n, vector<ll>(n));
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int x;
            cin >> x;
            c[i][j] = c[j][i] = x;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            for (int k=j+1; k<n; k++) {
                if (c[i][j] + c[j][k] < c[i][k]) {
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }

    cout << "No\n";
}
