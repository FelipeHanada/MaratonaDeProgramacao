#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


/*
if there is a triple
aaa, we cannot do anything about the rest

aa (...) bbb, the a(...)b must be alternating (and the rest)

ababab aa babababab (...)
=> se (...) termina em b, é só inverter a ordem
    se (...) termina em a, é só inverter os as e bs

=> então pode ter no máximo duas duplas de caracteres iguaos


... aa (...) aa ... 
    => troca a por b
    => reverte
... ab (...) ba ... 

... aa (...) bb ...
    => não troca a por b
    => reverte
... ab (...) ab ... 

*/

int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        const int n = int(s.size());
        int ans = 0;
        for (int i=1; i<n; i++) {
            ans += (s[i] == s[i-1]);
        }

        cout << (ans <= 2 ? "YES" : "NO") << '\n';
    }
}
