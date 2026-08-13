#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


int main() {
    string s; int n;
    cin >> s >> n;

    vector<int> cnt(26, 0);
    for (char c : s) cnt[c - 'a']++;

    auto check = [&](int k) -> bool {
        int need = 0;
        for (int i=0; i<26; i++) {
            need += (cnt[i] + k - 1) / k;
        }
        return need <= n;
    };

    int diff = 0;
    for (int i=0; i<26; i++) diff += bool(cnt[i]);

    if (diff > n) {
        cout << "-1\n";
        return 0;
    }

    int l = 0, r = 5000;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }

    cout << r << '\n';
    string t;
    for (int i=0; i<26; i++) {
        int need = (cnt[i] + r - 1) / r;
        for (int j=0; j<need; j++) {
            t.push_back('a' + i);
        }
    }
    while (t.size() < n) t.push_back('a');
    cout << t << '\n';
}