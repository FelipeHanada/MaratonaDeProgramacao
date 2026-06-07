#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    for (int i=0; i<n; i++) {
        if (i > 0) {
            for (int j=0; j<m; j++) {
                if (a[i][j] == '.' && a[i-1][j] == 'o')
                    a[i][j] = 'o';
            }
        }
        if (i == n-1) continue;

        for (int j=m-2; j>=0; j--) {
            if (a[i][j] == '.' && a[i][j+1] == 'o' && a[i+1][j+1] == '#')
                a[i][j] = 'o';
        }

        for (int j=1; j<m; j++) {
            if (a[i][j] == '.' && a[i][j-1] == 'o' && a[i+1][j-1] == '#')
                a[i][j] = 'o';
        }
    }


    for (int i=0; i<n; i++) {
        cout << a[i] << '\n';
    }
}