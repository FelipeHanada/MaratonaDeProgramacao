#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_S = 2000;
int s, n;
int v, w, k;
int dp[MAX_S + 1] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> n;

    map<int, vector<pair<int, int>>> items;
    for (int i=0; i<n; i++) {
        cin >> v >> w >> k;
        items[w].push_back({v, k});
    }

    for (auto &[w, p] : items) {
        sort(p.begin(), p.end(), greater<pair<int, int>>());

        int a = s / w;
        auto it = p.begin();
        for (int i=0; i<a && it != p.end(); i++) {
            for (int j=s; j>=w; j--) {
                dp[j] = max(dp[j], dp[j - w] + it->first);
            }
            if (--(it->second) == 0)
                it++;
        }
    }

    cout << dp[s] << "\n";
}
