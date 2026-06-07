#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<string> a, b;
inline bool valid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < n; }
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };


int main() {
    cin >> n >> q;
    a.resize(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    b = a;

    while (q--) {
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
            int alive = 0;
            for (int k=0; k<8; k++) {
                int ii = i + dx[k], jj = j + dy[k];
                if (!valid(ii, jj)) continue;
                alive += int(a[ii][jj] == '1');
            }

            if (a[i][j] == '0') {
                if (alive == 3) b[i][j] = '1';
                else b[i][j] = '0';
            } else {
                if (alive == 2 || alive == 3) b[i][j] = '1';
                else b[i][j] = '0';
            }
        }

        swap(a, b);
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
}
