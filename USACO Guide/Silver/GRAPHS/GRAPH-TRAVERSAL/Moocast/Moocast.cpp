#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int n;
    cin >> n;

    vector<tuple<int, int, int>> cows;
    vector<set<int>> adj(n, set<int>());
    for (int i=0; i<n; i++) {
        int x, y, p;
        cin >> x >> y >> p;
        cows.push_back({x, y, p});
    }

    for (int c1=0; c1<n; c1++) {
        for (int c2=0; c2<n; c2++) {
            const auto cow1 = cows[c1];
            const auto cow2 = cows[c2];

            const ll dx = get<0>(cow1) - get<0>(cow2);
            const ll dy = get<1>(cow1) - get<1>(cow2);
            const ll dist2 = dx*dx + dy*dy;
            
            const ll cow1r2 = get<2>(cow1) * get<2>(cow1); 
            if (cow1r2 >= dist2) {
                adj[c1].insert(c2);
            }
            
            const ll cow2r2 = get<2>(cow2)*get<2>(cow2);
            if (cow2r2 >= dist2) {
                adj[c2].insert(c1);
            }
        }
    }

    int ans = INT32_MIN;
    for (int i=0; i<n; i++) {
        int k = 0;
    
        vector<bool> seen(n, false);
        stack<int> dfs; dfs.emplace(i);
        seen[i] = true;
        while (dfs.size() > 0) {
            k++;
            int curr = dfs.top(); dfs.pop();

            for (int x : adj[curr]) {
                if (!seen[x]) {
                    seen[x] = true;
                    dfs.emplace(x);
                }
            }
        }

        ans = max(ans, k);
    }

    cout << ans << endl;
}