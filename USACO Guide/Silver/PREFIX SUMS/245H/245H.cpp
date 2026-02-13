#include <bits/stdc++.h>
using namespace std;

/*
p[i][j] = 1 se tem palindromo de tamanho i com começo em j

p[i+2][j] = 1 se p[i][j + (j+i+2)/2] && (s[j] == s[j+i+1])
*/

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    
    int n = s.size();
    vector<vector<ll>> p(n+1, vector(n+1, (ll)0));
    for (int i=1; i<=n; i++) p[0][i] = p[1][i] = 1; // toda palavra unitaria é palindromo
    
    for (int i=2; i<=n; i++) {
        for (int j=1; j+i-1<=n; j++) {
            p[i][j] = p[i-2][j+1] & (s[j-1] == s[j+i-2]);
        }
    }
    
    // accumulates
    for (int i=2; i<=n; i++) {
        for (int j=1; j+i-1<=n; j++) {
            p[i][j] += p[i-1][j] + p[i-1][j+1];
            if (i-2 >= 1) p[i][j] -= p[i-2][j+1];
        }
    }
    
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << p[r-l+1][l] << '\n';
    }
}
