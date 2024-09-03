#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    int v[n];
    for (int i=0; i<n; i++) cin >> v[i];

    vector<pair<ll, ll>> perm = {{0, 0}};
    for (int i=0; i<n; i++) {
        int s = perm.size();
        for (int j=0; j<s; j++) perm.push_back(perm[j]);

        for (int j=0; j<s; j++) perm[j].first += v[i];
        for (int j=s; j<s*2; j++) perm[j].second += v[i];
    }

    ll min_diff = LLONG_MAX;
    for (vector<pair<ll, ll>>::iterator it = perm.begin(); it != perm.end(); it++)
        min_diff = min(min_diff, abs(it->first - it->second));

    cout << min_diff;
}