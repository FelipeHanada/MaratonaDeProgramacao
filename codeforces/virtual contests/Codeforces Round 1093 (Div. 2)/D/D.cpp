#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;

int n;
map<pair<int, int>, int> memo;
// it does not need memoization
int query(int l, int r) {
    if (memo.count(make_pair(l, r))) return memo[make_pair(l, r)];

    cout << "? ";
    cout << r - l << ' ';
    for (int i=l; i<r; i++) cout << i + 1 << ' ';
    cout << '\n';
    fflush(stdout);
    int ans;
    cin >> ans;
    if (ans == -1) exit(0);

    return memo[make_pair(l, r)] =ans;
}

void answer(int x, int y, int z) {
    cout << "! " << x+1 << ' ' << y+1 << ' ' << z+1 << ' ' << '\n';
}

int one, two, three;
void solve1() {
    int l = 0, r = 2*n+1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int left = query(0, mid),
            right = query(mid, 2*n+1);

        if (left > right) { // only 1th is on the left set
            r = mid;
        } else if (left < right) { // 1th and 2th are on the left set
            r = mid;
        } else {
            if ((mid-left)%2) { // all of them are on the left set
                r = mid;
            } else { // all of them are on the right set
                l = mid;
            }
        }
    }
    one = l;
}
void solve2() {
    int l = 0, r = 2*n+1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int left = query(0, mid),
            right = query(mid, 2*n+1);

        if (left < right) { // 1th and 2th are on the left set
            r = mid;
        } else if (left > right) { // only 1th are on the left set
            l = mid;
        } else {
            if ((mid-left)%2) { // all of them are on the left set
                r = mid;
            } else { // all of them are on the right set
                l = mid;
            }
        }
    }
    two = l;
}
void solve3() {
    int l = 0, r = 2*n+1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int left = query(0, mid),
            right = query(mid, 2*n+1);

        if (left < right) { // 1th and 2th are on the left set
            l = mid;
        } else if (left > right) { // only 1th are on the left set
            l = mid;
        } else {
            if ((mid-left)%2) { // all of them are on the left set
                r = mid;
            } else { // all of them are on the right set
                l = mid;
            }
        }
    }
    three = l;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n;
        memo.clear();
        solve1();
        solve2();
        solve3();
        answer(one, two, three);
    }
}

/*
se fizemos duas queries nos intervalos [1, n] e [n+1, 2n+1]
com resultados l e r

cada par separado contribui em 1 para l e para r
a tripla contribui 1 para l+r se tiver pelo menos um elemento em na primeira e na segunda parte
    cc. todos estão somente na primeira ou somente na segunda

Dado um conjunto S,
    query(S) = query(complementar de S) sse. a tripla está em S ou complementar de S
    (query(S) != query(complementar de S) => a tripla está separada em S e comp. de S)


*/
