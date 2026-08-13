#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int B = 26;
constexpr int M = 89176388;
constexpr int md = int(1e9)+7;
int add(int a, int b, int m) { return (a + b) % m; }
int add(int a, int b) { return add(a, b, md); }
int mult(int a, int b, int m) { return ((ll)a * b) % m; }
int mult(int a, int b) { return mult(a, b, md); }
int sub(int a, int b, int m) { return (add(a, -b, m) + m) % m; }
int sub(int a, int b) { return sub(a, b, md); }
int binpow(int a, int b, int m) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mult(ans, a, m);
        a = mult(a, a, m);
        b >>= 1;
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    string s; cin >> s;
    int n = s.size();
    int k; cin >> k;
    vector<string> t(k);
    for (int i=0; i<k; i++) cin >> t[i];

    map<int, unordered_set<int>> hash_t;
    for (int i=0; i<k; i++) {
        int hash = 0;
        for (char c : t[i])
            hash = add(mult(hash, B, M), c - 'a', M);

        hash_t[t[i].size()].insert(hash);
    }

    vector<int> dp(n+1); dp[0] = 1;
    for (int i=1; i<=n; i++) {
        dp[i] = 0;
        int hash_s = 0, aux = 1;
        for (int size_j = 1; size_j <= i; size_j++) {
            hash_s = add(hash_s, mult(s[i - size_j] - 'a', aux, M), M);
            aux = mult(aux, B, M);
            if (hash_t[size_j].count(hash_s))
                dp[i] = add(dp[i], dp[i-size_j]);
        }
    }

    cout << dp[n] << '\n';
}

/*
prefix [] = 0 
*/
