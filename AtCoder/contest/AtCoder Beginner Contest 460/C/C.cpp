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
    vector<int> a(n), b(m);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int j=0; j<m; j++) cin >> b[j];
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    int ans = 0;
    while (!a.empty() && !b.empty()) {
        while (!a.empty() && a.back()*2 < b.back()) a.pop_back();
        if (a.empty()) break;
        ans++;
        a.pop_back();
        b.pop_back();
    }

    cout << ans << '\n';
}

/*
4 5
1 2 4 8
2 3 9 9 14
*/
