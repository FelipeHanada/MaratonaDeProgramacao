#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int main() {
    int n, k;
    cin >> n >> k;

    pair<int, int> x[n];
    for (int i=0; i<n; i++) {
        cin >> x[i].first;
        x[i].second = i + 1;
    }
    sort(x, x+n);

    for (int i=0; i<=n-4; i++) {
        for (int j=i+3; j<n; j++) {
            int a=i+1, b=j-1;

            int sum = x[i].f + x[j].f + x[a].f + x[b].f;
            while (a < b) {
                if (sum > k) {
                    sum -= x[b--].f;
                    sum += x[b].f;
                } else if (sum < k) {
                    sum -= x[a++].f;
                    sum += x[a].f;
                } else {
                    cout << x[i].s << ' ' << x[a].s << ' ' << x[b].s << ' ' << x[j].s << '\n';
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}
