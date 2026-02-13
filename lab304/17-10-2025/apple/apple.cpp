#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
int p[20];

ll sol(int i, ll a, ll b) {
    if (i == n) return abs(b - a);
    return min(sol(i+1, a+p[i], b), sol(i+1, a, b+p[i]));
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> p[i];
    }
    cout << sol(0, 0, 0) << '\n';
}