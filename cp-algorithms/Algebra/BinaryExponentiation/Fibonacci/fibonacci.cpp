#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct matrix {
    ll mat[2][2];

    matrix friend operator*(const matrix &a, const matrix &b) {
        matrix c;

        for (int i=0; i<2; i++) {
            for (int j=0; j<2; j++) {
                c.mat[i][j] = 0;
                for (int k=0; k<2; k++) {
                    c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
                }
            }
        }

        return c;
    }
};

int fib(int n) {
    matrix mat = {{ {1, 1}, {1, 0} }};

    matrix fib_mat = {{ {1, 0}, {0, 1} }};
    while (n > 0) {
        if (n & 1) {
            fib_mat = fib_mat * mat;
        }

        n >>= 1;
        mat = mat * mat;
    }

    return fib_mat.mat[0][1];
}

int main() {
    for (int i=0; i<10; i++) {
        cout << fib(i) << endl;
    }
}
