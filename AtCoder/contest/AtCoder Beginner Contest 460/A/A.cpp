#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
constexpr int md = 998244353;
inline int add(int a, int b) { a += b; if (a >= md) a -= md; return a; }
inline int sub(int a, int b) { a -= b; if (a < 0) a += md; return a; }
inline int mult(int a, int b) { return ((ll)a * b) % md; }


int main() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    while (m) {
        m = n % m;
        ans++;
    }
    cout << ans << '\n';
}
