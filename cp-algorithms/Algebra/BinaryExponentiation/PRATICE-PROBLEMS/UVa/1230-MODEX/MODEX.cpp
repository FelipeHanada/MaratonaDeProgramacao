// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3671
#include <bits/stdc++.h>
using namespace std;


int mod_pow(int x, int y, int n) {
    int r = 1;
    x %= n;
    while (y > 0) {
        if (y & 1)
            r = (r * x) % n;
        
        x = (x * x) % n;
        y >>= 1;
    }

    return r;
}

int main() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int x, y, n;
        cin >> x >> y >> n;

        cout << mod_pow(x, y, n) << endl;
    }
}
