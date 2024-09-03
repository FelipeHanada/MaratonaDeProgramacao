#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<ll> prefix(N+1, 0);
    for (int i=0; i<N; i++) {
        int a;
        cin >> a;
        prefix[i + 1] = prefix[i] + a;
    }

    int max_len = -1;
    for (int len=N; len>0 && max_len == -1; len--) {
        for (int l=0; l<=N-len && max_len == -1; l++) {
            ll sum = prefix[l + len] - prefix[l];
            if (sum % 7 == 0)
                max_len = len;
        }
    }

    cout << max_len << endl;
}
