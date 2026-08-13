#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int md = int(1e9)+7;

inline int mult(int a, int b) { return ((ll)a * b) % md; }
int binexp(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mult(ans, a);
        a = mult(a, a);
        b >>= 1;
    }
    return ans;
}

int main() {

}
