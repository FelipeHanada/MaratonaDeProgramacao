#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int B = 26;
constexpr int M = 9182763;
int add(int a, int b) {
    a += b;
    if (a >= M) a -= M;
    return a;
}
int sub(int a, int b) {
    a -= b;
    if (a < 0) a += M;
    return a;
}
int mult(int a, int b) { return ((ll)a * b) % M; }
int binpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mult(ans, a);
        a = mult(a, a);
        b >>= 1;
    }
    return ans;
}

int main() {
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    if (m > n) {
        cout << "0\n";
        return 0;
    }

    vector<int> hash_s(n - m + 1);
    int hash_t = 0;
    for (char c : t) hash_t = add(mult(hash_t, B), c - 'a');

    int powBm = binpow(B, m-1);
    for (int i=0; i<m; i++) hash_s[0] = add(mult(hash_s[0], B), s[i] - 'a');
    for (int i=1; i<hash_s.size(); i++) {
        hash_s[i] = sub(hash_s[i-1], mult(powBm, s[i-1] - 'a'));
        hash_s[i] = mult(hash_s[i], B);
        hash_s[i] = add(hash_s[i], s[i+m-1] - 'a');
    }

    int ans = 0;
    for (int hash : hash_s) ans += (hash == hash_t);

    cout << ans << '\n';
}
