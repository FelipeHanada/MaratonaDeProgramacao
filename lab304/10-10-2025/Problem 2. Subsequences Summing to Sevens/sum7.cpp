#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 50000;
int prefix[MAX_N+1];

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n;
    cin >> n;

    int first[7], last[7];
    for (int i=0; i<7; i++) {
        first[i] = last[i] = -1;
    }

    prefix[0] = 0;
    for (int i=0; i<n; i++) {
        cin >> prefix[i+1];
        prefix[i+1] = (prefix[i+1] + prefix[i]) % 7;

        if (first[prefix[i+1]] == -1)
            first[prefix[i+1]] = i;
        last[prefix[i+1]] = i;
    }

    int best = 0;
    for (int i=0; i<7; i++) {
        if (first[i] == -1) continue;
        best = max(best, last[i] - first[i]);
    }

    cout << best << '\n';
}
