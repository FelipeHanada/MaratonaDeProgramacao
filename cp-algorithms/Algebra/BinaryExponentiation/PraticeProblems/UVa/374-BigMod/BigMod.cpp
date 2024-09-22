// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=310
#include <bits/stdc++.h>
using namespace std;


int mod_pow(int x, int y, int m) {
    x %= m;
    int r = 1;
    while (y > 0) {
        if (y & 1)
            r = (r * x) % m;
        
        x = (x * x) % m;
        y >>= 1;
    }
    return r;
}

int main() {
    int b, p, m;
    while (cin >> b >> p >> m) {
        cout << mod_pow(b, p, m) << endl;
    }
}
