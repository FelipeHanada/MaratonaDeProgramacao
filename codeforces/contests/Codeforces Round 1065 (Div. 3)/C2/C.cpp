#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define _1 first
#define _2 second
#define ll long long

int flog2(int x) {
    return __builtin_clz(1) - __builtin_clz(x);
}

constexpr int MAX_N = 2e5;
int n;
int a[MAX_N], b[MAX_N];

int solve2(int i) {
    int count = 0;
    int last = 0;
    for (int j=0; j<n; j++) {
        if (b[j] & (1<<i)) {
            count++;
            last = j % 2;
        }
    }

    if (count % 2) {
        if (last) {
            return 1; // Mai
        } else {
            return -1; // Ajisai
        }
    } else {
        return 0; // Tie
    }
}

void solve() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) {
        cin >> b[i];
        b[i] ^= a[i];
    }

    int result = 0;
    for (int i=21; i>=0 && result == 0; i--) {
        result = solve2(i);
    }

    if (result == -1) {
        cout << "Ajisai\n";
    } else if (result == 1) {
        cout << "Mai\n";
    } else {
        cout << "Tie\n";
    }
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
