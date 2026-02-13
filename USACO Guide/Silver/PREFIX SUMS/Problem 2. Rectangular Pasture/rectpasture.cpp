#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define pii pair<int, int>
#define f first
#define s second

bool cmpY(const pii& a, const pii& b) {
    return a.s < b.s || (a.s == b.s && a.f < b.f);
}


constexpr int MAX_N = 2500;
int prefix[MAX_N+1][MAX_N+1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pii> cows(n);
    for (int i=0; i<n; i++)
        cin >> cows[i].f >> cows[i].s;


    // coordinate compression
    sort(cows.begin(), cows.end(), cmpY);
    for (int i=0; i<n; i++) cows[i].s = i+1;
    sort(cows.begin(), cows.end());
    for (int i=0; i<n; i++) cows[i].f = i+1;


    // building prefix matrix
    for (int i=0; i<=n; i++) fill_n(prefix[i], n, 0);
    for (pii cow : cows) prefix[cow.f][cow.s]++;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            prefix[i][j] += prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }

    ll ans = 1;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            int bot = min(cows[i].s, cows[j].s);
            int top = max(cows[i].s, cows[j].s);

            int below = (prefix[cows[j].f][bot] - prefix[cows[i].f-1][bot]);
            int above = (prefix[cows[j].f][n] - prefix[cows[j].f][top-1] - prefix[cows[i].f-1][n] + prefix[cows[i].f-1][top-1]);
            ans += below * above;
        }
    }

    cout << ans << '\n';
}
