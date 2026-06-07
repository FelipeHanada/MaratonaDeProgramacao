#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int md = 987179823;
constexpr int B = 256;
int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}
int sub(int a, int b) {
    a -= b;
    if (a < 0) a += md;
    return a;
}
int mult(int a, int b) {
    return ((ll)a * b) % md;
}


int main() {
    string s, t;
    cin >> s >> t;

    if (t.size() > s.size()) {
        cout << "0\n";
        return 0;
    }

    vector<int> hash;
    int tt = 0;
    for (char c : t) tt = add(mult(tt, B), int(c));

    int ss = int(s[0]);
    int p = 1;
    for (int i=1; i<t.size(); i++) {
        ss = add(mult(ss, B), int(s[i]));
        p = mult(p, B);
    }
    hash.push_back(ss);

    for (int i=t.size(); i<s.size(); i++) {
        ss = sub(ss, mult(p, s[i - t.size()]));
        ss = add(mult(ss, B), int(s[i]));
        hash.push_back(ss);
    }

    int ans = 0;
    for (int h : hash) {
        if (tt == h) ans++;
    }

    cout << ans << '\n';
}
