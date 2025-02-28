#include <bits/stdc++.h>
using namespace std;


int egcd(int a, int b, int &x, int &y) {
    x = 1; y = 0;
    int x1 = 0, y1 = 1;

    while (b) {
        int q = a / b;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a, b) = make_tuple(b, a - q * b);
    }

    return a;
}

bool find_any_solution(int a, int b, int c, int &x, int &y, int &g) {
    g = egcd(abs(a), abs(b), x, y);
    if (c % g)
        return false;
    
    x *= c / g;
    y *= c / g;

    if (a < 0) x *= -1;
    if (b < 0) y *= -1;
    
    return true;
}

void shift_solution(int &x, int &y, int a, int b, int k) {
    x += k * b;
    y -= k * a;
}

int a, b, c, x, y, g;
bool solve() {
    if (!find_any_solution(a, b, c, x, y, g))
        return false;

    a /= g; b /= g;

    shift_solution(x, y, a, b, -x / b);
    if (x < 0)
        shift_solution(x, y, a, b, 1);

    if (y < 0)
        return false;

    return true;
}

int main() {
    cin >> a >> b >> c;
    cout << (solve() ? "Yes" : "No") << "\n";
}