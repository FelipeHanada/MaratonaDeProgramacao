#include <bits/stdc++.h>
using namespace std;


int n;
constexpr int MAX_N = 100000;
int prefixH[MAX_N+1];
int prefixP[MAX_N+1];
int prefixS[MAX_N+1];


int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    cin >> n;
    prefixH[0] = prefixP[0] = prefixS[0] = 0;
    char c;
    for (int i=0; i<n; i++) {
        cin >> c;
        if (c == 'H') {
            prefixH[i+1] = prefixH[i];
            prefixP[i+1] = prefixP[i]+1;
            prefixS[i+1] = prefixS[i];
        } else if (c == 'P') {
            prefixH[i+1] = prefixH[i];
            prefixP[i+1] = prefixP[i];
            prefixS[i+1] = prefixS[i]+1;
        } else {
            prefixH[i+1] = prefixH[i]+1;
            prefixP[i+1] = prefixP[i];
            prefixS[i+1] = prefixS[i];
        }
    }

    int best = 0;
    for (int i=0; i<n; i++) {
        best = max(best, prefixH[i] + prefixP[n] - prefixP[i]);  // H -> P
        best = max(best, prefixH[i] + prefixS[n] - prefixS[i]);  // H -> S
        best = max(best, prefixP[i] + prefixH[n] - prefixH[i]);  // P -> H
        best = max(best, prefixP[i] + prefixS[n] - prefixS[i]);  // P -> S
        best = max(best, prefixS[i] + prefixH[n] - prefixH[i]);  // S -> H
        best = max(best, prefixS[i] + prefixP[n] - prefixP[i]);  // S -> P
    }

    cout << best << '\n';
}
