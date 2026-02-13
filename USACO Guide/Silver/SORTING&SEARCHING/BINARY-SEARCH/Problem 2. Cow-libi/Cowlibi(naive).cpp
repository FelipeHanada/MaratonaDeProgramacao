#include <bits/stdc++.h>
using namespace std;


int g, n;
constexpr int MAX_G = 1e5;
constexpr int MAX_N = 1e5;
tuple<int, int, int> grazings[MAX_G];
tuple<int, int, int> cows[MAX_N];

#define ll long long

bool verify(int cow, int grazing) {
    ll dx = get<0>(cows[cow]) - get<0>(grazings[grazing]);
    ll dy = get<1>(cows[cow]) - get<1>(grazings[grazing]);
    ll dt = get<2>(cows[cow]) - get<2>(grazings[grazing]);

    return dt*dt >= dx*dx + dy*dy;
}


int main() {
    cin >> g >> n;

    int x, y, t;
    for (int i=0; i<g; i++) {
        cin >> x >> y >> t;
        grazings[i] = make_tuple(x, y, t);
    }

    for (int i=0; i<n; i++) {
        cin >> x >> y >> t;
        cows[i] = make_tuple(x, y, t);
    }

    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<g; j++) {
            if (!verify(i, j)) {
                ans++; // innocent
                break;
            }
        }

    }

    cout << ans << '\n';
}