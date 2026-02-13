#include <bits/stdc++.h>
using namespace std;


/*
se uma bitstring A se transforma em B a partir de uma seq. S de operações como as descritas,
    então B se transforma em A por uma seq. S^r

ideia de demonstração:
    seja p uma operação que leva de A até B, a aplicação de p em B, leva até A,
        então se A p1 A1 p2 A2 p3 ... pn B, a aplicação reversa das operações
            leva B até A

toda bitstring de tamanho pelo menos 4 consegue chegar em 0^n
então A -> 0^n -> B funciona
e A -> 0^n utiliza no máximo n passos
*/

void solve2(vector<pair<int, int>> &ans, string &s) {
    while (s[0] != s[1]) {
        if (s[1] == s[2]) {
            // xyy -> xxx
            ans.push_back({1, 2});
            s[1] = s[2] = s[0];
        } else {
            if (s[2] == s[3]) {
                // xyxx -> xyyy -> xxxx
                ans.push_back({2, 3});
                ans.push_back({1, 3});
                s[1] = s[0];
            } else {
                // xyxy -> xxyx
                ans.push_back({1, 3});
                s[1] = s[0];
                s[2] = s[3];
                s[3] = s[0];
            }
        }
    }

    for (int i=0; i<s.size(); i++) {
        if (s[i] == s[0]) continue;
        ans.push_back({0, i-1});
        s[0] = s[i];
    }

    if (s[0] == '1') { // 1...1
        ans.push_back({0, s.size() - 1});
    }
}

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    vector<pair<int, int>> s_ans;
    vector<pair<int, int>> t_ans;
    // s -> 0^n
    // t -> 0^n

    solve2(s_ans, s);
    solve2(t_ans, t);
    
    cout << s_ans.size() + t_ans.size() << '\n';
    for (auto [l, r] : s_ans) {
        cout << l+1 << ' ' << r+1 << '\n';
    }

    for (auto it = t_ans.rbegin(); it != t_ans.rend(); it++) {
        cout << it->first+1 << ' ' << it->second+1 << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}