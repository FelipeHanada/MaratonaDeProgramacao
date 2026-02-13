#include <bits/stdc++.h>
using namespace std;


using ll = long long;

constexpr int MAX_N = 2e5;
int x[MAX_N+1], y[MAX_N+1];

bool cmp(int i, int j) {
    int ah = (y[i] < 0 || (y[i] == 0 && x[i] < 0));
    int bh = (y[j] < 0 || (y[j] == 0 && x[j] < 0));
    if (ah != bh) return ah < bh;
    ll cross = (ll)x[i]*y[j] - (ll)y[i]*x[j];
    return cross > 0 || (cross == 0 && i < j);
}
bool invcmp(int i, int j) {
    return !cmp(i, j);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<array<int,2>> points(n);
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        // if (!x && y) y /= abs(y);
        // else if (x && !y) x /= abs(x);
        // else if (x && y) {
        //     int g = abs(__gcd(x, y));
        //     x /= g; y /= g;
        // }
        points[i] = { x, y };
    }

    vector<int> sorted(n); iota(sorted.begin(), sorted.end(), 0);
    sort(sorted.begin(), sorted.end(), invcmp);

    vector<int> prefix(n);
    for (int i=0; i<n; i++) {
        x[MAX_N] = points[i][0]; y[MAX_N] = points[i][1];
        auto ub = upper_bound(sorted.begin(), sorted.end(), MAX_N, invcmp);
        prefix[sorted[i]] = distance(sorted.begin(), ub);
    }

    while (q--) {
        int a, b;
        cin >> a >> b; a--; b--;
        if (prefix[b] >= prefix[a]) {
            cout << prefix[b] - prefix[a] << '\n';
        } else {
        }
    }
}
