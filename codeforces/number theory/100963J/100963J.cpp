#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    x = 1; y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    
    while (b1) {
        ll q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }

    return a1;
}

bool find_any_solution(ll a, ll b, ll c, ll &x, ll &y, ll &g) {
    g = extended_gcd(abs(a), abs(b), x, y);
    if (c % g)
        return false;
    
    x *= c / g;
    y *= c / g;

    if (a < 0) x *= -1;
    if (b < 0) y *= -1;

    return true;
}

void shift_solution(ll &x, ll &y, ll a, ll b, ll k) {
    x += k * b;
    y -= k * a;
}

ll n, m, a, k;
bool solve() {
    if (n == 0)  // all inputs are positive except last line
        return false;

    // solution for minimum minimum x and y non negatives
    // n + m*x = (k + a) + a*y
    // m*x + (-a)*y = k + a - n

    ll a1 = m,
       b1 = -a,
       c1 = k + a - n,
       x, y, g;
    if (!find_any_solution(a1, b1, c1, x, y, g)) {
        cout << "Impossible\n";
        return true;
    }

    a1 /= g;
    b1 /= g;

    shift_solution(x, y, a1, b1, -x / b1);
    if (x < 0)
        shift_solution(x, y, a1, b1, -1);

    if (y < 0) {
        shift_solution(x, y, a1, b1, y / a1);
        if (y < 0)
            shift_solution(x, y, a1, b1, -1);
    }

    cout << n + m * x << "\n";
    return true;
}

int main() {
    do {
        cin >> n >> m >> a >> k;
    } while (solve());
}