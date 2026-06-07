#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(0);

constexpr int md = 998244353;
constexpr int inv2 = (998244353+1)/2;
int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}
int mult(int a, int b) {
    return (ll(a) * b) % md;
}

int main() {
    string s;
    cin >> s;

    int n = s.size();
    char last = 0;
    int ans = 0;
    int curr = 0;
    for (int i=0; i<n; i++) {
        if (s[i] != last) curr++;
        else {
            ans += mult(mult(curr, add(curr, 1)), inv2);
            curr = 1;
        }
        last = s[i];
    }

    ans += mult(mult(curr, add(curr, 1)), inv2);
    cout << ans << '\n';
}
