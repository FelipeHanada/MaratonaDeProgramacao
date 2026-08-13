#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int B = 26;
constexpr int M = 891763;
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

    vector<int> hash_t(k);
    for (int i=0; i<k; i++) {
        hash_t[i] = 0;
        for (int j=t[i].size()-1; j>=0; j--)
            hash_t[i] = add(mult(hash_t[i], B, M), t[i][j] - 'a', M);
    }

    vector<int> prefix(n+1);
    prefix[0] = 0;
    {
        int aux = 1;
        for (int i=1; i<=n; i++) {
            prefix[i] = add(prefix[i-1], mult(s[i-1] - 'a', aux, M), M);
            aux = mult(aux, B, M);
        }
    }
    int invB = binpow(B, M-2, M);
    vector<int> invpowB(n+1);
    invpowB[0] = 1;
    for (int i=1; i<=n; i++) invpowB[i] = mult(invpowB[i-1], invB, M);


    vector<int> dp(n+1);
    dp[0] = 1;
    for (int i=1; i<=n; i++) {
        dp[i] = 0;
        for (int j=0; j<k; j++) if (t[j].size() <= i) {
            int hash_s = mult(sub(prefix[i], prefix[i-t[j].size()], M), invpowB[i-t[j].size()], M);
            if (hash_s == hash_t[j]) dp[i] = add(dp[i], dp[i-t[j].size()]);
        }
    }

    cout << dp[n] << '\n';
}

/*
prefix [] = 0 
*/
