#include <bits/stdc++.h>
using namespace std;

/*
its obvious to see that any segment with a number not multiple by 3 of 0's or 1's
    will not be possible to make it empty

considering it is possible to make it empty, we can consider two cases

1) there is a segment with atleast two elements that are equal
    if this happens, we can eliminate these elements, to do this we can follow the rule
        a. if the size of the segment is multiple of 3, them remove three adjacent
        b. if not, remove two adjacent and other somewhere else
    since the number of 0's and 1's is multiple of three at the start, we can use this
        strategy to eliminate all elements of the segment with a cost of the size of the segment
        after this we can repeat this strategy until all elements of the interval are deleted

2) there is no equal elements adjacent to one another
    we can use a single operation of cost 2 to make the following subsegment fall into case 1
*/


void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> prefix(n+1);
    vector<int> eq_next(n);
    prefix[0] = 0;
    eq_next[0] = 0;
    for (int i=0; i<n; i++) {
        cin >> prefix[i+1];
        prefix[i+1] += prefix[i];
        if (i > 0) {
            eq_next[i] = eq_next[i-1] + ((prefix[i+1] - prefix[i] == prefix[i] - prefix[i-1]) ? 1 : 0);
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;

        if ((prefix[r] - prefix[l]) % 3 || (r - l) % 3) {
            cout << "-1\n";
            continue;
        }


        if (eq_next[r-1] - eq_next[l] > 0) {
            cout << (r - l) / 3 << '\n';
        } else {
            cout << 2 + (r - l - 3) / 3 << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}