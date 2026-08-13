#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int B = 26;
constexpr int M = 129876323;
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


int main() {
    string s; cin >> s;
    int n = s.size();

    vector<int> prefix(n+1), powB(n+1);
    prefix[0] = 0; powB[0] = 1;
    for (int i=1; i<=n; i++) {
        prefix[i] = add(mult(prefix[i-1], B), s[i-1] - 'a');
        powB[i] = mult(powB[i-1], B);
    }
    auto hash_s = [&](int l, int r) {
        return sub(prefix[r], mult(prefix[l], powB[r - l]));
    };

    for (int i=1; i<=n; i++) {
        bool ok = 1;
        for (int j=0; ok && j<n; j+=i) {
            ok = hash_s(0, min(j+i, n) - j) == hash_s(j, min(j+i, n));
        }

        if (ok) cout << i << ' ';
    }
    cout << '\n';
}
