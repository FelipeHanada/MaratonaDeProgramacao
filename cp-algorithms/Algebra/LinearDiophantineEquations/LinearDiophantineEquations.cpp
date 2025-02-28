#include <bits/stdc++.h>
using namespace std;


int extended_gcd(int a, int b, int &x, int &y) {
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

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = extended_gcd(abs(a), abs(b), x0, y0);

    if (c % g)
        return false;
    
    x0 *= c / g;
    y0 *= c / g;

    if (a < 0) x0 *= -1;
    if (b < 0) y0 *= -1;

    return true;
}

void shift_solution(int &x, int &y, int a, int b, int k) {
    x += k * b;
    y -= k * a;
}

int count_solutions_on_interval(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    
    a /= g; b /= g;

    int sign_a = (a > 0) ? +1 : -1;
    int sign_b = (b > 0) ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    
}

int main() {
    int a, b, c, x, y, g;
    cin >> a >> b >> c;

    if (a == b && b == 0) {
        cout << "This is the degenerate case.\n";
        cout << "Since c is " << ((c == 0) ? "" : "not") << " equal to 0.\n";
        cout << "The diophantine equation admits " << ((c == 0) ? "infinite" : "no") << " solution(s).\n";
        return 0;
    }

    if (!find_any_solution(a, b, c, x, y, g)) {
        cout << "There is no solution for this equation.\n";
        return 0;
    }

    cout << "Any solution: x=" << x << " y=" << y << ".\n";

    if (a == 0 || b == 0) {
        cout << "This solution cannot be shifted.\n";
        return 0;
    }

    a /= g; b /= g;

    int x1 = x, y1 = y;
    for (int i=0; i<3; i++) {
        shift_solution(x1, y1, a, b, 1);
        cout << "Solution shifted for x+ " << i << " time(s): x=" << x1 << " y=" << y1 << ".\n";
    }

    x1 = x; y1 = y;
    for (int i=0; i<3; i++) {
        shift_solution(x1, y1, a, b, -1);
        cout << "Solution shifted for x- " << i << " time(s): x=" << x1 << " y=" << y1 << ".\n";
    }

    return 0;
}