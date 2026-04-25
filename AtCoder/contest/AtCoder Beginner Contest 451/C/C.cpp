#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define _1 first
#define _2 second
using ll = long long;



int main() {
    int q;
    cin >> q;

    vector<pair<int,int>> queries(q);
    for (int i=0; i<q; i++) cin >> queries[i]._1 >> queries[i]._2;

    vector<int> ans(q, 0);
    deque<pair<int, int>> dels;
    for (int i=q-1; i>=0; i--) {
        auto [t, x] = queries.back(); queries.pop_back();

        if (t == 1) {
            auto lb = lower_bound(dels.begin(), dels.end(), pair<int,int>({x, -1}));
            ans[i]++;

            if (lb != dels.end()) {
                ans[(*lb)._2]--;
            }
        } else {
            while (!dels.empty() && dels.front()._1 <= x) {
                dels.pop_front();
            }
            dels.push_front({x, i});
        }
    }

    for (int i=1; i<q; i++) {
        ans[i] += ans[i-1];
    }

    for (int x : ans) {
        cout << x << '\n';
    }
}


/*
5
1 5
1 7
1 8
2 7
1 3

ans = [x x x x x]
ans = [x x x x 1]

             del7
ans = [x x x 0 1]

ans = [x x 1 0 1]

ans = [x 1 1 -1 1]


*/