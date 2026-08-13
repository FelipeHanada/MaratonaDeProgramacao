#include <bits/stdc++.h>
using namespace std;
using ll = long long;


constexpr int md = int(1e9) + 7;
inline int mult(int a, int b) { return ((ll)a * b) % md; }
int binpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mult(ans, a);
        a = mult(a, a);
        b >>= 1;
    }
    return ans;
}
inline int inv(int a) { return binpow(a, md-2); }

int fat[int(2e6)+1];

int main() {
    fat[0] = 1;
    for (int i=1; i<=int(2e6); i++) fat[i] = mult(fat[i-1], i);

    int n, m;
    cin >> n >> m;

    cout << mult(fat[n + m - 1], mult(inv(fat[n - 1]), inv(fat[m]))) << '\n';
}