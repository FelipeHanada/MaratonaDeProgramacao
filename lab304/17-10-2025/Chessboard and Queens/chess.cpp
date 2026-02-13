#include <bits/stdc++.h>
using namespace std;


bool grid[8][8];
bool check(vector<int>& p) {
    for (int i=0; i<8; i++) {
        if (grid[i][p[i]]) return false;
    }

    for (int i=0;i<8; i++) {
        for (int j=i+1; j<8; j++) {
            if (abs(i - j) == abs(p[i] - p[j])) return false;
        }
    }
    
    return true;
}

int main() {
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            char c;
            cin >> c;
            grid[i][j] = (c == '*');
        }
    }

    vector<int> p(8);
    iota(p.begin(), p.end(), 0);

    int ans = 0;
    do {
        if (check(p)) ans++;
    } while (next_permutation(p.begin(), p.end()));

    cout << ans << '\n';
}
