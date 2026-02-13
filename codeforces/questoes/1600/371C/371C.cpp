#include <bits/stdc++.h>
using namespace std;


#define ll long long

ll rb, rs, rc;
ll b, s, c;
ll pb, ps, pc;
ll r;

bool check(ll k) {
    ll price = 0;
    ll qb = rb * k;
    ll qs = rs * k;
    ll qc = rc * k;
    if (qb > b) price += (qb - b) * pb;
    if (qs > s) price += (qs - s) * ps;
    if (qc > c) price += (qc - c) * pc;
    return r >= price;
}

int main() {
    string recipe;
    cin >> recipe;
    
    rb = rs = rc = 0;
    for (int i=0; i<recipe.size(); i++) {
        switch (recipe[i]) {
            case 'B': { rb++; } break;
            case 'S': { rs++; } break;
            case 'C': { rc++; } break;
        }
    }
    cin >> b >> s >> c;
    cin >> pb >> ps >> pc;
    cin >> r;


    ll low = 0, high=(INT64_MAX >> 16);
    while (high - low > 1) {
        ll mid = (low + high) / 2;
        if (check(mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }

    cout << low << '\n';
}
