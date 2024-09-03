#include <bits/stdc++.h>

using namespace std;


vector<vector<char>> k;

void flip(int x, int y) {
    for (int i=0; i<=x; i++)
        for (int j=0; j<=y; j++)
            k[i][j] = k[i][j] == '1' ? '0' : '1';
}

int main() {
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);

    int n;
    cin >> n;

    char m;
    for (int i=0; i<n; i++) {
        vector<char> v;
        for (int j=0; j<n; j++) {
            cin >> m;
            v.push_back(m);
        }
        k.push_back(v);
    }

    int flips = 0;
    for (int i=n-1; i>=0; i--) {
        for (int j=n-1; j>=0; j--) {
            if (k[i][j] == '1') {
                flip(i, j);
                flips++;
            }
        }
    }

    cout << flips << endl;
}
