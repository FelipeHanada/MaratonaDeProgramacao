#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> p(n), deg(n, 0);
        for (int i=1; i<n; i++) {
            cin >> p[i];
            p[i]--;
            deg[p[i]]++;
        }

        string s; cin >> s;

        queue<int> q;
        for (int i=0; i<n; i++) if (deg[i] == 0) q.push(i);

        int ans = 0;
        vector<int> score(n, 0);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (s[curr] == 'W') score[curr]++;
            else score[curr]--;
            
            if (score[curr] == 0) ans++;

            if (curr == 0) continue;
            score[p[curr]] += score[curr];
            if (--deg[p[curr]] == 0) q.push(p[curr]);
        }

        cout << ans << '\n';
    }
}