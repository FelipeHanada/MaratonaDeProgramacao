#include <bits/stdc++.h>
using namespace std;

#define ll long long


int n, k;
int x[(int)2e5];

bool check(ll y) {
    int kn = 1;
    ll curr = 0;

    for (int i=0; i<n; i++) {
        if (x[i] > y) return false;
        if (curr + x[i] <= y) {
            curr += x[i];
        } else {
            kn++;
            curr = x[i];
        }
    }

    return kn <= k;
}


int main() {
    cin >> n >> k;
    ll sum = 0;
    for (int i=0; i<n; i++) {
        cin >> x[i];
        sum += x[i];
    }

    ll l=0, r=sum;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << r << '\n';
}
