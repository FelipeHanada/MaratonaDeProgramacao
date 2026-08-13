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

        // se (px-qx, py-qy) for colinear com (rx-sx, ry-sy)
        // entao a slope é a mesma

        if ((px-qx)*(ry-sy) - (py-qy)*(rx-sx)) {
            // nao sao colineares
            cout << "Yes\n"; // sol garantida
        } else {
            /*
            precisamos checar se não é a mesma reta
            */

            if (px == qx) {
                cout << (py+qy == ry+qy ? "Yes" : "No") << '\n';
            } else if (py == qy) {
                cout << (px+qx == rx+qx ? "Yes" : "No") << '\n';
            } else {
                

                if (abs((px-qx)*(ry-sy) - (py-qy)*(rx-sx)) > 1e7) {
                    cout << "No\n";
                } else {
                    cout << "Yes\n";
                }
            }
        }
    }
}

/*
0 0 1 0 -1 0 2 0

*/
