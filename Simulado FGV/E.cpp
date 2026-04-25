#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; string s;
    cin >> n >> s;
    string t = string(s.begin(), s.end()-1);
    ll m = atoi(t.c_str());
    if (s.back() == 'G') m *= 1024;
    else if (s.back() == 'T') m *= 1024 * 1024;

    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    int i=0, j=0;
    ll curr = 0;
    int R;
    while (j < n && curr + a[j] <= m) {
        curr += a[j];
        j++;
    }
    R = j - i;
    curr -= a[i];
    i++;
    map<int, int> L;
    while (n - i >= R) {
        while (j < n && curr + a[j] <= m) {
            curr += a[j];
            j++;
        }
        
        R = min(R, j - i);
        curr -= a[i];
        i++;

        if (j < n) L[j - i] = i;
    }

    if (L.count(R) == 0) L[R] = -1;

    cout << R << ' ' << L[R] + 1 << '\n';
}