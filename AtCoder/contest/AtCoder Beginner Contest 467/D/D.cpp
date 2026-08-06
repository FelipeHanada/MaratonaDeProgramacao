#include <bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);
#define _f first
#define _s second
using ll = long long;
constexpr int md = 0;
int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}
int sub(int a, int b) {
    a -= b;
    if (a < 0) a += md;
    return a;
}
int mult(int a, int b) { return ((ll)a * b) % md; }
int binpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mult(ans, a);
        a = mult(a, a);
        b >>= 1;
    }
    return ans;
}


int main() {
    int tt; cin >> tt;
    while (tt--) {
        ll px, py, qx, qy, rx, ry, sx, sy;
        cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;

        pair<double, double> p = { (px+qx)/2.0, (py+qy)/2.0 },
                             pv = { qy-py, -(qx-px) };

        pair<double, double> q = { (rx+sx)/2.0, (ry+sy)/2.0 },
                             qv = { sy-ry, -(sx-rx) };

        if (abs(pv._f * qv._s - pv._s * qv._f) < 1e-6) { // slope igual
            if (abs((qv._f*(p._s - q._s)) - (qv._s*(p._f - q._f))) < 1e-6) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        } else { // slope diferente sempre tem sol.
            cout << "Yes\n";
        }
    }
}

/*
a resposta é Yes se existe um ponto P(x, y) equidistante
de (px, py) (qx, qy)
e de (rx, ry) (sx, sy)

os pontos P'(px, qy) e Q'(qx, py) definem uma reta em que todos os pontos distam o mesmo de P e Q
definese o mesmo para R e S e o cruzamento é a sol.


se a slope for dif. então sempre da

se a slope for a mesma, então são paralelas
    então só não dá se não forem exatamente iguais


ou seja, que satisfaça

(px - x)^2 + (py - y)^2 = (qx - x)^2 + (qy - y)^2
(rx - x)^2 + (ry - y)^2 = (sx - x)^2 + (sy - y)^2

(px^2 - 2px*x + x^2) + (py^2 - 2py*y + y^2) = (qx^2 - 2qx*x + x^2) + (qy^2 - 2qy*y + y^2)
px^2 - 2px*x + py^2 - 2py*y = qx^2 - 2qx*x + qy^2 - 2qx*x
px^2 + py^2 - qx^2 - qy^2 = 2x(px - qx) + 2y(py - qy)


6
2 0 1 1 -1 0 1 2
1 0 -1 0 0 1 0 -1
4 0 3 1 2 0 1 1
0 0 1 1 0 0 1 1
1 1 0 0 0 0 1 1
0 0 0 1 0 1 1 1

*/
