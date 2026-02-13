#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> moves(n);
    for (int i=0; i<n; i++) {
        cin >> moves[i];
    }
    sort(moves.begin(), moves.end());

    vector<bool> wins(k+1); // first wins
    wins[0] = false;
    for (int i=1; i<=k; i++) {
        wins[i] = false;
        for (int m : moves) {
            if (i - m >= 0 && !wins[i-m]) {
                wins[i] = true;
            }
        }
    }

    cout << (wins[k] ? "First" : "Second") << '\n';
}
