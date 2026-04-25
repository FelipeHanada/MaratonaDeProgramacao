#include <bits/stdc++.h>
using namespace std;


using ll = long long;

pair<ll,ll> solve(const string& upper, int i, bool tight) {
    if (i == upper.size()) return {0, 1};

    pair<ll,ll> ans = {0, 0};
    pair<ll,ll> res;
    if (tight) {
        res = solve(upper, i+1, 0);
        for (char curr = '0'; curr < upper[i]; curr++) {
            ans.first += res.first + (curr - '0') * res.second;
            ans.second += res.second;
        }
        res = solve(upper, i+1, 1);
        ans.first += res.first + (upper[i] - '0') * res.second;
        ans.second += res.second;
    } else {
        res = solve(upper, i+1, 0);
        for (char curr = '0'; curr <= '9'; curr++) {
            ans.first += res.first + (curr - '0') * res.second;
            ans.second += res.second;
        }
    }

    return ans;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        ll k;
        cin >> k;

        int size = 1;
        ll p10size = 10;
        if (k > 9) {
            k -= 9;
            size++;
            p10size *= 10;
        }
        while (k >= size * (p10size-p10size/10)) {
            k -= size * (p10size-p10size/10);
            size++;
            p10size *= 10;
        }

        ll upper = k / size;
        k = k % size;

        string s;
        ll x = p10size/10 + upper - 1;
        while (x) {
            s.push_back('0' + x%10);
            x /= 10;
        }
        reverse(s.begin(), s.end());
        pair<ll,ll> res = solve(s, 0, 1);
        ll ans = res.first;

        x = p10size/10 + upper;
        while (!s.empty()) s.pop_back();
        while (x) {
            s.push_back('0' + x%10);
            x /= 10;
        }
        reverse(s.begin(), s.end());

        for (int i=0; i<k; i++) ans += s[i] - '0';

        cout << ans << '\n';
    }
}