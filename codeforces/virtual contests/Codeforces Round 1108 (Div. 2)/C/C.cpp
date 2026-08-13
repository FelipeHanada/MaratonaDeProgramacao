#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);
constexpr int md = int(1e9)+7;

int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}
int mult(int a, int b) { return ((ll)a * b) % md; }
constexpr int N = int(2e5)+5;


int main() {
    vector<int> pow2(N);
    pow2[0] = 1;
    for (int i=1; i<N; i++) pow2[i] = add(pow2[i-1], pow2[i-1]);
    auto even = [&](int i) -> int { return i ? pow2[i-1] : 1; };
    auto odd = [&](int i) -> int { return i ? pow2[i-1] : 0; };

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        int minus1 = 0;
        vector<pair<int, int>> b;
        {
            int i=0;
            for (; i<n && a[i] == -1; i++) minus1++;
            for (; i<n; i++) {
                if (b.empty() || b.back().first != a[i]) b.push_back({ a[i], 1 });
                else b.back().second++;
            }
        }

        vector<int> dp1(b.size()+1), dp2(b.size()+1);
        dp1[0] = even(minus1);
        dp2[0] = odd(minus1);
        for (int i=1; i<=b.size(); i++) {
            dp1[i] = mult(dp1[i-1], even(b[i-1].second));
            dp2[i] = mult(dp2[i-1], even(b[i-1].second));

            if (i>=2 && b[i-1].first == b[i-2].first + 1) {
                dp1[i] = add(dp1[i], mult(mult(dp2[i-2], odd(b[i-1].second)), odd(b[i-2].second)));
            }
        }

        cout << dp1.back() << '\n';
    }
}

/*

14
         -1 -1 -1 1 2 2 3 3 3 5 5 5 5 5
zero = 1 1  2  4  4  8
-1   = 0 1  2  4  4  8

*/
