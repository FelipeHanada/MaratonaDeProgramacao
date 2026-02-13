#include <bits/stdc++.h>
using namespace std;



/*
b1 b2 b3 b4 b5 ... bi

a1 = 1
a1 a2 a3 a4 a5 ... ai
e todos os novas valores adicionados são max(a1 ... ai-1)+1
onde o maior valor que que ocorreu [..ai] foi k

podemos decidir ai pela transição bi-1 bi


1 1 1 1 1 1 1 2 2 2 2 2 3 3 3 1 = X + 1 + quantidade depois do primeiro 1 = X + 1 + (n - quantidade até o primeiro 1)
        curr = last + 1 + (i - quantidade até o primeiro 1)
        = quantidade até o primeiro 1 = last - curr + 1 + i



5
1 3 5 7 9
1 2 1 2 1

5
1 3 5 7 8
1 2 1 2 2

6
1 2 3 4 5 6

7
1 3 5 9 11 17 19
1 2 1 3 1 4 1

1 3 6 
1 2 3 4 5 6 7


7
1 3 5 9 11 17 22
1 2 1 3 1 4 2
^ ^ as somas dessa faixa permanecem iguais, porque já tem um 2
    ^       ^ depois do ultimo dois aumenta a quantidade


8
1 3 6 10 15 21 28 36
1 2 3 4 5 6 7 8

9
1 3 6 10 15 21 28 36 37
1 2 3 4 5 6 7 8 8

9
1 3 6 10 15 21 28 36 44
1 2 3 4 5 6 7 8 1

6
1 3 6 9 12 15
1 2 3 1 2 3

4
1 3 6 9
1 2 3 1


4
1 3 4 7
1 2 2 1


7
1 3 4 8 10 11 17
1 2 2 3 2 2 1

*/

#define ll long long

void solve() {
    int n;
    cin >> n;

    deque<ll> ans; ans.push_back(1);
    map<ll, ll> m; // quantidade até a primeira aparição, valor
    m[0] = 1;

    ll curr, last;
    cin >> last;
    ll c = 2;
    for (int i=1; i<n; i++) {
        cin >> curr;
        // if (curr - last == 1) {
            // ans.push_back(c - 1);
        // }
        if (curr - last == i + 1) {
            ans.push_back(c);
            c++;
        } else {
            ans.push_back(m[last-curr+i]);
        }
        m[i] = ans.back();
        last = curr;
    }

    for (ll i : ans) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}