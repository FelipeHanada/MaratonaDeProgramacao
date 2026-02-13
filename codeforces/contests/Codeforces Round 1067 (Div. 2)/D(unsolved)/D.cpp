#include <bits/stdc++.h>
using namespace std;

#define _1 first
#define _2 second
#define pii pair<int, int>
#define ll long long 


void precompute() {

}

/*
3
5
01011
10000

01011 -> 10111 -> 10000
^^^        ^^^

greedy: concertar os bits mais a esquerda e ir indo para a direita


sem perda de generalidade, assuma que o MSB de s e t é distinto
1(...)
0(...)
portanto, precisa haver um movimento que inclua o primeiro bit

10010
01001

10010 -> 10101 -> 01001
  ^^^    ^^^

10010 -> 01101 -> 01010
^^^^       ^^^    

01001


5
01011 -> 10111
^^^
01011 -> 01000
   ^^

10000

da pra flipar qualquer quantia de bits identicos

*/

bool is_palin(string &s, int l, int r) {
    while (l < r) {
        if (s[l++] != s[r--])
            return false;
    }

    return true;
}

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    // task: encontrar maior palindromo s[l,r] que quando flipado dá exatamente t[l,r]

    bool ok = true;
    vector<pair<int, int>> ans;
    int l = 0;
    while (l < n && ok) {
        if (s[l] == t[l]) {
            l++;
            continue;
        }

        // encontrar algum palindromo no prefixo s[l,...]
        int r = l+1;
        while (r < n && !is_palin(s, l, r)) r++;

        if (r == n) {
            ok = false;
        } else {
            ans.push_back({l, r});
        }

        l++;
    }

    if (!ok) {
        cout << "-1\n";
        return;
    }

    cout << ans.size() << '\n';
    for (auto [a, b] : ans) {
        cout << a << ' ' << b << '\n';
    }
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
