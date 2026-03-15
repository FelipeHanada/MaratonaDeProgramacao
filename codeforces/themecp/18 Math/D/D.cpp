#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    string s, t;
    cin >> s >> t;
    if (s.size() < t.size()) swap(s, t);
    
    vector<pair<ll, ll>> power(100001);
    power[0] = { 0, 1 };
    power[1] = { 1, 0 };
    power[2] = { 1, 1 };
    for (ll i=3; i<=100000; i++) {
        power[i] = { power[i-1].first + power[i-1].second, power[i-1].first };
    }

    pair<ll, ll> a, b;
    for (ll i=0; i<s.size(); i++) {
        if (s[i] == '1') {
            a.first += power[s.size()-i-1].first;
            a.second += power[s.size()-i-1].second;
        }
    }

    for (ll i=0; i<t.size(); i++) {
        if (t[i] == '1') {
            b.first += power[t.size()-i-1].first;
            b.second += power[t.size()-i-1].second;
        }
    }
    
    if (a.first == b.first && a.second == b.second) {
        cout << "=\n";
    } else if (a.first >= b.first && a.second >= b.second) {
        cout << ">\n";
    } else if (a.first <= b.first && a.second <= b.second) {
        cout << "<\n";
    } else {
        if (a.first <= b.first && a.second >= b.second) swap(a, b);

        a.first -= b.first;
        b.second -= a.second;

        // a.first q ? b.second
        ll p = a.first, q = b.second;
        double x = p * sqrt(5), y = 2*q - p;

        if (x > y) {
            cout << ">\n";
        } else {
            cout << "<\n";
        }
    }
}