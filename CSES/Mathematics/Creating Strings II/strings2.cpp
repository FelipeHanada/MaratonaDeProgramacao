#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int md = int(1e9)+7;
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
constexpr int N = int(1e6);
int cnt[26];

int main() {
    fill_n(cnt, 26, 0);
    string s; cin >> s;
    for (char c : s) cnt[c - 'a']++;

    vector<int> fat(N+1);
    fat[0] = 1;
    for (int i=1; i<=N; i++) fat[i] = mult(fat[i-1], i);

    int ans = fat[s.size()];
    for (int i=0; i<26; i++) ans = mult(ans, inv(fat[cnt[i]]));

    cout << ans <<'\n';
}
