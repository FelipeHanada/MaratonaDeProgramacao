#include <bits/stdc++.h>
using namespace std;
#define u32 unsigned int
#define u64 unsigned long long

int t;
u32 x, n;
u64 y;

void solve() {
    u32 ans = 1;
    u32 i = x;
    while (y) {
        if (y & 1)
            ans = ((u64) ans * i) % n;

        y >>= 1;
        i = ((u64) i * i) % n;
    }
    cout << ans << "\n";
}

int main() {
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> x >> y >> n;
        solve();
    }
}