#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, q;
    cin >> n >> q;
    deque<int> c(n), s(n);
    for (int i=0; i<n; i++) cin >> c[i] >> s[i];

    map<int, vector<int>> a;
    for (int i=0; i<n; i++) a[s[i]].push_back(c[i]);

    vector<array<int,3>> b(q);
    for (int i=0; i<q; i++) {
        cin >> b[i][0] >> b[i][1];
        b[i][2] = i;
    }
    sort(b.begin(), b.end());

    int curr = 0;
    int sec = 0;
    while (sec < n && s[sec] == s[curr]) sec++;

    vector<int> ans(q, -2);
    while (!b.empty() && curr < n) {
        while (curr < n && c[curr] > b.back()[0]) {
            curr++;
            while (sec < n && s[sec] == s[curr]) sec++;
        }

        if (curr < n) {
            if (b.back()[1] != s[curr]) {
                ans[b.back()[2]] = curr;
            } else {
                ans[b.back()[2]] = (sec == n ? -2 : sec);
            }
        }

        b.pop_back();
    }

    for (int x : ans) cout << x + 1 << '\n';
}

/*
5 6
100 1
80 2
80 1
50 3
20 2
90 1
80 2
80 1
50 3
19 1
100 4
*/