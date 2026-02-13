#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define _1 first
#define _2 second

void precompute() {

}

/*
7 = 2 + 2 + 3

2
3
4
5


*/

void solve() {
    int n, k;
    cin >> n >> k;
    int ones = 0, twos = 0, zeros;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        if (x == 1) ones++;
        else if (x == 2) twos++;
    }
    zeros = n - ones - twos;

    int r = k - (ones + twos * 2);
    if (r == 0 || (r > 0 && (r % 2 == 0 || r % 3 == 0))) {
        cout << "-1\n";
    } else {
        for (int i=0; i<zeros; i++) cout << "0 ";
        for (int i=0; i<twos; i++) cout << "2 ";
        for (int i=0; i<ones; i++) cout << "1 ";
        cout << '\n';
    }
}

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #endif

    int t;
    cin >> t;
    precompute();
    while (t--) {
        solve();
    }
}