#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;
#define _0 first
#define _1 second

/*
7 30
20 26 3 14 4 4 9

20 26 3 14 4 4 9 | 3 9 14 20 26 |P 3 4 9 14 20 26


*/

int main() {
    int n, m, q;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> cnt(m+1);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    map<int,vector<int>> inv_cnt;
    for (int i=1; i<=m; i++) {
        if (cnt[i]) {
            inv_cnt[cnt[i]].push_back(i);
        }
    }
    priority_queue<pair<int,vector<int>>> pq;
    for (auto [k, v] : inv_cnt) {
        pq.push({-k, v});
    }

    cin >> q;
    vector<array<int,2>> queries(q);
    for (int i=0; i<q; i++) {
        cin >> queries[i][0];
        queries[i][1] = i;
    }
    sort(queries.rbegin(), queries.rend());

    int index = 0;
    vector<int> ans(q);
    int last = n;
    while (!queries.empty()) {
        if (queries.back()[0] <= n) {
            ans[queries.back()[1]] = a[queries.back()[1]-1];
            queries.pop_back();
            continue;
        }

        int moves = queries.back()[0] - last;

        if (index + moves < pq.top()._1.size()) {
            index += moves;
            ans[queries.back()[1]] = pq.top()._1[index];
            queries.pop_back();
            continue;
        }
        moves -= pq.top()._1.size();
        {
            auto [k, v] = pq.top(); pq.pop();
            if (pq.top()._0 == k - 1) {
                auto [k1, v1] = pq.top(); pq.pop();
                for (int x : v) v1.push_back(x);
                sort(v1.begin(), v1.end());
                pq.push({k1, v1});
            } else {
                pq.push({k - 1, v});
            }
        }

        while (moves >= pq.top()._1.size()) {
            auto [k, v] = pq.top(); pq.pop();

            int maxx; 
            if (pq.empty()) maxx = INT32_MAX;
            else maxx = ((-pq.top()._0) - k);

            int can = moves / v.size();
            can = min(can, maxx);


            if (pq.top()._0 == k - can) {
                auto [k1, v1] = pq.top(); pq.pop();
                for (int x : v) v1.push_back(x);
                sort(v1.begin(), v1.end());
                pq.push({k1, v1});
            } else {
                pq.push({k - can, v});
            }
        }

        index = moves;
        ans[queries.back()[1]] = pq.top()._1[index];

        last = queries.back()[0];
        queries.pop_back();
    }

    for (int x : ans) {
        cout << x << '\n';
    }
}
