#include <bits/stdc++.h>
using namespace std;


#define ll long long

constexpr int MAX_N = 5000000;

ll p[MAX_N+1];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fill_n(p, MAX_N+1, 0);
    for (int i=2; i<=MAX_N; i++) {
        if (p[i]) continue;

        ll pow = i;
        while (pow <= MAX_N) {
            for (int j=pow; j<=MAX_N; j+=pow) {
                p[j]++;
            }
            pow *= i;
        }
    }

    for (int i=1; i<=MAX_N; i++) {
        p[i] += p[i-1];
    }

    int tt;
    cin >> tt;
    while (tt--) {
        int a, b;
        cin >> a >> b;
        cout << p[a] - p[b] << '\n';
    }
}
