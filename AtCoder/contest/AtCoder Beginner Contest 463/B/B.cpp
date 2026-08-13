#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);
constexpr int md = int(1e9)+7;
inline int add(int a, int b) { return ((a%md) + (b%md)) % md;}
inline int sub(int a, int b) { return ((a%md) - (b%md) + md) % md;}
inline int mult(int a, int b) { return ((ll)(a%md) * (b%md)) % md;}
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


int main() {
    int n; char k;
    cin >> n >> k;
    vector<int> cnt(5, 0);
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<5; j++) {
            if (s[j] == 'o') cnt[j]++;
        }
    }

    int j = k - 'A';
    cout << (cnt[j] ? "Yes" : "No") << '\n';
}
