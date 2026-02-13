#include <bits/stdc++.h>
using namespace std;

#define _1 first
#define _2 second
#define pii pair<int, int>
#define ll long long 


void precompute() {

}


/*
4 5 4 4 5 4 6

c[1] = 3
c[2] = 1
c[3] = 1
c[4] = 4
c[5] = 2
c[6] = 1


par pode ser
(impar) * 2 => divide metade pra cada lado: ans += 2 (sem desbalanço)
(par) * 2 = divide par+1 em um lado e par-1 em outro: ans += 2 (gera desbalanço de 2)

todo ímpar, pode ser dividido em floor(c[i]/2) para cada lado e 1 em algum lugar +1 (dá desbalanço de 1)
precisa haver uma quantidade par de impares, então dá pra fazer isso

posso usar (par*2) no maximo a quantidade de impares/2


4
1 2 1 2 1 2 1 2

c[1] = 4
c[2] = 4
c[3] = 4

3 / 2
*/

void solve() {
    int n;
    cin >> n;
    vector<int> c(2*n+1, 0);
    for (int i=0; i<2*n; i++) {
        int x;
        cin >> x;
        c[x]++;
    }
    
    int t[3] = {0, 0, 0};
    for (int i=1; i<=2*n; i++) {
        if (!c[i]) continue;
        if (c[i] % 2) t[0]++; // impares
        else if (c[i] % 4 == 0) t[2]++; // (par) * 2
        else t[1]++; // (impar) * 2
    }

    int ans = t[1] * 2 + t[0] + (t[2]/2*2)*2;
    if (t[2] % 2 && t[0]) ans += 2;

    cout << ans << '\n';
}

int main() {
    #ifdef ONLINE_JUDGE 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #endif

    int t;
    cin >> t;
    precompute();
    while (t--) {
        solve();
    }
}
