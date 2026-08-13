#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> b[i];
        for (int i=0; i<n; i++) if (a[i] > b[i]) swap(a[i], b[i]);

        set<int> available;
        for (int i=0; i<n; i++) available.insert(i);
        map<int, set<int>> m;
        for (int i=0; i<n; i++) {
            m[a[i]].insert(i);
        }

        auto move = [&](int i, int j) {
            vector<int> s = { a[i], a[j], b[i], b[j] };
            sort(s.begin(), s.end());
            a[i] = a[j] = s[1];
            b[i] = b[j] = s[2];
        };

        while (available.size() > 1) {
            int i = *m.begin()->second.begin();
            m[a[i]].erase(i);
            if (m[a[i]].empty()) m.erase(a[i]);

            int left = -1, right = -1;
            auto lb = available.lower_bound(i);
            auto ub = available.upper_bound(i);
            if (lb != available.begin()) {
                left = *(--lb);
            }
            if (ub != available.end()) {
                right = *ub;
            }

            int j;
            if (left == -1) {
                j = right;
            } else if (right == -1) {
                j = left;
            } else {
                if (b[left] < b[right]) {
                    j = left;
                } else {
                    j = right;
                }
            }

            m[a[j]].erase(j);
            if (m[a[j]].empty()) m.erase(a[j]);
            move(i, j);
            m[a[j]].insert(j);

            available.erase(i);
        }

        cout << a[*available.begin()] << '\n';
    }
}

/*
1 2 3
4 5 6

2 3
4 6 => 3 4 => 3

1 3
4 5 => 3 4

6
3 6 12 4 10 12
2 3 2 7 8 9

6
7

8
 8  7 13 11  1 10  4  5
11 11 12  8  9  2  3 13

 8  7 13 11  1 10  4  5
11 11 12  8  9  2  3 13


9
16 1 9 12 5 18 10 10 16
14 6 7 11 12 17 18 3 17

9
16 1 9 12 5 18 10 10 16
14 6 7 11 12 17 18 3 17

16 6 12 5 18 10 10 16
14 7 11 12 17 18 3 17

16 6 12 5 18 10 10
14 7 11 12 17 18 16

16 6 11 18 10 10
14 7 12 17 18 16

16 7 18 10 10
14 11 17 18 16

11 18 10 10
14 17 18 16

11 18 10
14 17 16

11 16
14 17

14
16
*/
