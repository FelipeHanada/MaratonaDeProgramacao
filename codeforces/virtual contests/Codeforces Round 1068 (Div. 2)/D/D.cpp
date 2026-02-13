#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define _1 first
#define _2 second

void precompute() {
}

void solve() {
    int n, k;
    cin >> n >> k;

    while (!(n&1)) n >>= 1;

    vector<pair<int, int>> segs;
    int last = 0;
    while (n) {
        if (n & 1) {
            if (last) {
                segs.back()._1++;
            } else {
                segs.push_back({1, 0});
            }
        } else {
            segs.back()._2++;
        }
        last = n & 1;
        n >>= 1;
    }

    // all prev set 1 + number of seg. connected
    // conectar sempre que vale a pena

    while (segs.size() > 1 && (k > )) {

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
