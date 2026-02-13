#include <bits/stdc++.h>
using namespace std;


int v[1000];
int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v, v + n);

    int best = 0;
    for (int i=0; i<n; i++) {
        // acha a melhor bolsa onde o i-ésimo elemento é o menor
        int low = v[i], curr = 0;
        for (int j=i; j<n && low + k >= v[j]; j++) {
            curr++;
        }
        best = max(best, curr);
    }

    cout << best << '\n';
}
