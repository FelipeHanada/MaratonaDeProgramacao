#include <bits/stdc++.h>
using namespace std;


/*
strategy probably is to pick the odd with largest amount
it there is none, pick the even with largest amount

*/

void solve() {
    int n;
    cin >> n;

    map<int, int> even, odds;
    int x;
    for (int i=0; i<n; i++) {
        cin >> x;
        if (x % 2) odds[x]++;
        else even[x]++;
    }

    int alice = 0, bob = 0;
    int turn = 0;
    int v;
    while (!odds.empty() || even.count(0) < even.size()) {
        if (turn % 2 == 0) {
            if (!odds.empty()) {
                v = odds.rbegin()->first;
                alice += odds[v];
                even[v-1] += odds[v];
                odds.erase(v);
            } else {
                v = even.rbegin()->first;
                alice += even[v];
                odds[v-1] += even[v];
                even.erase(v);
            }
        } else {
            if (!odds.empty()) {
                v = odds.rbegin()->first;
                bob += odds[v];
                even[v-1] += odds[v];
                odds.erase(v);
            } else {
                v = even.rbegin()->first;
                bob += even[v];
                odds[v-1] += even[v];
                even.erase(v);
            }
        }
        turn++;
    }

    cout << alice << ' ' << bob << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
