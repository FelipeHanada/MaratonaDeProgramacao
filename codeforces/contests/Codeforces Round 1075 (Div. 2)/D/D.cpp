#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

/*
wi = 0 sse. i+1 está entre i e 0
wi = 1 sse. i+1 NÃO está entre i e 0

21 123456789
111000111000111000111

3 3
001

(.n.) 0 (.m.) i+1 (.k.)

podemos colocar o i em:
    wi = 1 -> (n+1)+(m+1)   posições
    wi = 0 -> (k+1)         posições

1|00| =2> |10| =2> 1
1111|1100| =4> 11111

    */

void solve() {
    int n, c;
    cin >> n >> c;
    string s;
    cin >> s;

    if (s[0] == '0' || s.back() == '0') {
        cout << "-1\n";
        return;
    }

    ll ans = 0;
    ll open = 2, close = 0;
    for (int i=s.size()-1; i>0; i--) {

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    int tt;
    cin >> tt;
    while (tt--) solve();    
    return 0;
}
