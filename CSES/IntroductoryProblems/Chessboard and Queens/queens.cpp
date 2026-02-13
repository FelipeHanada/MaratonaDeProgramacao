#include <bits/stdc++.h>
using namespace std;


bool grid[8][8];
bool check(const vector<int>& perm) {
    for (int i=0; i<8; i++) {
        if (grid[i][perm[i]]) return false;
    }

    for (int i=0; i<8; i++) {
        for (int j=i+1; j<8; j++) {
            if (abs(j - i) == abs(perm[j] - perm[i])) return false;
        }
    }

    return true;
}

int main() {
    char c;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            cin >> c;
            grid[i][j] = (c == '*');
        }
    }

    vector<int> perm(8);
    iota(perm.begin(), perm.end(), 0);

    int ans = 0;
    do {
        if (check(perm)) {
            ans++;
        }
    } while (next_permutation(perm.begin(), perm.end()));

    cout << ans << '\n';
}
