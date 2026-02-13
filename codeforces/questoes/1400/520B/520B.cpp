#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;

    map<int, int> ans;
    queue<pair<int, int>> q;
    q.push({n, 0});
    while (!ans.count(m)) {
        auto [curr, step] = q.front(); q.pop();
        if (ans.count(curr)) continue;
        if (curr < m && !ans.count(2*curr)) q.push({2*curr, step+1});
        if (curr && !ans.count(curr-1)) q.push({curr - 1, step+1});
        ans[curr] = step;
    }

    cout << ans[m] << '\n';
}
