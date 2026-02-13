#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
    int n, ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;
    set<int> xs;
    vector<array<int,2>> points(n);
    for (int i=0; i<n; i++) {
        cin >> points[i][0];
        xs.insert(points[i][0]);
    }
    for (int i=0; i<n; i++) cin >> points[i][1];

    map<int, int> comp;
    int i=0;
    for (int x : xs) comp[x] = i++;
    for (int i=0; i<n; i++) points[i][0] = comp[points[i][0]];

    vector<vector<int>> p(xs.size());
    for (int i=0; i<n; i++) {
        p[points[i][0]].push_back(points[i][1]);
    }
    for (int i=0; i<xs.size(); i++) sort(p[i].begin(), p[i].end());
    p.push_back((vector<int>){by});

    array<ll,2> top = {0, ay}, bottom = {0, ay};
    array<ll,2> ntop, nbottom;
    ll ans = bx - ax;
    for (auto ys : p) {
        ntop = min((array<ll,2>){top[0] + abs(top[1] - ys.back()) + ys.back() - ys.front(), ys.front()},
                    (array<ll,2>){bottom[0] + abs(bottom[1] - ys.back()) + ys.back() - ys.front(), ys.front()});
        nbottom = min((array<ll,2>){top[0] + abs(top[1] - ys.front()) + ys.back() - ys.front(), ys.back()},
                    (array<ll,2>){bottom[0] + abs(bottom[1] - ys.front()) + ys.back() - ys.front(), ys.back()});
        swap(top, ntop);
        swap(bottom, nbottom);
    }

    cout << ans + top[0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    int tt;
    cin >> tt;
    while (tt--) solve();    
    return 0;
}
